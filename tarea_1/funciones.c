#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const char *encrypt(char *key1, char *key2, char *entrada)
{
  char *salida;
  salida = entrada;
  char aux;

  for (int k = 0; k < strlen(key1); k++)
  {
    if (key1[k] >= 65 && key1[k] <= 90)
    {
      key1[k] = key1[k] + 32;
    }
  }
  for (int k = 0; k < strlen(key2); k++)
  {
    if (key2[k] >= 65 && key2[k] <= 90)
    {
      key2[k] = key2[k] + 32;
    }
  }

  for (int i = 0; i < strlen(salida); i++)
  {
    for (int j = 0; j < strlen(key1); j++)
    {
      if (salida[i] >= 65 && salida[i] <= 90)
      {
        salida[i] = salida[i] + 32;
        if (salida[i] == key1[j])
        {
          aux = key2[j];
          salida[i] = aux;
        }
        else if (salida[i] == key2[j])
        {
          aux = key1[j];
          salida[i] = aux;
        }
        salida[i] = salida[i] - 32;
      }
      else
      {

        if (salida[i] == key1[j])
        {
          aux = key2[j];
          salida[i] = aux;
        }
        else if (salida[i] == key2[j])
        {
          aux = key1[j];
          salida[i] = aux;
        }
      }
    }

    printf("%c", salida[i]);
  }
  return salida;
}

char decrypt(char *key1, char *key2, char *entrada)
{

  //   return salida;
}