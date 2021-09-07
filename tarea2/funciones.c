#include "funciones.h"

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
    strcpy(p.name, strtok(NULL, ","));
    p.danger_category = atoi(strtok(line,","));
    p.attack_prob = atof(strtok(NULL,","));
    personas[count] = p;
    count++;
  }
  return personas;
}