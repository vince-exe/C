#include <stdio.h>

#include "stack.h"

int main() {
    /*Build the stack*/
    Stack* stack = buildStack(20);

    /*get the size*/
    printf("La size dello stack equivale a: %d\n\n", getSize(stack));

    /*push elements*/
    int i;
    for(i = 0; i < 20; i++)
        push(stack, i);
    
    /*pop elements*/
    for(i = 0; i < 20; i++)
        printf("%d\n", pop(stack));
    
    /*check if the stack is full*/
    if(!isFull(stack))
        printf("\nLo stack equivale a: non pieno\n");
    else
        printf("\nLo stack non equivale a pieno\n");
    
    /*get the number of elements in the stack*/
    printf("\nNumeri di elementi nello stack: %d\n", getcurrElements(stack));

    /*return an element*/
    printf("\nElemento ritornato: %d\n", returnElement(stack));
    /*free the stack*/
    freeStack(&stack);

    return 0;
}