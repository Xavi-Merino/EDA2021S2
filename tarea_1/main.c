#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "requisitos_key.c"

int main(int argc, char *argv[])
{
    equal_length(argv[1],argv[2]);
    /*obtenemos el largo de las key mediante strlen*/    
    // int len1 = strlen(argv[1]);
    // int len2 = strlen(argv[2]);
    // char *key1, *key2;
    // key1 = (char *) malloc(sizeof(len1));
    // key2 = (char *) malloc(sizeof(len1));
    // strcpy(key1,argv[1]);
    // strcpy(key2,argv[2]);

    
    // printf("%c\n", *(key1+2));
    // printf("%s\n", key2);
    return 0;
}
