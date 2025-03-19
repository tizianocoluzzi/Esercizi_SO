#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/io.h>
#include "../avr_common/uart.h" 

static const uint8_t transition[] = {
    0, 1, -1, 0, -1, 0, 0, +1, +1, 0, 0, -1, 0, -1, +1, 0 
};
//il vettore precedente indica il valore delle transizioni, 
//per capire cio che significava nonostante vedessi le slide del prof ci ho messo una vita
// l'indice rappresenta io valore decimale del numero binario: [precedente + successivo]
// precedente a i due bi piu significativi esempio 0001 vuol dire transizione da 0 a 1, nell'indice 1
int main(){
    printf_init();
    int mask = 3;
    DDRA &= ~mask;
    
    PORTA = mask;
    uint8_t curr = 0;
    uint8_t prev = 0;
    uint8_t cont = 0;
    while(1){ // se avessi avuto com maschera 255 dove sottrarre a 255
        curr = 3 - PINA; //mi prende comunque solo i valori che ho abilitato a leggere 
        int idx = (prev << 2) | curr; // calcola l'indice della transizione
        int val = transition[idx]; // calcola il valore
        cont += val; // aumenta o dimnuisce il contatore
        printf("%d\n",cont);
        prev = curr;
    }
}
