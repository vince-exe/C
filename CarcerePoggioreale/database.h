#ifndef DATABASE_H
#define DATABASE_H

#include "carcerato.h"

#define SIZE 30

typedef struct Database {
    struct Carcerato* listaCarcerati[SIZE];
    int index;
} Database;

void addCarcerato(Database* database);
void printDatabase(Database* database);
void deleteCarcerato(Database* database);
void search(Database* database);
int getSearchMod();
int checkIndex(Database* database);

#endif