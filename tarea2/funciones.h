#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name [60];
    int danger_category;
    float attack_prob;
}persona;

persona* leer_archivo(char* filename, int* N);