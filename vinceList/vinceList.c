#include <stdio.h>
#include <stdlib.h>

#include "vinceList.h"

int appendInt(struct List** head, int value) {
    /*create a new node*/
    struct List* new_node = malloc(sizeof(struct List));

    /*check if the malloc failed*/
    if(!new_node)
        return 0;

    /*variable used to know the type of the node*/
    new_node->type = INT;
        
    /*assign to the new node the value*/
    new_node->n_int = value;

    /*connect the new node to the head*/
    new_node->next = (*head);
    
    /*change the position (value) of the head*/
    (*head) = new_node;

    return 1;
}

int appendFloat(struct List** head, float value) {
    /*create a new node*/
    struct List* new_node = malloc(sizeof(struct List));

    /*check if the malloc failed*/
    if(!new_node)
        return 0;

    /*variable used to know the type of the node*/
    new_node->type = FLOAT;
        
    /*assign to the new node the value*/
    new_node->n_float = value;

    /*connect the new node to the head*/
    new_node->next = (*head);
    
    /*change the position (value) of the head*/
    (*head) = new_node;

    return 1;
}

int appendDouble(struct List** head, double value) {
    /*create a new node*/
    struct List* new_node = malloc(sizeof(struct List));

    /*check if the malloc failed*/
    if(!new_node)
        return 0;

    /*variable used to know the type of the node*/
    new_node->type = DOUBLE;
            
    /*assign to the new node the value*/
    new_node->n_double = value;

    /*connect the new node to the head*/
    new_node->next = (*head);
    
    /*change the position (value) of the head*/
    (*head) = new_node;

    return 1;   
}

int appendChar(struct List** head, char c) {
    /*create a new node*/
    struct List* new_node = malloc(sizeof(struct List));

    /*check if the malloc falied*/
    if(!new_node)
        return 0;
    
    /*variable used to know the type of the node*/
    new_node->type = CHAR;

    /*assign to the new node the value*/
    new_node->c = c;

    /*connect the new node to the head*/
    new_node->next = (*head);

    /*change the position (value) of the head*/
    (*head) = new_node;

    return 1;
}

void printList(struct List* head) {
    /*while head != NULL*/
    while(head) {
        
        switch (head->type) {
        /*if the value to print is an integer*/
        case INT:
            printf("%d\n", head->n_int);
            break;

        /*if the value to print is a float*/
        case FLOAT:
            printf("%f\n", head->n_float);
            break;

        /*if the value to print is a double*/
        case DOUBLE:
            printf("%lf\n", head->n_double);
            break;

        /*if the value to print is a char*/
        case CHAR:
            printf("%c\n", head->c);
            break;
            
        default:
            break;
        }
        /*move to the next node*/
        head = head->next;                                                                                                                                             
    }
}

int isInteger(struct List* head, int key) {
    /*while head != NULL*/
    while(head) {
        /*check if the data exist*/
        if(head->n_int == key)
            return 1;
        head = head->next;
    }
    return 0;
}

int isFloat(struct List* head, float key) {
    /*while head != NULL*/
    while(head) {
        /*check if the data exist*/
        if(head->n_float == key)
            return 1;
        head = head->next;
    }
    return 0;
}

int isDouble(struct List* head, double key) {
    /*while head != NULL*/
    while(head) {
        /*check if the data exist*/
        if(head->n_double == key)
            return 1;
        head = head->next;
    }
    return 0;
}

int isChar(struct List* head, char key) {
    /*while head != NULL*/
    while(head) {
        /*check if the data exist*/
        if(head->c == key)
            return 1;
        head = head->next;
    }
    return 0;
}

int removeInt(struct List** head, int key) {
    /*save the value of the head in a temp pointer*/
    struct List* temp = (*head);
    /*pointer used to point to the previus nodes*/
    struct List* prev = NULL;

    /*if the value to delete is the head*/
    if(temp->n_int == key) {
        /*move the head*/
        (*head) = temp->next;
        /*free the value*/
        free(temp);

        return 1;
    } 

    /*while temp != NULL and temp->int != key*/
    while(temp && temp->n_int != key) {
        /*assign the value of temp to prev*/
        prev = temp;
        /*move temp to the next node*/
        temp = temp->next;
    }

    /*if the key doesn't exist*/
    if(!temp)
    return 0;

    /*else connect the prev node to the next of temp*/
    prev->next = temp->next;
    /*free temp*/
    free(temp);

    return 1;
}

int removeFloat(struct List** head, float key) {
    /*save the value of the head in a temp pointer*/
    struct List* temp = (*head);
    /*pointer used to point to the previus nodes*/
    struct List* prev = NULL;

    /*if the value to delete is the head*/
    if(temp->n_float == key) {
        /*move the head*/
        (*head) = temp->next;
        /*free the value*/
        free(temp);

        return 1;
    } 

    /*while temp != NULL and temp->float != key*/
    while(temp && temp->n_float != key) {
        /*assign the value of temp to prev*/
        prev = temp;
        /*move temp to the next node*/
        temp = temp->next;
    }

    /*if the key doesn't exist*/
    if(!temp)
    return 0;

    /*else connect the prev node to the next of temp*/
    prev->next = temp->next;
    /*free temp*/
    free(temp);

    return 1;
}

int removeDouble(struct List** head, double key) {
    /*save the value of the head in a temp pointer*/
    struct List* temp = (*head);
    /*pointer used to point to the previus nodes*/
    struct List* prev = NULL;

    /*if the value to delete is the head*/
    if(temp->n_double == key) {
        /*move the head*/
        (*head) = temp->next;
        /*free the value*/
        free(temp);

        return 1;
    } 

    /*while temp != NULL and temp->double != key*/
    while(temp && temp->n_double != key) {
        /*assign the value of temp to prev*/
        prev = temp;
        /*move temp to the next node*/
        temp = temp->next;
    }

    /*if the key doesn't exist*/
    if(!temp)
    return 0;

    /*else connect the prev node to the next of temp*/
    prev->next = temp->next;
    /*free temp*/
    free(temp);

    return 1;
}

int removeChar(struct List** head, char key) {
    /*save the value of the head in a temp pointer*/
    struct List* temp = (*head);
    /*pointer used to point to the previus nodes*/
    struct List* prev = NULL;

    /*if the value to delete is the head*/
    if(temp->c == key) {
        /*move the head*/
        (*head) = temp->next;
        /*free the value*/
        free(temp);

        return 1;
    } 

    /*while temp != NULL and temp->char != key*/
    while(temp && temp->c != key) {
        /*assign the value of temp to prev*/
        prev = temp;
        /*move temp to the next node*/
        temp = temp->next;
    }

    /*if the key doesn't exist*/
    if(!temp)
    return 0;

    /*else connect the prev node to the next of temp*/
    prev->next = temp->next;
    /*free temp*/
    free(temp);

    return 1;
}

void freeList(struct List** head) {
    /*create a temp pointer to store the value of head and free the list*/
    struct List* temp = NULL;

    /*while head != NULL*/
    while((*head)) {
        /*assign to temp the value of head*/
        temp = (*head);
        /*move to the next node*/
        (*head) = (*head)->next;
        /*free the node*/
        free(temp);
    }
}

int getElements(struct List* head) {
    /*variable that will used for counter of elements in the list*/
    int numElements = 0;

    /*while head != NULL*/
    while(head) {
        /*increment the num of elements*/
        numElements++;
        /*move to the next node*/
        head = head->next;
    }
    return numElements;    
}
