#include "funciones.h"

#define MAX_lARGO_NOMBRE 60

int main(int argc, char *argv[]) {
  int cant_personas_out = atoi(argv[2]);
  int cant_personas_in = 0;
  if (argc != 3) {
    printf(
        "%s\n",
        "¡ERROR!, el programa debe recibir 2 argumentos (nombre del archivo y "
        "cantidad).");
    exit(-1);
  }

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
           "valor nulo...Use un número entero positivo ");
    exit(-1);
  }

  // iniciamos el nodo root
  struct AVLNode *head = NULL;

  // leemos el archivo y creamos el arbol
  readFile(argv[1], &head, &cant_personas_in);

  // se imprime la estructura del arbol
  printAVLTree(head);

  char *finalListOfNames;
  finalListOfNames = (char *)malloc(MAX_lARGO_NOMBRE * cant_personas_in);

  reverse_inorder(head);

  char *output = "output.txt";
  FILE *file2 = fopen(output, "w");
  insert_names(head);
  fclose(file2);
  printf("\n");
  most_dangerous(cant_personas_out);
  read_and_overwrite(output, cant_personas_out);

  freeAllMemoryInAVLTree(head);
  return 0;
}