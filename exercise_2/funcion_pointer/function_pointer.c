#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"function_pointer.h"
//nota importante, sarebbero da migliorare le print per capire che succede
Stato stato; //variabile globale che memorizza lo stato
//per far finire il ciclo ma in realta non esiste
int s4_in = 0;
//lista comandi
char* c1 = "0xAA\n";
char* c2 = "0x55\n";

int comparison(char* in, char* c){
    int len = strlen(in);
    if(len == strlen(c) && memcmp(in, c, len) ==0)
        return 1;
}

void s1(char* in){
    if(comparison(in, c1) == 1) {
        stato = s2;
        printf("ricevuto 0xAA\n");
    }
    else printf("non inizio di comunicazione\n");
}
void s2(char* in){
    if(comparison(in, c2)== 1) {
        stato = s3;
        printf("inizio dati\n");
    }
    else stato = s1;
}
void s3(char* in){
    stato = s4;
    s4_in = atoi(in);
    printf("pacchetto di dimensione %d\n", s4_in);
}
void s4(char* in){
    printf("ricevuto %s", in);
    --s4_in;
    if(s4_in <= 0) stato = s5;
    else printf("input rimanenti %d\n", s4_in);
}
void s5(char* in){
    printf("pacchetto ricevuto\n");
    if(comparison(in,c1) == 1) stato = s2;
    else stato = s1;
}
int main(){
    //funzione principale che esegue l'automa
    //regolato da uno stato che è variabile globale, rappresentato da un puntatore a funzione
    //di base, prendi input da tastiera, esegui stato(input), ricomincia ciclo
    stato = s1;
    char buffer[BUFFER_SIZE];
    while(1){
        fgets(buffer, BUFFER_SIZE-1, stdin);
        (stato)(buffer);
    }
}

