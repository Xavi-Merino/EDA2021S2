#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("%s\n", "¡ERROR!, el programa solo recibe 3 argumentos.");
    exit(-1);
  }

  if (strcmp(argv[1], argv[2]) == 0) {
    printf("%s\n",
           "¡ERROR!, el los nombres de los archivos de entrada y salida deben "
           "ser diferentes");
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
  // show_personas(p, cant_personas);

  // case_without_attk_prob3(p, cant_personas);
  // show_personas(p, cant_personas, cant_personas_out);
  // printf("\n\n");

  // MergeSort(p, 0, cant_personas - 1);
  // printf("\n\n");

  // case_without_attk_prob45(p, cant_personas);
  //  show_personas(p, cant_personas, cant_personas_out);
  //  printf("\n\n");
  // case_without_attk_prob3(p, cant_personas);
  //  show_personas(p, cant_personas, cant_personas_out);
  //  printf("\n\n");

  // MergeSort(p, 0, cant_personas - 1);
  // printf("\n\n");

  // alphabetical_if_equal(p, cant_personas);
  //  show_personas(p, cant_personas, cant_personas_out);
  //  printf("\n\n");

  // output(p, cant_personas_out, argv[3]);

  nodo **tabla;
  tabla = (nodo **)malloc(10 * sizeof(nodo *));

  for (int i = 1; i < 6; i++) {
    tabla[i] = NULL;
  }

  // if (p->danger_category==1){
  // insertar(tabla[1])
  //}
  for (int i = 0; i < cant_personas; i++) {
    insertar(tabla, p[i].danger_category, p[i].attack_prob);
  }

  imprimir_tabla(tabla);
  output(p, cant_personas_out, argv[3]);

  return 0;
}
