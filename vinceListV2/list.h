#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "item.h"

struct List {
    item value;
    struct List* next;    
};

typedef struct List *List;

int append(struct List** head, item value);
int countNodes(struct List* head);
int removeNode(struct List** head, int key);

item getItem(struct List* head, item i);

void freeList(struct List** head);
void reverseList(struct List** head);

#endif