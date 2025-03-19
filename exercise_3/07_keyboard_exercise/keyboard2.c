#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include "../avr_common/uart.h" // this includes the printf and initializes it

//TODO aggiungere la memoria di stato per ogni tasto per capire se 
// il tasto era gia stato preuto
uint8_t status[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
 
int main(){
    printf_init();
    uint8_t mask = 240; //credo 0xF0
    


    DDRA |= mask; //output 
    PORTA = 0x0F; //input pullup ??
    printf("status:%d\n", status);
    while(1){
        for(int i = 0; i < 4; i++){
            PORTA = ~(1 << (4+i)); // tutti 1 tranne in i che mettiamo 0
            int val = ~(0x0F & PINA);
            //printf("val: %d, colonna %d\n", val,i);
            _delay_ms(100); // per stabilizzare il segnale
            //scansione delle colonne per vedere quale è stato premuto
            for (int j = 0; j < 4; j++){
                uint8_t v = (val & (1 << j)) != 0; // 1 se è premuto
                uint8_t idx = (4 * i) +j; //indice del vettore, pensavo di usare un solo byte ma ho fallito
                if(v !=status[idx]){
                    status[idx] = v;
                    printf("cambio stato di: %d con stato:%d e status è %d: \n", idx, v);
                }
            }  
        }
    }

}
