#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "database.h"
#include "carcerato.h"
#include "functions.h"

#define SEARCH_NOME 1
#define SEARCH_COGNOME 2
#define SEARCH_ID 3
#define SEARCH_ETA 4

#define LENGHT 15

void addCarcerato(Database* database) {
    database->listaCarcerati[database->index] = buildCarcerato();
    database->index++;
}

void printDatabase(Database* database) {
    printf("\n\nDatabase Carcerati Poggioreale\n\n");
    int i;
    for(i = 0; i < database->index; i++) {
        printf("\nNome: %s", database->listaCarcerati[i]->nome);
        printf("\nCognome: %s", database->listaCarcerati[i]->cognome);
        printf("\nId: %s", database->listaCarcerati[i]->id);
        printf("\nEta: %d", database->listaCarcerati[i]->eta);
        printf("\nIndex Carcerato: %d", i);
        printf("\n");
    }
    printf("\n");
}

void printDatabaseIndex(Database* database, int index) {
    printf("\nNome: %s", database->listaCarcerati[index]->nome);
    printf("\nCognome: %s", database->listaCarcerati[index]->cognome);
    printf("\nId: %s", database->listaCarcerati[index]->id);
    printf("\nEta: %d", database->listaCarcerati[index]->eta);
    printf("\nIndex Carcerato: %d", index);
    printf("\n");

}

int checkIndex(Database* database) {
    if(!(database->index))
        return 0;

    return 1; 
}

int getIndex(Database* database) {
    int tempIndex;
    do {
        printf("\nInserire l'index carcerato: ");
        scanf("%d", &tempIndex);
    } while (tempIndex < 0 || tempIndex >= database->index);

    return tempIndex;
}

void deleteCarcerato(Database* database) {
    if(!(checkIndex(database))) {
        printf("\nIl database e' vuoto.\n");
        return;
    }

    int tempIndex = getIndex(database);
    freeAll(database, tempIndex);

    for(; tempIndex < database->index - 1; tempIndex++) 
        database->listaCarcerati[tempIndex] = database->listaCarcerati[tempIndex + 1];
    
    database->index--;
    printf("%d", database->index);
}

void search(Database* database) {
    if(!(checkIndex(database))) {
        printf("\nImpossibile avviare la ricerca, il databse e' vuoto :-(\n");
        return;
    }

    int eta, i, mod = getSearchMod();
    char string[LENGHT + 1];

    while(getchar() != '\n');
    switch (mod) {
    
    case SEARCH_NOME:
        printf("\nInserire nome: ");
        gets(string);

        for(i = 0; i < database->index; i++)
            if(!(strcmp(database->listaCarcerati[i]->nome, string)))
                printDatabaseIndex(database, i);
        break;
    
    case SEARCH_COGNOME:
        printf("\nInserire cognome: ");
        gets(string);

        for(i = 0; i < database->index; i++)
            if(!(strcmp(database->listaCarcerati[i]->cognome, string)))
                printDatabaseIndex(database, i);
        break;

    case SEARCH_ID:
        printf("\nInserire id: ");
        gets(string);

        for(i = 0; i < database->index; i++)
            if(!(strcmp(database->listaCarcerati[i]->id, string)))
                printDatabaseIndex(database, i);
        break;

    case SEARCH_ETA:
        printf("\nInserire eta: ");
        scanf("%d", &eta);

        for(i = 0; i < database->index; i++)
            if(database->listaCarcerati[i]->eta == eta)
                printDatabaseIndex(database, i);
        break;
    
    default:
        printf("\nError :-(\n");
        break;
    }
}

int getSearchMod() {
    int mod;

    printf("\n-.-.-Ricerca Carcerato.-.-.-\n");
    do {
        printf("\n%d)Nome\n%d)Cognome\n%d)Id\n%d)Eta\n\nInserire modalita ricerca: ", SEARCH_NOME, SEARCH_COGNOME, SEARCH_ID, SEARCH_ETA);
        scanf("%d", &mod);
    } while (mod < 0 || mod > 4);
    
    return mod;
}