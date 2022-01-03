#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARGS 2

#define INSUFFICIENT_ARGUMENTS -5
#define FILE_ERROR -4

/*
Program that copy the content of a file in an other file

The first argument is the path + name of the destination file
The second argument is the path + source of the destination file
*/

int main(int argc, char *argv[]) {
    //check if the number of arguments are correct (-1 it's because the .out file is considered an argument and i have to exclude it)
    if(argc - 1 < ARGS) {
        printf("\nInsufficient arguments :-(");
        exit(INSUFFICIENT_ARGUMENTS);
    }
    FILE *destination, *source;
    //open the file in write mode
    destination = fopen(argv[1], "w");

    //check if the destination pointer is equal to void.
    if(!(destination)) {
        printf("\nCan't create the file :-(");
        exit(FILE_ERROR);
    }
    source = fopen(argv[2], "r");

    if(!(source)) {
        printf("\nCan't open the source file :-(");
        remove(argv[1]);    //remove the destination file because the programm exit with an error
        exit(FILE_ERROR);
        
    }
    
    char c;
    while((c = getc(source)) != EOF)
        putc(c, destination);
    
    fclose(source);
    fclose(destination);
}