/*
Main used to test the Library
*/
#include <stdio.h>

#include "vinceList.h"

int main() {
    struct List* lista = NULL;

    int i;
    for(i = 0; i < 100000; i++)
        appendInt(&lista, i);
    
    printList(lista);
    
    printf("\n\nNumber of elements in the list: %d", getElements(lista));

    freeList(&lista);
    return 0;

}