#include "funciones.h"

#include <string.h>

#define ATTKPROB 1.1
// leemos archivo
persona* leer_archivo(char* filename, int* N) {
  FILE* filelist;
  filelist = fopen(filename, "r");
  char line[10000];
  persona p;
  persona* personas;
  enemigo e;
  enemigo* enemigos;
  int count = 0;
  while (fgets(line, 999, filelist) != NULL) {
    count++;
  }
  // count--;  // para que no cuente el titulo
  fclose(filelist);
  *N = count;
  personas = (persona*)malloc(count * sizeof(persona));
  enemigos = (enemigo*)malloc(count * sizeof(enemigo));

  filelist = fopen(filename, "r");
  count = 0;
  fgets(line, 999, filelist);

  while (fgets(line, 999, filelist) != NULL) {
    strcpy(p.name, strtok(line, ","));
    p.danger_category = atoi(strtok(NULL, ","));
    p.attack_prob = atof(strtok(NULL, ","));
    if (p.attack_prob == 0.0 &&
        (p.danger_category == 4 || p.danger_category == 5)) {
      p.attack_prob = ATTKPROB;
    } else if (p.attack_prob == 0.0 && p.danger_category == 3) {
      p.attack_prob = ATTKPROB;
    }
    personas[count] = p;
    count++;
  }

  return personas;
}
// función que crea lista que irá dentro de cada bucket de la tabla hash
nodo* crearLista(float ataque) {
  nodo* n = (nodo*)malloc(sizeof(nodo));
  n->sgte = NULL;
  n->dato = ataque;

  return n;
}
// función que imprime la lista completa en cada bucket
void imprimir(nodo* head) {
  nodo* cursor = head;
  while (cursor != NULL) {
    printf("%f ", cursor->dato);
    cursor = cursor->sgte;
  }
  printf("\n");
}
// función que agrega elemento al final de cada lista
void push_back(nodo* head, float attack_prob) {
  nodo* n = crearLista(attack_prob);
  nodo* cursor = head;
  while (cursor->sgte != NULL) {
    cursor = cursor->sgte;
  }
  cursor->sgte = n;
}
// función que agrega elemento al principio de cada lista
//hash

void push_front(nodo** head, float attack_prob) {
  nodo* tmp = *head;

  nodo* new_head = crearLista(attack_prob);
  *head = new_head;
  (*head)->sgte = tmp;
}
// función de hash
int hash(int dato) { return (dato * 1); }

//order tabla by attack_prob from low to high
persona ordenar(persona* personas, int N) {
  persona aux;
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (personas[i].attack_prob > personas[j].attack_prob) {
        aux = personas[i];
        personas[i] = personas[j];
        personas[j] = aux;
      }
    }
  }
  return personas[0];
}
// función que inserta cada lista en el bucket de la tabla de hash
void insertar(nodo** tabla, int category, float attack_prob) {
  int index = hash(category);
  if (tabla[index] == NULL) {
    tabla[index] =
        crearLista(attack_prob);  // creamos lista en caso de que la tabla no
                                  // tenga valor en ese índice
  } else {
    push_back(tabla[index], attack_prob);
  }
}

// imprime tabla hash completa
void imprimir_tabla(nodo** tabla) {
  for (int i = 1; i < 6; i++) {
    printf("%d: ", i);
    imprimir(tabla[i]);
  }
}

// funciones tarea2
//----------------------------------------------o----------------------------------------------------
void swap(persona* src, persona* dst) {
  persona tmp = *src;
  *src = *dst;
  *dst = tmp;
}

void show_personas(persona* personas, int cant_personas, int N_output) {
  for (int i = 0; i < N_output; i++) {
    printf("%s, %i, %f\n", personas[i].name, personas[i].danger_category,
           personas[i].attack_prob);
  }
}

static void Merge(persona* arr, int low, int mid,
                  int high)  // ordena danger_category
{
  int mergedSize = high - low + 1;
  persona* temp = (persona*)malloc(mergedSize * sizeof(persona));
  int mergePos = 0;
  int leftPos = low;
  int rightPos = mid + 1;
  while (leftPos <= mid && rightPos <= high)  // aca sucede la magia
  {
    if (arr[leftPos].danger_category >
        arr[rightPos].danger_category)  // 1ro ordenamos por categoria
    {
      temp[mergePos++] = arr[leftPos++];
    } else if ((arr[leftPos].danger_category ==
                arr[rightPos].danger_category) &&
               arr[leftPos].attack_prob >
                   arr[rightPos].attack_prob)  // 2do por attack_prob
    {
      temp[mergePos++] = arr[leftPos++];
    } else {
      temp[mergePos++] = arr[rightPos++];
    }
  }

  while (leftPos <= mid) {
    temp[mergePos++] = arr[leftPos++];
  }

  while (rightPos <= high) {
    temp[mergePos++] = arr[rightPos++];
  }

  for (mergePos = 0; mergePos < mergedSize; ++mergePos)
    arr[low + mergePos] = temp[mergePos];

  free(temp);
}

void MergeSort(persona* arr, int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;

    MergeSort(arr, low, mid);
    MergeSort(arr, mid + 1, high);

    Merge(arr, low, mid, high);
  }
}

void alphabetical_if_equal(persona* arr, int cant_personas) {
  for (int i = 0; i < cant_personas;
       i++) {  // algoritmo bubble sort para ordenar alfabéticamente
    for (int j = 0; j < cant_personas - 1 - i; j++) {
      if ((arr[j].danger_category == arr[j + 1].danger_category) &&
          (arr[j].attack_prob == arr[j + 1].attack_prob)) {
        if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
          // swap array[j] and array[j+1]
          swap(&arr[j], &arr[j + 1]);
        }
      }
    }
  }
}

void case_without_attk_prob45(persona* arr, int cant_personas) {
  for (int i = 0; i < cant_personas; i++) {
    if (arr[i].attack_prob > 1) {
      arr[i].attack_prob = 0;
    }
  }
}

// void mid_insertion(persona* arr, int l, int r) { int mid = l + (l - r) / 2; }

void case_without_attk_prob3(persona* arr, int cant_persona) {
  int cant_cat3 = 0;
  float suma_attack_prob = 0;
  float mean_attack_prob = 0;
  for (int i = 0; i < cant_persona; i++) {
    if (arr[i].danger_category == 3 && arr[i].attack_prob != 0.0) {
      suma_attack_prob = suma_attack_prob + arr[i].attack_prob;
      cant_cat3 = cant_cat3 + 1;
    }
  };
  if (cant_cat3 != 0) {
    mean_attack_prob = suma_attack_prob / cant_cat3;
  }
  for (int i = 0; i < cant_persona; i++) {
    if ((arr[i].danger_category == 3) && (arr[i].attack_prob == 0))
      arr[i].attack_prob = mean_attack_prob;
  }
}

void output(persona* personas, int n, char* file) {
  int i = 0;
  char texto2[10000] = "";
  persona each_person;
  char space_text[10000];
  FILE* file2 = fopen(file, "w");
  for (i; i < n; i++) {
    strcpy(space_text, "");
    strcpy(each_person.name, personas[i].name);
    strcat(space_text, each_person.name);
    strcat(space_text, "\n");
    fputs(space_text, file2);
  }
  fclose(file2);
}
