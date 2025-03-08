#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Veicolo.h"
#include "common.h"


void Veicolo_destructor_function(Veicolo* a);
void Veicolo_print_function(Veicolo* a);
void Veicolo_clacson_function(Veicolo* a);


Veicolo_ops veicolo_ops; //tutte le variabili globali sono inizializzate
Veicolo* Veicolo_constructor(const char* nome, const char* targa){
    char* n = malloc(LEN);
    char* t = malloc(LEN);
    memcpy(n, nome, strlen(nome)+1);
    memcpy(t, targa, strlen(targa)+1);
    Veicolo* a = malloc(sizeof(Veicolo));
    a->nome = n;
    a->targa = t;
    if(veicolo_ops.dtor == 0){
        //se veicolo_ops non è stata iniziaizzata la inizializzo
        veicolo_ops.dtor = (Veicolo_dtorfn) Veicolo_destructor_function;
        veicolo_ops.print = (Veicolo_printfn) Veicolo_print_function;
        veicolo_ops.clacson = (Veicolo_clacsonfn) Veicolo_clacson_function;
    }
    a->veicolo_ops = &veicolo_ops;
    return a;
}
void Veicolo_destructor_function(Veicolo* a){
    free(a->nome);
    free(a->targa);
    free(a);
}
void Veicolo_print_function(Veicolo* a){
    printf("Veicolo di: %s targa: %s\n", a->nome, a->targa);
}
void Veicolo_clacson_function(Veicolo* a){
    printf("NON DISPONIBILE PER LE AUTO GENERICHE\n");
}
//metodi generici
void Veicolo_destructor(Veicolo* a){
    assert(a);
    assert(a->veicolo_ops && a->veicolo_ops->dtor);
    (*a->veicolo_ops->dtor)(a);
}

void Veicolo_print(Veicolo* a){
    assert(a);
    assert(a->veicolo_ops && a->veicolo_ops->print);
    (*a->veicolo_ops->print)(a); 
}
void Veicolo_clacson(Veicolo* a){
    assert(a);
    assert(a->veicolo_ops && a->veicolo_ops->clacson);
    (*a->veicolo_ops->clacson)(a);
}

