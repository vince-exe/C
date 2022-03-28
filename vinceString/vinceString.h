#ifndef VINCESTRING_H
#define VINCESTRING_H

#include <stdio.h>

/*
Founder: Caliendo Vincenzo

Last Update: 28/03/2022 23:30
*/

/*function that return the lenght of a string*/
int strlen_(const char* string);

/*function that return 1 if the string are equals, else return 0*/
int strcmpy_(char* string1, char* string2);

/*function that copy the content of src in dest string return the number of characters that are been pasted*/
int strcpy_(char* dest, char* src);

/*function that return 1 if the given character is present un the string*/
int ischar_(char* string, char c);

/*function that check if a given character is present in the string, and return the pointer to it*/
char* strsrc_(char* src, char c);

/*function that return how many time there is the given character in the string*/
int cntchar_(char* string, char c);

/*function that return 1 if the given word is present in the string*/
int isString(char* dest, const char* src);

/*function created for take from stdin a string and paste it into the given vector without overflow the given buffer*/
int readString(char* string, int buffer);

/*function to concatenate a string into another string*/
void strct_(char* dest, char* src);

#endif