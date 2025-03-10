#include<stdio.h>
#include "Veicolo.h"
#include "Automobile.h"
#include "Camion.h"
#include "ParcoAuto.h"
//per il distruttore ho dovuto utilizzare il metodo del double pointer per porre a null il valore del puntatore a veicolo
void test(){
    Veicolo* a = Veicolo_constructor("mario", "XTV");
    Veicolo_print(a);
    Veicolo_destructor(&a);
    //a = NULL;
    Automobile* b = Automobile_constructor("Luca", "BWS");
    Veicolo_print((Veicolo*)b);
    Veicolo_destructor((Veicolo**)&b);
    //b = NULL;
    Camion * c = Camion_constructor("Camion", "ranco", 115);
    Veicolo_print((Veicolo*)c);
    //Veicolo_destructor((Veicolo**)&c);
    printf("success\n");
    printf("%p\n", c); 
    ParcoAuto* p = Parco_constructor("p1", 10);
    int ret = Parco_aggiungiVeicolo(p,(Veicolo*) c);
    if(ret) printf("problema con l'inserimento\n");
    Parco_print(p);
    Parco_distruttore(&p);
 }

int main(){
    //file della gestione principale
    test();
}
