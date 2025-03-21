#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
//ia include our custom uart (from previous exercise)
#include "my_uart.h"

//TODO fondamentale la divisione in funzioni e la chiamata della verifica dall'interrupt

//tabella delle transizioni
static const uint8_t transition[] = {
    0, 1, -1, 0, -1, 0, 0, +1, +1, 0, 0, -1, 0, -1, +1, 0 
};
volatile uint8_t interruzione = 0;
volatile uint8_t status = 0;
volatile uint8_t input = 0;
volatile uint8_t encoder[4] = {0,0,0,0};
//interruzioni sulla porta K
//pcint 16-23

void check_encoder(uint8_t num){
    //valore attuale dell'encoder
    uint8_t j = num*2; //perche vado di due in due
    //calcolo dell'indice: valore precedente shiftato di 2 in or con il valore attuale
    int idx =  (((status & ((1<<j)|(1<<(j+1))))>>j)<<2) | ((input & ((1<<j)|(1<<(j+1))))>>j); 
    //La transizione aggiorna il valore di encoder[i] 
    encoder[num] += transition[idx]; //per evitare probemi di overloading dovrei fare roba strana
                    
}

ISR(PCINT2_vect){
    interruzione = 1;
    input = PINK;
    for(int i = 0; i < 4; i++){
        //pre ogni encoder controllo
        check_encoder(i);
    }
    status = input;// dopo aver fatto i controlli aggiorno lo status
}
//TODO gestione delle transizioni
int main(){
    UART_init();
    DDRK &= ~ 0xFF; //metto in input 
    PORTK |= 0xFF; //pullup resistor
    PCICR |= (1<<PCIE2);//setto interrupt sul cambiamento
    PCMSK2 |= 0xFF; // prende interrupt da tutta la maschera
    sei();
    char buf[100];
    while(1){
        if(interruzione){
            interruzione = 0; //metto l'interruzione a 0 cosi è pronto per ricevere le altre
            //operazioni lente nel main loop
            //UART_putString((uint8_t*) "interruzione\n");
            for(int i = 0; i < 4; i++){
                sprintf(buf, "e:%d v:%d\n", i, encoder[i]);
                UART_putString((uint8_t*) buf);
            }
        }
    }
}
