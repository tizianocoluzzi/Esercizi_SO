#pragma once
#include "Veicolo.h"

//la stessa struct di veicolo praticamente
typedef struct Automobile{
    Veicolo veicolo;
}Automobile;

//ridefinisco solo il clacson e il costruttore
void Veicolo_clacson(Veicolo* a);
Automobile* Automobile_constructor(const char* nome, const char* targa);



