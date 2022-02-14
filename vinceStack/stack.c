#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "stack.h"

struct Stack* buildStack(int size) {
    /*create a new stuck*/
    Stack* stack = malloc(sizeof(struct Stack));

    /*allocate his vector with n elements*/
    stack->stack = malloc(sizeof(int) * size);
    /*set the index = 0*/
    stack->index = 0;
    /*set the size to the given size*/
    stack->size = size;

    /*return the pointer to stuck*/
    return stack;
}

void freeStack(struct Stack** stack) {
    /*free the array*/
    free((*stack)->stack);
    /*free the pointer*/
    free((*stack));

    /*assign to stuck a NULL value*/
    (*stack) = NULL;
}

int getElements(struct Stack* stack) {
    int i;
    
    /*if the value != CLEAR increment the nElements*/
    for(i = 0; i < stack->index; i++);

    return i;
}

int isFull(struct Stack* stack) {
    /*return 0 if the stack isn't full*/ 
    if(getElements(stack) <= stack->size) 
        return 0;
    
    /*else return 1 (is full)*/
    return 1;    
}

int checkValue(int value) {
    if(value > INT_MIN && value < INT_MAX)
        return 1;
    
    return 0;
}

int push(struct Stack* stack, int value) {
    /*check the conditions*/
    if((!isFull(stack)) && checkValue(value)) {
        stack->stack[stack->index] = value;
        stack->index += 1;
    }

    return 0;
}

int pop(struct Stack* stack) {
    /*if the stack isn't full*/
    if(stack->index >= 0) {
        /*save the value in a val variable*/
        int val = stack->stack[stack->index - 1];
        /*decrement the index*/
        stack->index -= 1;
        
        return val;
    }
    return -1;
}

int returnElement(struct Stack* stack) {
    /*return the value at the index without removing it*/ 
    return stack->stack[stack->index];
}