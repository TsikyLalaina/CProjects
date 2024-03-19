#ifndef H_F
#define H_F
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int countchar(char * string, char * character);
int findchar(char * string, char character);
char * join(char ** arr, size_t len, char * sep);
char ** split(char * string, size_t len, char * sep);
int * indexofstr(char * string, char * character);
size_t strlen(const char*);
void free(void*);
int toupper(int);
char* toUpperstr(char* str);

#endif // H_F
