
/*library created for the manipulation of stacks in C

Program tested with: valgrind

What's valgrind?

Info[https://valgrind.org/]

Founder: Caliendo Vincenzo alias vince-exe

GitHub[https://github.com/vince-exe]
*/
#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    /*array for data (integers)*/
    int* stack;
    /*index to move into the array*/
    int index;
    /*variable to know the size of the stuck*/
    int size;
} Stack;

/*function that build the stuck with the size*/
struct Stack* buildStack(int size);

/*function to free the entire stuck*/
void freeStack(struct Stack** stack);

/*function that return True if the stack is full*/
int isFull(struct Stack* stack);

/*function the return the number of elements in the stack*/
int getcurrElements(struct Stack* stack);

/*function that add an element to the Stack*/
int push(struct Stack* stack, int value);

/*function that remove an element from the Stack*/
int pop(struct Stack* stack);

/*function that check if the value to push respect the conditions*/
int checkValue(int value);

/*function that return an element without removing it from the stack*/
int returnElement(struct Stack* stack);

/*function that return the size of the stack*/
int getSize(struct Stack* stack);

#endif