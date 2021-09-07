#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char *argv[])
{
    int num;
    /*prueba de que lee los nombres y su info*/
    persona *p = leer_archivo(argv[1], &num);
    return 0;
}
