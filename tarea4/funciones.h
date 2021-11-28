#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVLNode {
  struct AVLNode *left;
  struct AVLNode *right;
  char name[60];
  int danger_category;
  float attack_prob;
  float factorPeligro;
  int height;
} AVLNode;

// memoria
AVLNode *newAVLNode(char *name, int danger_category, float attack_prob,
                    float factorPeligro);

// modificaciones
AVLNode *insert(AVLNode *root, char *name, int danger_category,
                float attack_prob, float factorPeligro);
extern void freeAllMemoryInAVLTree(AVLNode *const);

// balanceo
extern AVLNode *rotateLeft(AVLNode *const);
extern AVLNode *rotateRight(AVLNode *const);

// propiedaes de los nodos
extern int updateHeight(AVLNode *const);
extern int balanceFactorOfAVLNode(AVLNode *const);
extern int heightOfAVLNode(AVLNode *const);

// utilidades
extern int max(int const, int const);
void readFile(char *fileName, AVLNode **root, int *cantidad_personas_in);
char *finalListInsert(char *name);

// imprimir arbol(arriba izquierda abajo derecha)
extern void printAVLTree(AVLNode *const);
extern void printAVLNode(AVLNode *const);
void reverse_inorder(AVLNode *root);
void insert_names(AVLNode *root);
void most_dangerous(int personas_out);
void read_and_overwrite(char *filename, int numberOfLines);