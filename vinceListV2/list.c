#include "list.h"
#include "item.h"

int append(struct List** head, item value) {
    struct List* newNode = malloc(sizeof(item));

    if(!newNode)
        return 0;

    newNode->value = value;

    newNode->next = (*head);
    (*head) = newNode;

    return 1;
}

item getItem(struct List* head, int i) {
    int j;
    struct List* tmp = head;

    for(j = 0; j < i && tmp != NULL; j++) {
        tmp = tmp->next;
    }

    return getValue(tmp->value);
}

int countNodes(struct List* head) {
    struct List* tmp = head;
    int i = 0;

    while(tmp != NULL) {
        tmp = tmp->next;
        i++;
    }

    return i;
}

int removeNode(struct List** head, item key) {
    struct List* tmp = (*head);

    /*check if he wants to remove the head*/
    if(tmp->value == key) {
        (*head) = tmp->next;
        free(tmp);

        return 1;
    }

    struct List* prev;

    while(tmp != NULL && tmp->value != key) {
        prev = tmp;
        tmp = tmp->next;
    } 

    if(tmp != NULL) {
        prev->next = tmp->next;
        free(tmp);

        return 1;
    }

    return 0;
}

void freeList(struct List** head) {
    struct List* tmp = NULL;

    while((*head) != NULL) {
        tmp = (*head);
        (*head) = (*head)->next;
        free(tmp);
    }
}

void reverseList(struct List** head) {
    struct List* prev = NULL;
    struct List* next = NULL;

    while((*head) != NULL) {
        /*we move the next node*/
        next = (*head)->next;
        /*connect the head to the previous node*/
        (*head)->next = prev;
        /*update the position of the prev*/
        prev = (*head);
        /*move head to the next node*/
        (*head) = next;
    }
    (*head) = prev;
}