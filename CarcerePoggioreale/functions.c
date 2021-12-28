#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAIL_ALLOCATION -5
#define STRING_LENGHT 15

void* xmalloc(size_t bytes) {
    void* p;
    p = malloc(bytes);

    if(p == NULL) {
        printf("\nFATAL ERROR :-(");
        exit(FAIL_ALLOCATION);
    }

    return p;
}

void freeAll(Database* database, int index) {
    free(database->listaCarcerati[index]->nome);
    free(database->listaCarcerati[index]->cognome);
    free(database->listaCarcerati[index]->id);
    free(database->listaCarcerati[index]);
}