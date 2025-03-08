#pragma once
#include"Veicolo.h"
// non avendo previsto classi derivate, o quantomeno metodi con override non c'e ops
typedef struct ParcoAuto{
    char* nome;
    int auto_presenti;
    int posti_totali;
    Veicolo** listaAuto;
}ParcoAuto;

ParcoAuto* Parco_constructor(const char* nome, int totali);

void Parco_distruttore(ParcoAuto* parco);

int Parco_aggiungiVeicolo(ParcoAuto* parco, Veicolo* veicolo);
int Parco_rimuoviVeicolo(ParcoAuto* parco, Veicolo* veicolo);
void Parco_print(ParcoAuto* parco);
