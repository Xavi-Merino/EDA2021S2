#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[60];
  int danger_category;
  float attack_prob;
} persona;

persona* leer_archivo(char* filename, int* N);
void show_personas(persona* personas, int N, int N_output);
void swap(persona* src, persona* dst);
persona* ordena_peligro(persona* p, int cant_personas);
static void Merge(persona* arr, int low, int mid, int high);
void MergeSort(persona* arr, int low, int high);
void alphabetical_if_equal(persona* arr, int cant_personas);
void case_without_attk_prob45(persona* arr, int cant_personas);
void swap_prob45(persona* arr, int cantidad);
void case_without_attk_prob3(persona* arr, int cant_persona);
void output(persona* a1, int n, char* file);