#include<stdio.h>
#include "Veicolo.h"
#include "Automobile.h"
#include "Camion.h"
#include "ParcoAuto.h"
void test(){
    Veicolo* a = Veicolo_constructor("mario", "XTV");
    Veicolo_print(a);
    Veicolo_destructor(a);
    Automobile* b = Automobile_constructor("Luca", "BWS");
    Veicolo_print((Veicolo*)b);
    Veicolo_destructor((Veicolo*)b);
    Camion * c = Camion_constructor("Camion", "ranco", 115);
    Veicolo_print((Veicolo*)c);
    Veicolo_destructor((Veicolo*)c);
    printf("success\n");
    ParcoAuto* p = Parco_constructor("p1", 10);
    Parco_aggiungiVeicolo(p, c);
    Parco_print(p);
 }

int main(){
    //file della gestione principale
    test();
}
