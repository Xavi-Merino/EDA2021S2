#include "funciones.h"

#include <string.h>

persona* leer_archivo(char* filename, int* N) {
  FILE* filelist;
  filelist = fopen(filename, "r");
  char line[1000];
  persona p;
  persona* personas;
  int count = 0;
  while (fgets(line, 999, filelist) != NULL) {
    count++;
  }
  fclose(filelist);
  *N = count;
  personas = (persona*)malloc(count * sizeof(persona));

  filelist = fopen(filename, "r");
  count = 0;
  while (fgets(line, 999, filelist) != NULL) {
    strcpy(p.name, strtok(line, ","));
    p.danger_category = atoi(strtok(NULL, ","));
    p.attack_prob = atof(strtok(NULL, ","));
    personas[count] = p;
    count++;
  }
  return personas;
}

void show_personas(persona* personas, int N) {
  for (int i = 1; i < N; i++) {
    printf("%s, %i, %f\n", personas[i].name, personas[i].danger_category,
           personas[i].attack_prob);
  }
}