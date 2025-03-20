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
static uint8_t encoder[4] = {0,0,0,0};
//interruzioni sulla porta K
//pcint 16-23
ISR(PCINT2_vect){
    interruzione = 1;
}
//TODO gestione delle transizioni
int main(){
    UART_init();
    DDRK &= ~ 0xFF; //metto in input 
    PORTK |= 0xFF; //pullup resistor
    PCICR |= (1<<PCIE2);//setto interrupt sul cambiamento
    PCMSK2 |= 0xFF; // prende interrupt da tutta la maschera
    sei();
    while(1){
        if(interruzione){
            interruzione = 0;
            int input = PINK;
            if (input != status){
                char buffer[1024];
                //per ogni encoder
                for(int i = 0; i < 4; i++){
                    //valore attuale dell'encoder
                    uint8_t j = i*2; //perche vado di due in due
                    int val = (input & ((1<<j)|(1<<(j+1))))>>j; 
                    int prev_val =  (status & ((1<<j)|(1<<(j+1))))>>j;
                    //status = input; ERRATO perche perdo eventuali cambi contemporanei
                    //La transizione aggiorna il valore di encoder[i] 
                    encoder[i] += transition[(prev_val<<2) | val]; //per evitare probemi di overloading dovrei fare roba strana
                    //stampa
                    sprintf(buffer, "encoder %d valore :%d\n", i, encoder[i]);
                    UART_putString(buffer);

                }            
            }
        }
        _delay_ms(100);
    }
}
