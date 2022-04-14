#include <stdio.h>

#include "list.h"

int main() {
    List lista = NULL;
    int i;
    
    append(&lista, 'c');
    append(&lista, 'p');
    append(&lista, 'l');
    append(&lista, 'u');
    append(&lista, 'p');

    reverseList(&lista);

    for(i = 0; i < countNodes(lista); i++)
        printf("%c\n", getItem(lista, i));


    freeList(&lista);

    return 0;
}