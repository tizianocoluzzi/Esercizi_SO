#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "Veicolo.h"
#include "ParcoAuto.h"
ParcoAuto* Parco_constructor(const char* nome, int totali){
    ParcoAuto* p = malloc(sizeof(ParcoAuto));
    p->nome = malloc(sizeof(LEN));
    memcpy(p->nome, nome, strlen(nome)+1);
    p->auto_presenti = 0;
    p->posti_totali = totali;
    p->listaAuto = (Veicolo**) calloc(totali, sizeof(Veicolo*));
    return p;
}

void Parco_distruttore(ParcoAuto** p){
    Veicolo* a;
    for(int i = 0; i < (*p)->posti_totali; i++){
        a = ((*p)->listaAuto)[i];
        if(a != NULL)
            Veicolo_destructor(&a);
    }
    free((*p)->listaAuto);
    free((*p)->nome);
    free(*p);
    *p = NULL;
}

int Parco_aggiungiVeicolo(ParcoAuto* parco, Veicolo* veicolo){
    if(veicolo == NULL) return -1;
    if(parco == NULL) return -1;
    int i = 0;
    int tot = parco->posti_totali;
    if(tot - parco->auto_presenti == 0) return -1;
    parco->auto_presenti++;
    Veicolo** lista = parco->listaAuto;
    //chiaramente inefficiente
    while( i < tot && lista[i] != NULL) ++i;
    lista[i] = veicolo; 
    return 0;
}
int Parco_rimuoviVeicolo(ParcoAuto* parco, Veicolo* veicolo){return 0;}
void Parco_print(ParcoAuto* parco){
    if(parco == NULL) {printf("parco null\n"); return;}
    int tot = parco->posti_totali;
    Veicolo** v = parco->listaAuto;
    printf("parco di nome: %s, posti totali:%d, posti disponibili:%d\n", parco->nome, tot, tot-parco->auto_presenti);
    for(int i = 0;i < tot; i++){
        printf("[%d]", i);
        fflush(stdout);
        if(v[i] != NULL) Veicolo_print(parco->listaAuto[i]);
        else printf("vuoto");
        printf("\n");
    }
}
