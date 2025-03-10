#pragma once
//N.B. non ho inserito le funzioni effettive che vengono eseguite
//in modo da proteggere l'accesso a quelle funzioni

//come dice il prof, forward declaraion to shut the compiler
struct Veicolo;
//definizione dei tipi delle funzioni 
typedef void (*Veicolo_dtorfn)(struct Veicolo**);
typedef void (*Veicolo_printfn)(struct Veicolo*);
typedef void (*Veicolo_clacsonfn)(struct Veicolo*);

//VMT per la classe Veicolo
typedef struct{
    Veicolo_dtorfn dtor;
    Veicolo_printfn print;
    Veicolo_clacsonfn clacson;
} Veicolo_ops; 
//classe Veicolo
typedef struct{
    char* nome;
    char* targa;
    Veicolo_ops* veicolo_ops;
} Veicolo;

//metodi della classe Veicolo
void Veicolo_destructor(Veicolo** a);
void Veicolo_print(Veicolo* a);
void Veicolo_clacson(Veicolo* a);
Veicolo* Veicolo_constructor(const char* nome, const char* targa);

