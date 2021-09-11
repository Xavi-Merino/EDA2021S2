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
  count--;  // para que no cuente el titulo
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
    personas[count] = p;
    count++;
  }
  return personas;
}

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
    if (arr[leftPos].danger_category <
        arr[rightPos].danger_category)  // 1ro ordenamos por categoria
    {
      temp[mergePos++] = arr[leftPos++];
    } else if ((arr[leftPos].danger_category ==
                arr[rightPos].danger_category) &&
               arr[leftPos].attack_prob <
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

void swap_cat12_0prob(persona* arr, int cant_personas) {
  persona tmp;
  int cant_cat1 = 0, cant_cat2 = 0;

  for (int i = 0; i < cant_personas; i++) {
    if (arr[i].danger_category == 1) {
      cant_cat1++;
    } else if (arr[i].danger_category == 2) {
      cant_cat2++;
    }
  }
  printf("%d %d", cant_cat1, cant_cat2);
  for (int i = 0; i < cant_cat1 - 1; i++) {
    if (arr[i].attack_prob == 0 && i != cant_cat1) {
      tmp = arr[i];
    }
    arr[i] = arr[i + 1];
    arr[cant_cat1 - 1] = tmp;
  }
  for (int i = cant_cat1; i < cant_cat2 - 1; i++) {
    if (arr[i].attack_prob == 0 && i != cant_cat2) {
      tmp = arr[i];
    }
    arr[i] = arr[i + 1];
    arr[cant_cat2 - 1] = tmp;
  }
}
