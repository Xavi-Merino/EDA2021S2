#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void equal_length(int key1_len, int key2_len){
  if (key1_len != key2_len){
      printf("las key son de distinta longitud, intenta con keys del mismo largo\n");
  }
}


/*funcion que verifica que las letras sean distintas, esto lo hace
  creando un array de 127 posiciones, en el cual cada posición representa
  una letra en formato decimal(ASCII), todos los valores parten en 0,
  de esta forma leyendo la key sumamos 1 a la posicion del arreglo
  'abecedario' que corresponde al valor de la letra en formato ASCII.
  tras registrar la cantidad existente de cada letra en la key, se verifica 
  si alguna letra aparece mas de una vez, en tal caso se imprime cual de 
  las key es la que contiene caracteres repetidos */
void all_char_different(char *key ,int key_len){

  int *abecedario;
  abecedario = (int *) calloc(127, sizeof(int));
  for(int i = 0;i <= key_len; i++ ){
      if(abecedario[key[i]] == 0){
          abecedario[key[i]] = 1;
      }
      else if (abecedario[key[i]] != 0){
          abecedario[key[i]] += 1;
      }                
  }
  for(int j = 0 ; j <= 127; j++){
      if(abecedario[j] > 1 ){
          printf("la key '%s' contiene letras repetidas\n", key);
      }
  }
    
}