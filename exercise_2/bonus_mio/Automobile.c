#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Veicolo.h"
#include "Automobile.h"
#include "common.h"

//funzioni private che vengono chiamate solo all'interno del file
void Automobile_destructor_function(Automobile* a);
void Automobile_print_function(Automobile* a);
void Automobile_clacson_function(Automobile* a);


Veicolo_ops automobile_ops; //tutte le variabili globali sono inizializzate
Automobile* Automobile_constructor(const char* nome, const char* targa){
    
    Automobile* a =(Automobile*) Veicolo_constructor(nome, targa);
    assert(a);
    if(automobile_ops.dtor == 0){
        //se veicolo_ops non è stata iniziaizzata la inizializzo
        automobile_ops.dtor = (Veicolo_dtorfn) Automobile_destructor_function;
        automobile_ops.print = (Veicolo_printfn) Automobile_print_function;
        automobile_ops.clacson = (Veicolo_clacsonfn) Automobile_clacson_function;
    }
    a->veicolo.veicolo_ops = &automobile_ops; //sovrascrivo automobile_ops POCO EFFICIENTE
    return a;
}
//è uguale a quello del veicolo, questa cosa non va molto bene ma al momento è cosi
void Automobile_destructor_function(Automobile* a){
    free(a->veicolo.nome);
    free(a->veicolo.targa);
    free(a);
}
void Automobile_print_function(Automobile* a){
    assert(a);
    assert(a->veicolo.targa && a->veicolo.nome);
    printf("chiamata print id auto\n");
    printf("Automobile di: %s targa: %s\n", a->veicolo.nome, a->veicolo.targa);
}

void Automobile_clacson_function(Automobile* a){
    printf("pe-pee\En");
}
