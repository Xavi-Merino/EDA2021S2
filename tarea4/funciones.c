
#include "funciones.h"

#include <string.h>

// leemos archivo
persona* leer_archivo(char* filename, int* N) {
  FILE* filelist;
  filelist = fopen(filename, "r");
  char line[10000];
  persona p;
  persona* personas;
  int count = 0;
  while (fgets(line, 999, filelist) != NULL) {
    count++;
  }
  // count--;  // para que no cuente el titulo
  fclose(filelist);
  *N = count;
  personas = (persona*)malloc(count * sizeof(persona));

  filelist = fopen(filename, "r");
  count = 0;
  fgets(line, 999, filelist);

  while (fgets(line, 999, filelist) != NULL) {
    strcpy(p.name, strtok(line, ","));
    p.danger_category = atoi(strtok(NULL, ","));
    p.attack_prob = atof(strtok(NULL, ","));
    // if (p.attack_prob == 0.0 &&
    //   (p.danger_category == 4 || p.danger_category == 5)) {
    // p.attack_prob = ATTKPROB;
    //} else if (p.attack_prob == 0.0 && p.danger_category == 3) {
    // p.attack_prob = ATTKPROB;
    //}
    personas[count] = p;
    count++;
  }

  return personas;
}

void show_personas(persona* personas, int cant_personas, int N_output) {
  for (int i = 0; i < N_output; i++) {
    printf("%s, %i, %f\n", personas[i].name, personas[i].danger_category,
           personas[i].attack_prob);
  }
}
