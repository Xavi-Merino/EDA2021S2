#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estructura para leer las personas en el archivo
typedef struct {
  char name[60];
  int danger_category;
  float attack_prob;
} persona;
// estructura del enemigo
typedef struct {
  char name[60];
  float attack_prob;
} enemigo;
// creamos cada bucket del la tabla hash
typedef struct n {
  char name[60];
  float dato;
  struct n* sgte;
} nodo;

persona* leer_archivo(char* filename, int* N);
void show_personas(persona* personas, int N, int N_output);
nodo* crearLista(float ataque);
void imprimir(nodo* head);
void push_back(nodo* head, float attack_prob);
void push_front(nodo** head, float attack_prob);
int hash(int dato);
void insertar(nodo** tabla, int category, float attack_prob);
void imprimir_tabla(nodo** tabla);

// funciones tarea2
void swap(persona* src, persona* dst);
persona* ordena_peligro(persona* p, int cant_personas);
static void Merge(persona* arr, int low, int mid, int high);
void MergeSort(persona* arr, int low, int high);
void alphabetical_if_equal(persona* arr, int cant_personas);
void case_without_attk_prob45(persona* arr, int cant_personas);
void swap_prob45(persona* arr, int cantidad);
void case_without_attk_prob3(persona* arr, int cant_persona);
void output(persona* a1, int n, char* file);