# Parco auto
## Scopo del progetto
Riassumere le competenze acquisite nelle prime settimane di corso
## Idea del progetto
Grazie al fedele ChatGpt che sput fuori l'idea piu banale del mondo
## Descrizione 
Progetto per la gestione di un parco auto, costituito dalle seguenti classi
classe ParcoAuto:
* Attributi
    - ListaAuto
    - Nome
    - Posti totali
    - Auto presenti
* Metodi
    - costruttore
    - distruttore
    - aggiungiAuto
    - rimuoviAuto
    - stampati
classe Veicolo:
* Attributi
    - Nome
    - Targa
* Metodi
    - costruttore
    - distruttore
    - stampati
    - SuonoClason (astratto)
classe AutoMobile eredita Veicolo:
* Attributi

* Metodi
    - costruttore
    - distruttore
    - stampati
    - SuonoClacson
classe Camion eredita Veicolo:
* Attributi 
    - altezza
* Metodi
    - costruttore
    - distruttore
    - stampati
    - SuonoClacson
## Realizzazione
Strutture dati: considerando che non sono necessarie operazioni particolari e sopratutto non è richiesta efficienza(grazie l'ho fatto io), per evitare di inserire altre librerie(potrei copiare quelle che ho gia in realtà) utilizzo un semplice array, questo rende inserimento e rimozione molto meno efficienti O(n) ma tanto èun parco auto piccolo
>N.B. potrei cambiare

Il metodo distruttore è stato realizzato passando come parametro un puntatore al puntatore dell'oggetto, per poter sfruttare il double pointer method e poiter settare il puntatore a NULL
## Struttra del progetto
senza particolari fronzoli, le classi sono tutte nel folder principale
la cartella build è la cartella in cui è presente l'eseguibile main, costruito tramite cmake e make 


