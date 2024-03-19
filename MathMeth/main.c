#include "MathMeth.h"

int hextoten(char input){
    char* extrabase = "ABCDEF";
    if(strchr(extrabase, input) != NULL){
        return strchr(extrabase, input) - extrabase + 10;
    }else{
        return input - '0';
    }
}

char tentohex(int input){
    char* extrabase = "ABCDEF";
    if(input > 9){
        return extrabase[input - 10];
    }else{
        return input + '0';
    }
}

int toten(char* str, int input_base){
    if(input_base != 16 && input_base != 10){
        for(int i = input_base; i < 10; i++){
            if(strchr(str, i + '0') != NULL){
                return 0;
            }
        }
    }
    int power = strlen(str) - 1;
    int result = 0;
    int i =  0;
    int a;
    do{
        a = (int) (pow(input_base, power) + 1e-9);
        if(input_base == 16){
            result +=  a * hextoten(str[i]);
        }else{
            result +=  a * (str[i] - '0');
        }
        power--;
        i++;
    }while(i < strlen(str));
    return result;
}

char* fromtento(char* str, int output_base){
    int rest = strtol(str, NULL, 10);
    int power = (int) (log(rest) / log(output_base));
    int counter = power;
    if(pow(output_base, power) > rest){
        power--;
    }
    char* result = malloc((power + 2) * sizeof(char));
    int i = 0;
    do{
        int tempresult = (int) (rest / pow(output_base, power));
        if(output_base == 16){
            result[i] = tentohex((int) (rest / pow(output_base, power)));
        }else{
            result[i] = (int) (rest / pow(output_base, power)) + '0';
        }
        rest -= (tempresult) * pow(output_base, power);
        power--;
        i++;
    }while(power > -1);
    result[counter + 1] = '\0';
    return result;
}

char* convertbases(char* str, int input_base, int output_base){
    char result[10];
    sprintf(result, "%d", toten(str, input_base));
    char* p = malloc(10 * sizeof(char));
    strcpy(p, result);
    if(output_base == 10){
        return p;
    }else{
        if(input_base != 10){
            return fromtento(result, output_base);
        }else{
            return fromtento(str, output_base);
        }
    }
}
