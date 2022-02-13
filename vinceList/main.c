/*
Main used to test the Library
*/
#include <stdio.h>

#include "vinceList.h"

int main() {
    struct List* lista = NULL;

    /*add elements*/
    int i;
    for(i = 0; i < 10; i++)
        appendInt(&lista, i);

    for(i = 0; i < 10; i++)
        appendDouble(&lista, 10.200000);
    
    for(i = 0; i < 10; i++)
        appendChar(&lista, 'o');
    
    for(i = 0; i < 10; i++)
        appendFloat(&lista, 10.11);
    
    for(i = 0; i < 10; i++)
        appendString(&lista, "lesss goooooooooo");

    /*print elements*/
    printList(lista);

    /*remove elements*/
    removeChar(&lista, 'o');
    removeDouble(&lista, 10.200000);
    removeFloat(&lista, 10.11);
    removeInt(&lista, 1);
    removeString(&lista, "lesss goooooooooo");
    
    /*print elements again*/
    printf("\n\n");
    printList(lista);

    /*print infos*/
    printf("\n\nNumber of integers: %d", getInteger(lista));
    printf("\nNumber of float: %d", getFloat(lista));
    printf("\nNumber of double: %d", getDouble(lista));
    printf("\nNumber of char: %d", getChar(lista));
    printf("\nNumber of string: %d", getString(lista));
    printf("\n\nTotal Elements: %d", getElements(lista));

    /*clear list*/
    freeList(&lista);

    return 0;
}