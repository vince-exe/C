#include <stdio.h>

#include "stack.h"

int main() {
    Stack* stack = buildStack(20);

    int i;
    for(i = 0; i < 20; i++)
        push(stack, i);

    for(i = 0; i < 20; i++)
        printf("%d\n", pop(stack));
    
    
    if(!isFull(stack))
        printf("\nLo stack equivale a: non pieno");
    else
        printf("\nLo stack non equivale a pieno");
    
    printf("\nNumeri di elementi nello stack: %d", getElements(stack));

    printf("\nElemento ritornato: %d", returnElement(stack));
    freeStack(&stack);

    return 0;
}