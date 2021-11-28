#include "funciones.h"

size_t sizeOfAVLNode = sizeof(AVLNode *);

void freeAllMemoryInAVLTree(AVLNode *const root)
{
  if (root)
  {
    freeAllMemoryInAVLTree(root->left);
    freeAllMemoryInAVLTree(root->right);
    free(root);
  }
}

AVLNode *newAVLNode(char *name, int danger_category, float attack_prob, float factorPeligro)
{
  AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));

  strcpy(newNode->name, name);
  newNode->danger_category = danger_category;
  newNode->attack_prob = attack_prob;
  newNode->factorPeligro = factorPeligro;
  newNode->height = 1;
  newNode->left = newNode->right = NULL;

  return newNode;
}

void printAVLNode(AVLNode *const root)
{
  if (root)
  {
    printf("name : %s, categoria : %d, probabilidad : %f height : %d \n", root->name, root->danger_category, root->attack_prob, root->height);
  }
}

static void printAVLTreeWithIndentation(AVLNode *const root, char const seperator, char const repeater)
{
  if (root)
  {
    printAVLTreeWithIndentation(root->left, seperator, repeater + 2);

    for (int i = 0; i < repeater; ++i)
    {
      printf("%c", seperator);
    }

    printf(">");
    printAVLNode(root);

    printAVLTreeWithIndentation(root->right, seperator, repeater + 2);
  }
}
void printAVLTree(AVLNode *const root)
{
  printf("\n");
  printAVLTreeWithIndentation(root, '-', 0);
}

inline int heightOfAVLNode(AVLNode *const root)
{
  return root ? root->height : 0;
}

inline int max(int const numberOne, int const numberTwo)
{
  return (numberOne > numberTwo) ? numberOne : numberTwo;
}

int updateHeight(AVLNode *const root)
{
  if (root)
  {
    root->height = 1 + max(heightOfAVLNode(root->left), heightOfAVLNode(root->right));
    return root->height;
  }
  return 0;
}

int balanceFactorOfAVLNode(AVLNode *const root)
{
  return root ? heightOfAVLNode(root->left) - heightOfAVLNode(root->right) : 0;
}

AVLNode *rotateRight(AVLNode *const root)
{
  if (root)
  {

    AVLNode *const leftChild = root->left;
    AVLNode *const rightOfLeftChild = leftChild->right;

    leftChild->right = root;
    root->left = rightOfLeftChild;

    updateHeight(root);
    updateHeight(leftChild);

    return leftChild;
  }
  return root;
}

AVLNode *rotateLeft(AVLNode *const root)
{
  if (root)
  {
    AVLNode *rightChild = root->right;
    AVLNode *leftOfRightChild = rightChild->left;

    rightChild->left = root;
    root->right = leftOfRightChild;

    //actualizar informacion de altura
    updateHeight(root);
    updateHeight(rightChild);

    return rightChild;
  }
  return root;
}
AVLNode *insert(AVLNode *root, char *name, int danger_category, float attack_prob, float factorPeligro)
{
  if (root)
  {
    //verifica que el nombre no este en el arbol par ano introducir el nodo
    if (root->name != name)
    {
      if (factorPeligro < root->factorPeligro)
      {
        root->left = insert(root->left, name, danger_category, attack_prob, factorPeligro);
      }
      else if (factorPeligro > root->factorPeligro)
      {
        root->right = insert(root->right, name, danger_category, attack_prob, factorPeligro);
      }
      updateHeight(root);

      int const rootBalanceFactor = balanceFactorOfAVLNode(root);

      if (rootBalanceFactor > 1)
      {
        if (factorPeligro > root->left->factorPeligro)
          root->left = rotateLeft(root->left);
        root = rotateRight(root);
      }
      else if (rootBalanceFactor < -1)
      {
        if (factorPeligro < root->right->factorPeligro)
          root->right = rotateRight(root->right);
        root = rotateLeft(root);
      }
    }

    return root;
  }

  return newAVLNode(name, danger_category, attack_prob, factorPeligro);
}
static AVLNode *orElse(AVLNode *firstChoice, AVLNode *secondChoice)
{
  return firstChoice ? firstChoice : secondChoice;
}

void readFile(char *fileName, AVLNode **root, int *cantidad_personas_in)
{
  FILE *file = fopen(fileName, "r");
  if (file)
  {
    char name[60];
    int category = 0;
    float attack_prob = 0;
    float factorPeligro = 0;
    char line[1000];
    fgets(line, 999, file);
    int count = 0;

    while (fgets(line, 999, file) != NULL)
    {
      strcpy(name, strtok(line, ","));
      category = atoi(strtok(NULL, ","));
      attack_prob = atof(strtok(NULL, ","));
      factorPeligro = category + attack_prob;
      *root = insert(*root, name, category, attack_prob, factorPeligro);
      count++;
    }
    *cantidad_personas_in = count;
    fclose(file);
  }
}

void reverse_inorder(AVLNode *root)
{
  if (root == NULL)
    return;

  reverse_inorder(root->right);

  printf("%s \n", root->name);

  reverse_inorder(root->left);
}
