#include <soma_string.h>


int soma_string(char* string_entrada) {

  int* numeros = string_para_numero(string_entrada);
  int i;
  int total = 0;
  if (numeros[0] == -1) {
    return -1;
  }
  for (i = 1; i < numeros[0] + 1; ++i) {
    total += numeros[i];
  }
  free(numeros);

  return total;

}

int* string_para_numero(char* string_entrada) {

  unsigned int i;
  /* Numero = -1 se o ultimo caracter nao era um numero*/
  int numero = -1;
  int quant_nums = 0;
  int* numeros = (int*)malloc(sizeof(numero));
  if (numeros == NULL) {
    int* erro = (int*)malloc(sizeof(int));
    erro[0] = -1;
    return erro;
  }
  numeros[quant_nums] = 0;

  for (i = 0; i < strlen(string_entrada); ++i) {
    /* Checar cada caracter se e um numero ou nao */
    if (string_entrada[i] < '0' || string_entrada[i] > '9') {
      numero = -1;
    } else {

      if (numero == -1) {
        numero = 0;
        ++quant_nums;
        int* tmp = (int*)realloc(numeros, (sizeof(numero) * quant_nums) + sizeof(numero));
        if (tmp == NULL) {
          int* erro = (int*)malloc(sizeof(int));
          erro[0] = -1;
          return erro;
        } else {
          numeros = tmp;
        }
        numeros[quant_nums] = 0;
      } else {
        /* Para ter numeros maiores que 9 */
        numero *= 10;
      }
      numero += string_entrada[i] - '0';
      numeros[quant_nums] = numero;

    }
  }

  numeros[0] = quant_nums;

  return numeros;

}