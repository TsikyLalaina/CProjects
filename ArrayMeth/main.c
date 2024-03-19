#include "ArrayMeth.h"

int countint(int* arr, size_t nbrel, int value){
    int j = 0;
    for(int i = 0; i < nbrel; i++){
        if(arr[i] == value){
            j += 1;
        }
    }
    return j;
}

int indexofint(int* arr, size_t nbrel, int value){
    int i = 0;
    bool exist = false;
    while(i < nbrel){
        if(arr[i] == value){
            exist = true;
            break;
        }
        i++;
    }
    if(exist){
        return i;
    }
    return -1;
}

int* removeint(int* arr, size_t nbrel, int element){
    int index = indexofint(arr, nbrel, element);
    for(int i = index; i < nbrel; i++){
        if(i != nbrel - 1){
            arr[i] = arr[i + 1];
        }
    }
    return realloc(arr, (nbrel - 1) * sizeof(int));
}

int indexofchar(char** arr, size_t nbrel, char* element){
    int i = 0;
    bool equal = false;
    while(i < nbrel){
        if(strcmp(arr[i], element) == 0){
            equal = true;
            break;
        }
        i++;
    }
    if(equal){
        return i;
    }
    return -1;
}

void removechar(char** arr, size_t nbrel, char* element){
    int index = indexofchar(arr, nbrel, element);
    for(int i = index; i < nbrel; i++){
        if(i != nbrel - 1){
            strcpy(arr[i], arr[i + 1]);
        }
    }
    free(arr[nbrel - 1]);
}

int* removeintwithindex(int* arr, size_t nbrel, int index){
    return removeint(arr, nbrel, arr[index]);
}

void removecharwithindex(char** arr, size_t nbrel, int index){
    removechar(arr, nbrel, arr[index]);
}
