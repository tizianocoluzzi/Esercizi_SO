#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Veicolo.h"
#include "Camion.h"
#include "common.h"

//funzioni private che vengono chiamate solo all'interno del file
void Camion_destructor_function(Camion* a);
void Camion_print_function(Camion* a);
void Camion_clacson_function(Camion* a);


Veicolo_ops camion_ops; //tutte le variabili globali sono inizializzate
Camion* Camion_constructor(const char* nome, const char* targa, int altezza){
    //a differenza dell'auto devo fare a mano perche ha dimensione maggiore
    Camion* a = malloc(sizeof(Camion));
    a->veicolo.targa = malloc(LEN);
    a->veicolo.nome = malloc(LEN);
    memcpy(a->veicolo.nome,nome, strlen(nome)+1);
    memcpy(a->veicolo.targa, targa, strlen(targa)+1);
    a->altezza = altezza;
    assert(a);
    if(camion_ops.dtor == 0){
        //se veicolo_ops non è stata iniziaizzata la inizializzo
        camion_ops.dtor = (Veicolo_dtorfn) Camion_destructor_function;
        camion_ops.print = (Veicolo_printfn) Camion_print_function;
        camion_ops.clacson = (Veicolo_clacsonfn) Camion_clacson_function;
    }
    a->veicolo.veicolo_ops = &camion_ops; //sovrascrivo camion_ops POCO EFFICIENTE
    return a;
}
//è uguale a quello del veicolo, questa cosa non va molto bene ma al momento è cosi
void Camion_destructor_function(Camion* a){
    free(a->veicolo.nome);
    free(a->veicolo.targa);
    free(a);
}
void Camion_print_function(Camion* a){
    assert(a);
    assert(a->veicolo.targa && a->veicolo.nome);
    printf("Camion di: %s targa: %s, altezza: %d", a->veicolo.nome, a->veicolo.targa, a->altezza);
}

void Camion_clacson_function(Camion* a){
    printf("pe-pee\En");
}
