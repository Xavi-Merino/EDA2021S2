
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "requisitos_key.h"

int main(int argc, char *argv[])
{
    //1. validación y verificación de argumentos
    //Validación de 5 argumentos después de ./tarea1
    int main_exit_code = EXIT_SUCCESS;
    if (argc != 6)
    {
        fprintf(stderr, "¡Error! El programa debe recibir 5 argumentos\n");
        main_exit_code = EXIT_FAILURE;
        exit(0);
    };
    //Validación de que el segundo argumento debe ser la palabra encode o decode
    char *arg2 = argv[2];
    char *arg22 = argv[2];
    char word1[7] = "encode";
    char word2[7] = "decode";
    if (strcmp(arg2, word1) != 0 && strcmp(arg22, word2) != 0)
    {
        fprintf(stderr, "¡Error! El segundo argumento del programa debe ser la palabra 'encode' o 'decode'\n");
        main_exit_code = EXIT_FAILURE;
        exit(0);
    }
    //Validación de que largo de las 2 palabras clave deben ser iguales
    char *arg3 = argv[3];
    char *arg4 = argv[4];
    if (strlen(arg3) != strlen(arg4))
    {
        fprintf(stderr, "¡Error! El largo de las palabras clave debe ser igual\n");
        main_exit_code = EXIT_FAILURE;
        exit(0);
    }

    //Validación de que el nombre de archivo de entrada debe ser distinto al de salida
    char *arg1 = argv[1];
    char *arg5 = argv[5];
    if (strcmp(arg1, arg5) == 0)
    {
        fprintf(stderr, "¡Error! El nombre de archivo de entrada debe ser distinto al de salida\n");
        main_exit_code = EXIT_FAILURE;
        exit(0);
    }

    //Probamos la entrada del algoritmo con el input de ejemplo de ejecución de las instrucciones de la tarea
    int i;
    printf("argc = %d\n", argc);
    for (i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    //abre archivo de entrada txt y lo almacena en una variable temporal
    char *mensaje = argv[1];
    char temp[1000];
    FILE *archivo = fopen(mensaje, "r");
    fgets(temp, 999, archivo);
    printf("%s\n", temp);

    // int key1_len = strlen(argv[2]);
    // int key2_len = strlen(argv[3]);
    // all_char_different(argv[2], key1_len);
    // all_char_different(argv[3], key1_len);

    // equal_length(argv[1],argv[2]);
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
    char *mensaje_salida = argv[5];
    char temp_2[1000];
    FILE *archivo_salida = fopen(mensaje_salida, "w");
    fputs("Este es el mensaje final, interpolar con el output de la funcion", archivo_salida);

    return (main_exit_code);
}
