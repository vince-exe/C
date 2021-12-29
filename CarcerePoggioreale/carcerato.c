#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "carcerato.h"
#include "database.h"
#include "functions.h"

#define LEN_NOME 15
#define LEN_COGNOME 10
#define LEN_ID 10

Carcerato* buildCarcerato(Database* database) {
    char nome[LEN_NOME + 1], cognome[LEN_COGNOME + 1], id[LEN_ID + 1];
    int eta;
    Carcerato* carcerato = (Carcerato*) malloc(sizeof(Carcerato));

    while(getchar() != '\n');
    printf("\nRammo o nome: ");
    gets(nome);
    carcerato->nome = (char*) malloc(sizeof(char) * (strlen(nome) + 1));

    printf("\nRamm o cognome: ");
    gets(cognome);
    carcerato->cognome = (char*) malloc(sizeof(char) * (strlen(cognome) + 1));

    printf("\nMe vuless ra pur l'id?: ");
    gets(id);
    carcerato->id = (char*) malloc(sizeof(char) * (strlen(id) + 1));
    //l'id l'avess calcola ma nun teng genij

    printf("\nMe ra l'eta e po bast: ");
    scanf("%d", &eta);

    strcpy(carcerato->nome, nome);
    strcpy(carcerato->cognome, cognome);
    strcpy(carcerato->id, id);
    carcerato->eta = eta;

    //i controlli sulla malloc ne facimm pk stamm a napl
    return carcerato;
}