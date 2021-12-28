#ifndef CARCERATO_H
#define CARCERATO_H

#include "database.h"

//Creo il mio frATM
typedef struct Carcerato {
    char* nome;
    char* cognome;
    char* id;
    int eta;
} Carcerato;

Carcerato* buildCarcerato();

#endif