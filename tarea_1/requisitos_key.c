#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*(primer requisito)funcion que verifica que los largos de las key 
  sean iguales*/
int equal_length(char *arg3, char *arg4, int main_exit_code){
  if (strlen(arg3) != strlen(arg4))
  {
    fprintf(stderr, "¡Error! El largo de las palabras clave debe ser igual\n");
    main_exit_code = EXIT_FAILURE;
    exit(0);
  }
  return main_exit_code;
}

/*funcion para comparar que las letras de las key no sean iguales*/
int letters_not_equal(char *arg3, char *arg4, int main_exit_code){
  for(int i = 0; i <=  strlen(arg3)-1 ; i++){
    if(arg3[i] == arg4[i])
    {
      fprintf(stderr, "¡Error! la letra %c se repite en ambas key\n", arg3[i]);
      main_exit_code = EXIT_FAILURE;
      exit(0);
    }
  }
  return main_exit_code;
}


/*funcion que verifica que las letras sean distintas, esto lo hace
  creando un array de 127 posiciones, en el cual cada posición representa
  una letra en formato decimal(ASCII), todos los valores parten en 0,
  de esta forma leyendo la key sumamos 1 a la posicion del arreglo
  'abecedario' que corresponde al valor de la letra en formato ASCII.
  tras registrar la cantidad existente de cada letra en la key, se verifica 
  si alguna letra aparece mas de una vez, en tal caso se imprime cual de 
  las key es la que contiene caracteres repetidos */
int all_char_different(char *key ,int main_exit_code){

  int *abecedario;
  abecedario = (int *) calloc(127, sizeof(int));
  for(int i = 0;i <= strlen(key); i++ ){
      if(abecedario[key[i]] == 0){
          abecedario[key[i]] = 1;
      }
      else if (abecedario[key[i]] != 0){
          abecedario[key[i]] += 1;
      }                
  }
  for(int j = 0 ; j <= 127; j++){
      if(abecedario[j] > 1 ){
      fprintf(stderr, "¡Error! la key '%s' contiene letras repetidas\n", key);
      main_exit_code = EXIT_FAILURE;
      exit(0);
      }
  }
  return main_exit_code;  
}

