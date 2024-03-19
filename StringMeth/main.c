#include "StringMeth.h"

int countchar(char * string, char * character){
    char * p = strchr(string, character[0]);
    bool equal = false;
    if (p != NULL)
    {
        for (int i = 0; i < strlen(character); i++)
        {
            if (*(p+i) != character[i])
            {
                equal = false;
                break;
            }
            else
            {
                equal = true;
            }
        }
    }
    int n = 0;
    while(p != NULL){
        if (equal)
        {
            n++;
        }
        if (equal == true){
            p = strchr(p + strlen(character), character[0]);
        }else{
            p = strchr(p + 1, character[0]);
        }
        if (p != NULL)
        {
            for (int i = 0; i < strlen(character); i++){
                if (*(p+i) != character[i])
                {
                    equal = false;
                    break;
                }
                else
                {
                    equal = true;
                }
            }
        }
    }
    free(p);
    return n;
}

int * indexofstr(char * string, char * character)
{
    char * p = strchr(string, character[0]);
    int * indces = malloc(sizeof(int) * countchar(string, character));
    bool equal = false;
    int j = 0;
    if (p != NULL)
    {
        for (int i = 0; i < strlen(character); i++)
        {
            if (*(p+i) != character[i])
            {
                equal = false;
                break;
            }
            else
            {
                equal = true;
            }
        }
    }
    while(p != NULL)
    {
        if (equal)
        {
            indces[j] = p - string;
            j++;
        }
        if (equal == true){
            p = strchr(p + strlen(character), character[0]);
        }else{
            p = strchr(p + 1, character[0]);
        }
        if (p != NULL)
        {
            for (int i = 0; i < strlen(character); i++)
            {
                if (*(p+i) != character[i])
                {
                    equal = false;
                    break;
                }
                else
                {
                    equal = true;
                }
            }
        }
    }
    free(p);
    return indces;
    //don't forget to free indces
}

char **  split(char * string, size_t len, char * sep){
    char ** p = malloc((len) * sizeof(char *));
    int * indices = indexofstr(string, sep);
    p[0] = malloc(indices[0] + 1);
    strncpy(p[0], string, indices[0]);
    p[0][indices[0]] = '\0';
    for(int i = 0; i < len; i++){
        if (i != len - 1)
        {
            p[i + 1] = malloc(indices[i + 1] - indices[i] - strlen(sep) + 1);
            if (p[i + 1] != NULL)
            {
                strncpy(p[i + 1], string + (indices[i] + strlen(sep)), indices[i + 1] - indices[i] - strlen(sep));
                p[i + 1][indices[i + 1] - indices[i] - strlen(sep)] = '\0';
            }
        }
        else
        {
            p[i + 1] = malloc(strlen(string) - indices[i] - strlen(sep));
            if (p[i + 1] != NULL)
            {
                strncpy(p[i + 1], string + (indices[i] + strlen(sep)), strlen(string) - indices[i] - strlen(sep));
                p[i + 1][strlen(string) - indices[i] - strlen(sep)] = '\0';
            }
        }
    }
    return p;
    //don't forget to free p
}

char * join(char ** arr, size_t len, char * sep)
{
    size_t size = len;
    for (int i = 0; i < len; i++)
    {
        size += strlen(arr[i]);
    }
    char * p = malloc(size);
    strcpy(p,arr[0]);
    strcat(p, sep);
    printf("0:%s\n", p);
    if (len + 1 > 1)
    {
        for (int i = 1; i < len; i++)
        {
            strcat(p, arr[i]);
            if (i != len)
            {
                strcat(p, sep);
            }
            printf("%d: %s\n", i, p);
        }
    }
    p[strlen(p)] = '\0';
    return p;
    //don't forget to free p
}

int findchar(char * string, char character)
{
    char * p = strchr(string, character);
    if (p != NULL)
    {
        int indx = p - string;
        free(p);
        return indx;// don't forget to free(p)
    }
    free(p);
    return -1;
}

char* toUpperstr(char* str){
    char* result = malloc(strlen(str) * sizeof(char));
    for(int i = 0; i < strlen(str); i++){
        result[i] = toupper(str[i]);
    }
    result[strlen(str)] = '\0';
    return result;
}
