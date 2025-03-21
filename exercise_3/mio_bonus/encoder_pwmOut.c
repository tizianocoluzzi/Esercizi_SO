#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
// include our custom uart (from previous exercise)
#include "my_uart.h"

//costanti per la pwm
#define TCCRA_MASK (1<<WGM10)|(1<<COM1C0)|(1<<COM1C1)
#define TCCRB_MASK ((1<<WGM12)|(1<<CS10))   
//costanti per l'encoder
static const uint8_t transition[] = {
    0, 1, -1, 0, -1, 0, 0, +1, +1, 0, 0, -1, 0, -1, +1, 0 
};
volatile uint8_t interruzione = 0;
volatile uint8_t status = 0;
volatile uint8_t input = 0;
volatile uint8_t encoder = 0;
//interruzioni sulla porta K
//pcint 16-23



/**
    * MAIN GOAL creare una pwm su una porta per connettere una cassa
**/
void check_encoder(){
    //calcolo dell'indice: valore precedente shiftato di 2 in or con il valore attuale
    int idx =  (status & 0x03) << 2| (input & 0x03);
    //La transizione aggiorna il valore di encoder[i] 
    encoder += transition[idx]; //per evitare probemi di overloading dovrei fare roba strana
                    
}

ISR(PCINT2_vect){
    interruzione = 1;
    input = PINK;
    check_encoder();
    status = input;// dopo aver fatto i controlli aggiorno lo status
}

void pwm_init(){
    //inizializza la pwm
    TCCR1A = TCCRA_MASK;
    TCCR1B = TCCRB_MASK;
    OCR1AH = 0;
    OCR1BH = 0;
    OCR1CH = 0;
    OCR1CL = 1;
    DDRB |= (1<<7); //pin 13 come output
}

int main(){
    //setting up the encoder
    DDRK &= ~ 0x03; //metto in input 
    PORTK |= 0x03; //pullup resistor
    PCICR |= (1<<PCIE2);//setto interrupt sul cambiamento
    PCMSK2 |= 0x03; // prende interrupt da tutta la maschera
    sei();
    //setting up wpm
    pwm_init();
    UART_init(); //se non dobbiamo usare la porta seriale bisogna chiudere  
    char buf[100];
    while(1){
        if(interruzione){
            interruzione = 0;
            OCR1CL = encoder;
            //sprintf(buf, "v:%d\n",encoder);
            //UART_putString((uint8_t*) buf);
        }
        //_delay_ms(100);
        //intensity += 8;
        sprintf(buf, "%d\n", encoder);
        UART_putString((uint8_t*)buf);
    }
}
