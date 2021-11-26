#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// estructura de nodos den arbol AVL
typedef struct node {
  char name[100];
  int danger_category;
  float attack_prob;
  int height;
  struct node *left;
  struct node *right;
} node;

node *read_file(char *filename, int N);
// operaciones de memoria
node *new_node(char *name, int danger_category, float attack_prob);

// oprecaiones de modificación
node *insert(node *root, char *name, int danger_category, float attack_prob);

// leer propiedades de un nodo
int updateHeight(node *root);
int getBalance(node *root);
int height(node *root);

// funciones de utilidad
int max(int a, int b);

// imprimir arbol

void print_node(int max_salida);

void print_personas(node *root);