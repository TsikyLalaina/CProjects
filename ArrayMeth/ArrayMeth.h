#ifndef H_F
#define H_F
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int countint(int* arr, size_t nbrel, int value);
int indexofint(int* arr, size_t nbrel, int value);
char*** appendchar2(char*** arr, size_t nbrel, char** element, size_t nbrl2);
int* removeint(int* arr, size_t nbrel, int element);
int indexofchar(char** arr, size_t nbrel, char* element);
void removechar(char** arr, size_t nbrel, char* element);
int* removeintwithindex(int* arr, size_t nbrel, int index);
void removecharwithindex(char** arr, size_t nbrel, int index);

#endif
