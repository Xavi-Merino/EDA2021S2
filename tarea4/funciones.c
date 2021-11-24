
#include "funciones.h"

#include <string.h>

// leemos archivo
persona *leer_archivo(char *filename, int *N)
{
  FILE *filelist;
  filelist = fopen(filename, "r");
  char line[10000];
  persona p;
  persona *personas;
  int count = 0;
  while (fgets(line, 999, filelist) != NULL)
  {
    count++;
  }
  // count--;  // para que no cuente el titulo
  fclose(filelist);
  *N = count;
  personas = (persona *)malloc(count * sizeof(persona));

  filelist = fopen(filename, "r");
  count = 0;
  fgets(line, 999, filelist);

  while (fgets(line, 999, filelist) != NULL)
  {
    strcpy(p.name, strtok(line, ","));
    p.danger_category = atoi(strtok(NULL, ","));
    p.attack_prob = atof(strtok(NULL, ","));
    new_node(p.name, p.danger_category, p.attack_prob);
    personas[count] = p;
    count++;
  }

  return personas;
}

void show_personas(persona *personas, int cant_personas, int N_output)
{
  for (int i = 0; i < N_output; i++)
  {
    printf("%s, %i, %f\n", personas[i].name, personas[i].danger_category,
           personas[i].attack_prob);
  }
}

void print_node(node *root)
{
  if (root == NULL)
  {
    return;
  }
  printf("nombre: %s,categoria: %i,probabilidad de ataque:  %f, altura: %i, balance: %d\n", root->name, root->danger_category, root->attack_prob, root->height, getBalance(root));
}

void print_tree(node *root)
{
}

//funcion que crea un nodo con los datos de la persona
node *new_node(char *name, int danger_category, float attack_prob)
{
  node *new_node = (node *)malloc(sizeof(node));
  strcpy(new_node->name, name);
  new_node->danger_category = danger_category;
  new_node->attack_prob = attack_prob;
  new_node->height = 1;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

//funcion que calcula la altura maxima entre dos nodos
int max(int a, int b)
{
  return (a > b) ? a : b;
}

//funcion para extraer la altura del nodo
int height(node *root)
{
  if (root == NULL)
    return 0;
  return root->height;
}

//funcion para obtener el factor de balance de un nodo
int getBalance(node *root)
{
  if (root == NULL)
    return 0;
  return height(root->left) - height(root->right);
}

//funcion que actualiza la altura de un nodo
int updateHeight(node *root)
{
  int lh = 0;
  int rh = 0;
  if (root->left != NULL)
  {
    lh = root->left->height;
  }
  if (root->right != NULL)
  {
    rh = root->right->height;
  }
  root->height = 1 + max(lh, rh);
  return root->height;
}

//funcion para ahcer una rotacion a la derecha
node *rightRotate(node *root)
{
  if (root == NULL)
    return NULL;
  node *left = root->left;
  node *right = left->right;

  left->right = root;
  root->left = right;

  updateHeight(root);
  updateHeight(left);

  return left;
}

//funcion para hacer una rotacion a la izquierda
node *leftRotate(node *root)
{
  if (root == NULL)
    return NULL;
  node *right = root->right;
  node *left = right->left;

  right->left = root;
  root->right = left;

  updateHeight(root);
  updateHeight(right);
  return right;
}

//funcion que incerta un nodo en el arbol AVL
node *insert(node *root, char *name, int danger_category, float attack_prob)
{
  if (root == NULL)
  {
    return new_node(name, danger_category, attack_prob);
  }
  else if (name = root->name)
  {
    return root;
  }
  else if (danger_category < root->danger_category)
  {
    if (attack_prob < root->attack_prob)
    {
      root->left = insert(root->left, name, danger_category, attack_prob);
    }
    else
    {
      root->right = insert(root->right, name, danger_category, attack_prob);
    }
  }
  else
  {
    root->right = insert(root->right, name, danger_category, attack_prob);
  }

  updateHeight(root);
  int const rootBalance = getBalance(root);

  if (rootBalance > 1 && danger_category < root->left->danger_category)
  {
    return rightRotate(root);
  }
  if (rootBalance < -1 && danger_category > root->right->danger_category)
  {
    return leftRotate(root);
  }
  return root;
}