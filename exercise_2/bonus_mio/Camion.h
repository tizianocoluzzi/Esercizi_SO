#pragma once
#include "Veicolo.h"

//la stessa struct di veicolo praticamente
typedef struct Camion{
    Veicolo veicolo;
    int altezza;
}Camion;

//ridefinisco solo il clacson e il costruttore
void Camion_clacson(Veicolo* a);
Camion* Camion_constructor(const char* nome, const char* targa, int altezza);


