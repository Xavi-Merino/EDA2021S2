#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

int main(int argc, char *argv[]) {
  int cant_personas;
  int cant_personas_out = atoi(argv[2]);
  /*prueba de que lee los nombres y su info*/
  persona *p = leer_archivo(argv[1], &cant_personas);
  show_personas(p, cant_personas);
  // swap(p,(p+1));
  // printf("\n\n");
  // show_personas(p, cant_personas);


  MergeSort(p, 0, cant_personas - 1);
  printf("\n\n");
  show_personas(p, cant_personas);
  // swap_cat12_0prob(p,cant_personas);
  // printf("\n\n");
  // show_personas(p, cant_personas);

  return 0;
}
