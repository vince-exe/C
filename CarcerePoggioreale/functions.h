#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>

#include "database.h"

void* xmalloc(size_t bytes); 
void freeAll(Database* database, int index);

#endif