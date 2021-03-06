
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "requisitos_key.h"
#include "funciones.h"

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

    if (strcmp(arg2, "encode") != 0 && strcmp(arg2, "decode") != 0)
    {
        fprintf(stderr, "¡Error! El segundo argumento del programa debe ser la palabra 'encode' o 'decode'\n");
        main_exit_code = EXIT_FAILURE;
        exit(0);
    }
    //Validación de que largo de las 2 palabras clave deben ser iguales
    char *arg3 = argv[3];
    char *arg4 = argv[4];
    equal_length(arg3, arg4, main_exit_code);

    //Validacion de que las las keys no tienen las mismas letras
    letters_not_equal(arg3, arg4, main_exit_code);

    //Validacion de que no se repiten letras en las key
    all_char_different(arg3, main_exit_code);
    all_char_different(arg4, main_exit_code);

    //Validación de que el nombre de archivo de entrada debe ser distinto al de salida
    char *arg1 = argv[1];
    char *arg5 = argv[5];
    if (strcmp(arg1, arg5) == 0)
    {
        fprintf(stderr, "¡Error! El nombre de archivo de entrada debe ser distinto al de salida\n");
        main_exit_code = EXIT_FAILURE;
        exit(0);
    }
    //abre archivo de entrada txt y lo almacena en una variable temporal
    char *mensaje = argv[1];
    char temp[1000];
    FILE *archivo = fopen(mensaje, "r");
    fgets(temp, 999, archivo);

    char *mensaje_salida = argv[5];
    if (strcmp(arg2, "encode") == 0)
    {
        const char *salida = encrypt(arg3, arg4, temp);
        FILE *archivo_salida = fopen(mensaje_salida, "w");
        fputs(salida, archivo_salida);
    }
    else
    {
        const char *salida = decrypt(arg3, arg4, temp);
        FILE *archivo_salida = fopen(mensaje_salida, "w");
        fputs(salida, archivo_salida);
    }

    return (main_exit_code);
}
