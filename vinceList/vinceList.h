#ifndef VINCELIST_H
#define VINCELIST_H

#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define CHAR 4

/*
Library created for the manipulation of the lists in C

Tested on linux Ubuntu with valgrind program

What's valgrind?

Info = [https://valgrind.org/]

Founder: Caliendo Vincenzo aka vince-exe

GitHub: [https://github.com/vince-exe]
*/

typedef struct List {
    float n_float;
    int n_int;
    double n_double;
    char c;
    /*variable to know of what type is the node
      1 = integer
      2 = float
      3 = double
      4 = char
    */
    short int type;
      
    /*pointers to others nodes of the list*/
    struct List* next;
} List;

/*function that append an integer to the list*/
int appendInt(struct List** head, int value);

/*function that append a float to the list*/
int appendFloat(struct List** head, float value);

/*function that append a double to the list*/
int appendDouble(struct List** head, double value);

/*function that append a char to the list*/
int appendChar(struct List** head, char c);

/*function to print the list*/
void printList(struct List* head);

/*function that return 1 if the data (integer) is in the list, else return 0*/
int isInteger(struct List* head, int key);

/*function that return 1 if the data (float) is in the list, else return 0*/
int isFloat(struct List* head, float key);

/*function that return 1 if the data (double) is in the list, else return 0*/
int isDouble(struct List* head, double key);

/*function that return 1 if the data (char) is in the list, else return 0*/
int isChar(struct List* head, char key);

/*function to delete a node by key in the list (int)*/
int removeInt(struct List** head, int key);

/*function to delete a node by key in the list (float)*/
int removeFloat(struct List** head, float key);

/*function to delete a node by key in the list (double)*/
int removeDouble(struct List** head, double key);

/*function to delete a node by key in the list (char)*/
int removeChar(struct List** head, char key);

/*function that free all nodes of the list*/
void freeList(struct List** head);

/*function that return the num of elements in the list*/
int getElements(struct List* head);

#endif