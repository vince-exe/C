#ifndef VINCESTRING_H
#define VINCESTRING_H

#include <stdio.h>
#include <stdlib.h>

/*
Founder: Caliendo Vincenzo

Last Update: 29/03/2022 18:35
*/

/*return the lenght of a string*/
int strlen_(const char* string);

/*return 1 if strings are equals, else 0*/
int strcmpy_(char* string1, char* string2);

/*copy the content of src in dest string return the number of characters that are been pasted*/
int strcpy_(char* dest, char* src);

/*return 1 if the given character is present in the string*/
int ischar_(char* string, char c);

/*return a pointer to, which points to the memory address where the given character is located*/
char* strsrc_(char* src, char c);

/*return how many times the there is the given character in the string*/
int cntchar_(char* string, const char* c);

/*return 1 if the given src string is present in the dest string*/
int isString(char* dest, const char* src);

/*read a given number of characters from stdin and put it in a buffer*/
int readString(char* string, int buffer);


/*concatenate two strings (make sure that the string dest has enough space)

also return a pointer to the concatenated string
*/
char* strct_(char* dest, char* src);


/*concatenate the two given strings and return a pointer to the concatenated string

it's different from strct_() because here the pointer is dinamically allocated
*/
char* strct2_(char* dest, char* src);


/*set a string with the given character

also return a pointer to the setted string
*/
char* strnset_(char* string, const char* sm, int count);


/*set ALL the string to the given character

also return a pointer to the full setted string
*/
char* strset_(char* string, const char* sm);


/*start to set a string from (int start) and continue based on (int count)

also return a pointer to the setted string
*/
char* strset1_(char* string, const char* sm, int start, int count);


/*reverse a string

also return a pointer to the reversed string
*/
char* strrev_(char* string);

#endif