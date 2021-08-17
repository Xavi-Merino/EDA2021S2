#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char encrypt(char *key1, char *key2, char *entrada)
{
  char *salida;
  salida = entrada;
  char *aux;
  for (int i=0 ; i <=strlen(salida)-1; i++ )
  {
    for (int j=0; j <= strlen(key1) -1 ; j++ )
    {
      if(salida[i] == key1[j])
      {
        aux = key2[j];
        salida[i] = aux;
      }
      else if(salida[i] == key2[j])
      {
        aux = key1[j];
        salida[i] = aux;
      }
    }
    printf("%c", salida[i]);
  }
  // return salida;
}

char decrypt(char *key1, char *key2, char *entrada)
{

//   return salida;
}