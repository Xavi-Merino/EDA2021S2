#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf(
        "%s\n",
        "¡ERROR!, el programa debe recibir 2 argumentos (nombre del archivo y "
        "cantidad).");
    exit(-1);
  }
  int cant_personas_out = atoi(argv[2]);

  if (cant_personas_out < 0) {
    printf("%s\n",
           "¡ERROR! Debe ingresar un número no "
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

  node* tree = read_file(argv[1], cant_personas_out);
  char* output = "output.txt";
  FILE* file2 = fopen(output, "w");
  fclose(file2);
  print_personas(tree);
  print_node(cant_personas_out);

  return 0;
}
