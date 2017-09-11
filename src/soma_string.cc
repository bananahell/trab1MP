#include <soma_string.h>


int soma_string(char* string_entrada) {

  if (checa_string(string_entrada) == false) {
    return -1;
  }
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

bool checa_string(char* string_entrada) {

  /* O menor caso e nenhum numero, entao por exemplo "\n" */
  if (strlen(string_entrada) < 2) {
    if (strcmp(string_entrada, "\n") == 0) {
      return true;
    }
    return false;
  }

  /* Se tem delimitador */
  unsigned int i = 0;
  char* delimitador;
  int tam_delimit = 0;
  if (string_entrada[0] == '/' && string_entrada[1] == '/') {
    /* TODO pegar o delimitador */
    /* Colocar o i logo depois da linha do delimitador */
    while (string_entrada[i] != '\n') {
      ++i;
    }
    i += 2;
  } else {
    delimitador = (char*)malloc(strlen(",") * sizeof(char));
    strncpy(delimitador, ",", strlen(","));
    tam_delimit = strlen(",");
  }

  /* Se nao terminar com \n */
  if (string_entrada[strlen(string_entrada) - 1] != '\n') {
    free(delimitador);
    return false;
  }
  /* Se nao comecar com numero */
  if (string_entrada[i] < '0' ||
      string_entrada[i] > '9') {
    if (i != strlen(string_entrada) - 1) {
      free(delimitador);
      return false;
    }
  }

  while (i < strlen(string_entrada)) {
    /* Checar se e numero e ate onde e numero */
    if (string_entrada[i] >= '0' && string_entrada[i] <= '9') {
      ++i;
    /* Checar se agora ocorre quebra de linha */
    } else if (string_entrada[i] == '\n') {
      ++i;
    /* Checa se e o delimitador */
    } else {

      int j = 0;
      while (j < tam_delimit) {
        /* Checando se e o delimitador */
        if (string_entrada[i+j] != delimitador[j]) {
          free(delimitador);
          return false;
        }
        ++i;
        ++j;
        /* Se terminar com o delimitador */
        if (i == strlen(string_entrada) - 1) {
          free(delimitador);
          return false;
        }
      }

    }
  }

  free(delimitador);
  return true;

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
