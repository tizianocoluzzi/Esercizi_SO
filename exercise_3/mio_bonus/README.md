# ESERCITAZIONE PERSONALE
## Obettivo
Imparare a maneggiare arduino mega, in particolare utilizzando timer e interrupt per gestire periferiche esterne
## Esercizi
### encoder_pwmOut.c
#### Descrizione
L'esercizio si basa sulla gestione di un encoder tramite interrupt, come nell'esercizio 08, 
l'intensità manipolata tramite l'encoder regola l'intensitàdi una pwm, 
che puo essere collegata ad un output, come un buzzer o un LED
#### Configurazione
- Clk portK pin 1 (A8)
- Dt portK pin 2 (A9)
- USCITA portB 7 (13)
![schema_encoder.jpg](https://github.com/tizianocoluzzi/Esercizi_SO/exercise_3/mio_bonus/schema_encoder.jpg "schema")
### radar_pwmOut.c
#### Descrizione
L'esercizio si basa sulla ricezione di un segnale da un sensore ad ultrasuoni, 
l'elaborazione del segnale avviene tramite un interrupt esterno e un timer,
il timer invia periodcamente al pin Trig del sensore un valore HIGH, questo invia un segnale audio 
e successivamente attiva il pin Echo in attesa, nel momento in cui lo riceve il segnale si abbassa
il timer segnala l'invio e l'ISR controlla il valore del pin Trig.
Questo gestisce in output l'intensità di una pwm, come nell'esercizio precedente
#### Configurazione
- Trig portK pin 1 (A8)
- Echo portK pin 2 (A9)
- USCITA portB 7 (13)
![schema_radar.jpg](https://github.com/tizianocoluzzi/Esercizi_SO/exercise_3/mio_bonus/schema_radar.jpg "schema")
