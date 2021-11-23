#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("%s\n",
           "¡ERROR!, el programa solo recibe 2 argumentos (nombre archivo y "
           "cantidad).");
    exit(-1);
  }

  int cant_personas;
  int cant_personas_out = atoi(argv[2]);

  persona *p = leer_archivo(argv[1], &cant_personas);

  if (cant_personas_out > cant_personas) {
    printf("%s\n",
           "¡ERROR!, la cantidad de personas solicitadas excede la cantidad de "
           "personas que hay en el archivo");
    exit(-1);
  }

  if (cant_personas_out < 0) {
    printf(
        "%s\n",
        "¡ERROR! No contaban con nuestra astucia...Debe ingresar un número no "
        "negativo como cantidad de "
        "personas");
    exit(-1);
  }

  if (cant_personas_out == 0) {
    printf("%s\n",
           "¡Error! La idea es mostrar una cantidad de personas, y el 0 tiene "
           "valor nulo...Use un número entero ");
    exit(-1);
  }
  /*prueba de que lee los nombres y su info*/
  show_personas(p, cant_personas, cant_personas_out);
  // swap(p,(p+1));
  printf("\n\n");

  show_personas(p, cant_personas, cant_personas_out);
  // output(p, cant_personas_out, argv[3]);

  return 0;
}
