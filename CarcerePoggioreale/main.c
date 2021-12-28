/*
PROVVEDITORATO AMMINISTRAZIONE PENITENZIARIA DI NAPOLI

Indirizzo: Via Nuova Poggioreale, 168, 80143 Napoli NA

Sempre Fozza Napoli <3 <3 <3
*/
#include <stdio.h>

#include "database.h"
#include "carcerato.h"

#define AGGIUNGI 1
#define ELIMINA 2
#define STAMPA 3
#define CERCA 4
#define ESCI 5

int main() {
    int opzione, run = 1;
    Database* database;
    database->index = 0;
   
    do {
        printf("\n%d)Aggiungi Carcerato\n%d)Elimina Carcerato\n%d)Stampa Database\n%d)Cerca Carcerato\n%d)Esci\n\nInserire opzione (%d / %d): ", AGGIUNGI, ELIMINA, STAMPA, CERCA, ESCI, AGGIUNGI, ESCI);
        scanf("%d", &opzione);

        switch(opzione) {

        case AGGIUNGI:
            addCarcerato(database);
            break;
        
        case ELIMINA:
            deleteCarcerato(database);
            break;

        case STAMPA:
            printDatabase(database);
            break;

        case CERCA:
            search(database);
            break;

        case ESCI:
            run = 0;
            break;

        default:
            printf("\nUaglio me sta piglann pe cul?!?\n");
            break;
        }
    } while (run);

    printf("\nca maronn v'accumpagn");
    return 0;
}