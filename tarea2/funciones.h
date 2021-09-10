#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
  char name[60];
  int danger_category;
  float attack_prob;
} persona;

persona* leer_archivo(char* filename, int* N);
void show_personas(persona* personas, int N);
void swap(persona *src, persona* dst);
persona* ordena_peligro(persona* p, int cant_personas);
static void Merge(persona *arr, int low, int mid, int high);
void MergeSort(persona *arr, int low, int high);
void swap_cat12_0prob(persona* arr, int cant_personas);