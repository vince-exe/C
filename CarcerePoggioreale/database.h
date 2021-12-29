#ifndef DATABASE_H
#define DATABASE_H

#include "carcerato.h"
 
typedef struct Database {
    struct Carcerato** listaCarcerati;  //questo (nel mio caso) è un array di puntatori che punta ad altri puntatori di tipo Carcerato*
    int index;
    int size;
    int indexSize;
    int indexPrint;
} Database;

void constructorDatabase(Database* database);
void addCarcerato(Database* database);
void printDatabase(Database* database);
void deleteCarcerato(Database* database);
void search(Database* database);
int getSearchMod();
int checkIndex(Database* database);

#endif