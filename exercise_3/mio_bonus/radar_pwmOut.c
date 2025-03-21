#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
// include our custom uart (from previous exercise)
#include "my_uart.h"
//TODO attaccare il tutto all'output delle casse
#define INMSK 0x01
#define OUTMSK 0x02
volatile uint8_t interrupt = 0;
volatile uint8_t input = 0;
volatile uint8_t now = 0;
volatile uint8_t diff = 0;

#define TCCRA_MASK (1<<WGM10)|(1<<COM1C0)|(1<<COM1C1)
#define TCCRB_MASK ((1<<WGM12)|(1<<CS10))   



ISR(TIMER5_COMPA_vect){
    //UART_putString("invio:");
    //invio il segnale
    //PORTK &= ~OUTMSK;
    //_delay_us(5);
    PORTK |= OUTMSK;
    _delay_us(10); 
    PORTK &= ~OUTMSK;
}

ISR(PCINT2_vect){
    //quando si crea l'interruzione salvo la differenza di tempo
    input = (PINK & INMSK);
    if(input==0x01){
        now = TCNT5; //quando sale prende il tempo
    }
    else if(input== 0x00){
        interrupt = 1; //aggiorno i valori nel main quando completa 
        diff = TCNT5 - now; //quando scende fa la differenza
    }
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
    //settaggio porte
    // TRIG su pin 2 ECHO su pin 1
    DDRK &= ~INMSK; //primo pin della K in input
    DDRK |= OUTMSK; //secondo pin in output
    PORTK |= INMSK; //pullup resistor
    PORTK &= ~OUTMSK; // setto a zero il valore iniziale del pin 2
    
    //settaggio interrupt
    PCICR |= (1<<PCIE2); //setto interrupt al cambiamento
    PCMSK2 |= INMSK; // primo bit della porta causano interrupt 
    //settaggio timer interrupt
    TCCR5A = 0;
    TCCR5B = (1<<CS42); //| (1<<CS40);
    OCR5A = 1;
    TIMSK5 = (1 << OCIE5A);

    sei();
    UART_init();
    pwm_init();
    while(1){
        char buf[100];
        if(interrupt){
            interrupt = 0;
            //if(diff > 225) OCR1CL = 255;
            //else if(diff > 125) OCR1CL = 200;
            //else if(diff > 75) OCR1CL = 100;
            //else if(diff > 25) OCR1CL = 50;
            //else OCR1CL = 1;
            OCR1CL = diff;
            sprintf(buf, "%u\n", diff); 
            UART_putString((uint8_t*)buf);
        }
        //_delay_ms(100);
    }
}
