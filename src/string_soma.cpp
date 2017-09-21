/**
 * @file string_soma.cpp
 * 
 * @brief Arquivo com a função que transforma uma string em números e os soma.
 *
 * @author Pedro Nogueira - 14/0065032
 *
 */

#include <string_soma.hpp>


int soma_string(char* string_entrada) {

  if (checa_string(string_entrada) == false) {
    return -1;
  }
  int* numeros = string_para_numero(string_entrada);
  /* Ocorreu algum problema ao alocar memória dinamicamente */
  if (numeros == NULL) {
    return -1;
  }
  int i;
  int total = 0;
  for (i = 1; i < numeros[0] + 1; ++i) {
    /* Se tem algum número maior ou igual a 1000 */
    if (numeros[i] > 999) {
      numeros[i] = 0;
    }
    total += numeros[i];
  }
  free(numeros);

  return total;

}

bool checa_string(char* string_entrada) {

  /* O menor caso é nenhum número, então = "\n" */
  if (strlen(string_entrada) < 2) {
    if (strcmp(string_entrada, "\n") == 0) {
      return true;
    }
    return false;
  }

  unsigned int i = 0;
  char** delimitadores;
  int qtd_delimitadores;
  /* Se tem delimitador */
  if (string_entrada[0] == '/' && string_entrada[1] == '/') {
    delimitadores = checa_delimitadores(string_entrada);
    /* Se deu algum problema com os delimitadores */
    if (delimitadores == NULL) {
      return false;
    }
    /* Colocar o i assim que começarem os números */
    while (string_entrada[i] < '0' || string_entrada[i] > '9') {
      ++i;
    }
    /* Achar a quantidade de delimitadores */
    if (delimitadores[0][0] == '0') {
      qtd_delimitadores = strlen(delimitadores[0]);
    }
  } else {
    /* Criar delimitador padrão */
    delimitadores = (char**)malloc(3 * sizeof(char*));
    if (delimitadores == NULL) {
      printf("\n - Ocorreu algum problema");
      printf(" na alocação dinâmica de memória! -\n");
      return false;
    }
    delimitadores[0] = (char*)malloc(2 * sizeof(char));
    if (delimitadores[0] == NULL) {
      printf("\n - Ocorreu algum problema");
      printf(" na alocação dinâmica de memória! -\n");
      free(delimitadores);
      return false;
    }
    delimitadores[1] = (char*)malloc(sizeof(char) + 2);
    if (delimitadores[1] == NULL) {
      printf("\n - Ocorreu algum problema");
      printf(" na alocação dinâmica de memória! -\n");
      free(delimitadores[0]);
      free(delimitadores);
      return false;
    }
    delimitadores[0][0] = ',';
    delimitadores[0][1] = '\0';
    delimitadores[1][0] = '0';
    delimitadores[1][1] = '0';
    delimitadores[1][2] = '\0';
    qtd_delimitadores = strlen(delimitadores[1]);
  }

  /* Se não terminar com \n */
  if (string_entrada[strlen(string_entrada) - 1] != '\n') {
    for (i = 0; (int)i < qtd_delimitadores; ++i) {
      free(delimitadores[i]);
    }
    free(delimitadores);
    return false;
  }
  /* Se não começar com número */
  if (string_entrada[i] < '0' ||
      string_entrada[i] > '9') {
    if (i != strlen(string_entrada) - 1) {
      for (i = 0; (int)i < qtd_delimitadores; ++i) {
        free(delimitadores[i]);
      }
      free(delimitadores);
      return false;
    }
  }

  int quant_nums = 0;
  while (i < strlen(string_entrada)) {
    /* Se tiver mais números em uma linha que o especificado */
    if (quant_nums > 3) {
      for (i = 0; (int)i < qtd_delimitadores; ++i) {
        free(delimitadores[i]);
      }
      free(delimitadores);
      return false;
    }
    /* Checar se é número e até onde é número */
    if (string_entrada[i] >= '0' && string_entrada[i] <= '9') {
      if (i == 0 || string_entrada[i-1] < '0' || string_entrada[i-1] > '9') {
        ++quant_nums;
      }
      ++i;
    /* Checar se agora ocorre quebra de linha */
    } else if (string_entrada[i] == '\n') {
      quant_nums = 0;
      ++i;
    /* Checa se é o delimitador */
    } else {

      int j;
      int k;
      bool ja_passou = false;
      for (k = 0; k < qtd_delimitadores; ++k) {
        if (ja_passou) {
          break;
        }
        j = 0;
        while (j < (int)strlen(delimitadores[k])) {
          /* Checando se é o delimitador */
          if (string_entrada[i+j] != delimitadores[k][j]) {
            if (k != qtd_delimitadores - 1) {
              break;
            }
            for (i = 0; (int)i < qtd_delimitadores; ++i) {
              free(delimitadores[i]);
            }
            free(delimitadores);
            return false;
          }
          ++j;
          /* Se terminar com o delimitador */
          if (i + j == strlen(string_entrada) - 1) {
            for (i = 0; (int)i < qtd_delimitadores; ++i) {
              free(delimitadores[i]);
            }
            free(delimitadores);
            return false;
          }
         ja_passou = true;
        }
      }
      i += j;

    }
  }

  for (i = 0; (int)i < qtd_delimitadores; ++i) {
    free(delimitadores[i]);
  }
  free(delimitadores);
  return true;

}

char** checa_delimitadores(char* string_entrada) {

  int quant_elem = 0;
  char** delimitadores = (char**)malloc(sizeof(char*));
  if (delimitadores == NULL) {
    printf("\n - Ocorreu algum problema na alocação dinâmica de memória! -\n");
    return NULL;
  }
  ++quant_elem;
  delimitadores[0] = (char*)malloc(3 * sizeof(char));
  if (delimitadores[0] == NULL) {
    printf("\n - Ocorreu algum problema na alocação dinâmica de memória! -\n");
    free(delimitadores);
    return NULL;
  }
  ++quant_elem;
  delimitadores[0][0] = '0';
  delimitadores[0][1] = '0';
  delimitadores[0][2] = '\0';
  delimitadores[1] = (char*)malloc(2 * sizeof(char));
  if (delimitadores[1] == NULL) {
    printf("\n - Ocorreu algum problema na alocação dinâmica de memória! -\n");
    free(delimitadores[0]);
    free(delimitadores);
    return NULL;
  }
  delimitadores[1][0] = '0';
  delimitadores[1][1] = '\0';
  unsigned int i = 2;
  int tamanho_delimit;
  /* Olhando dentro da lista de delimitadores */
  while ((string_entrada[i] < '0' || string_entrada[i] > '9')
         && i != strlen(string_entrada) - 1) {
    /* Achando um delimitador */
    if (string_entrada[i] == '[') {
      ++i;
      /* Se houver um delimitador vazio na lista */
      if (string_entrada[i] == ']') {
        for (i = 0; (int)i < quant_elem; ++i) {
          free(delimitadores[i]);
        }
        free(delimitadores);
        return NULL;
      }
      tamanho_delimit = 0;
      /* Pegando o que tem entre os colchetes, que é o delimitador */
      while (string_entrada[i+tamanho_delimit] != ']'
             && i + tamanho_delimit != strlen(string_entrada) - 1) {
        ++tamanho_delimit;
      }
      char** aux = (char**)realloc(delimitadores,
                                   (quant_elem + 1) * (sizeof(char*)));
      if (aux == NULL) {
        printf("\n - Ocorreu algum problema");
        printf(" na alocação dinâmica de memória! -\n");
        for (i = 0; (int)i < quant_elem; ++i) {
          free(delimitadores[i]);
        }
        free(delimitadores);
        return NULL;
      }
      delimitadores = aux;
      ++quant_elem;
      char* aux_ind = (char*)realloc(delimitadores[0],
                                     (quant_elem + 1) * sizeof(char));
      if (aux_ind == NULL) {
        printf("\n - Ocorreu algum problema");
        printf(" na alocação dinâmica de memória! -\n");
        for (i = 0; (int)i < quant_elem; ++i) {
          free(delimitadores[i]);
        }
        free(delimitadores);
        return NULL;
      }
      delimitadores[0] = aux_ind;
      delimitadores[0][quant_elem-1] = '0';
      delimitadores[0][quant_elem] = '\0';
      delimitadores[quant_elem-1] = (char*)malloc((tamanho_delimit + 1)
                                                  * sizeof(char));
      if (delimitadores[quant_elem-1] == NULL) {
        printf("\n - Ocorreu algum problema");
        printf(" na alocação dinâmica de memória! -\n");
        for (i = 0; (int)i < quant_elem; ++i) {
          free(delimitadores[i]);
        }
        free(delimitadores);
        return NULL;
      }
      int m;
      for (m = 0; m < tamanho_delimit; ++m) {
        delimitadores[quant_elem-1][m] = string_entrada[i+m];
      }
      delimitadores[quant_elem-1][tamanho_delimit] = '\0';
      i += tamanho_delimit;
    /* Se achar quebra de linha como se fosse terminar e não termina */
    } else if (string_entrada[i] == '\n') {
      if ((string_entrada[i+1] < '0' || string_entrada[i+1] > '9')
          && string_entrada[i+1] != '\n') {
        for (i = 0; (int)i < quant_elem; ++i) {
          free(delimitadores[i]);
        }
        free(delimitadores);
        return NULL;
      }
    /* Se achar qualquer coisa fora de colchetes
         ou que não é quebra de linha */
    } else {
      for (i = 0; (int)i < quant_elem; ++i) {
        free(delimitadores[i]);
      }
      free(delimitadores);
      return NULL;
    }
    ++i;
  }

  /* Se a lista de delimitadores não terminar com \n */
  if (string_entrada[i-1] != '\n') {
    for (i = 0; (int)i < quant_elem; ++i) {
      free(delimitadores[i]);
    }
    free(delimitadores);
    return NULL;
  }
  /* Se só tem a lista de delimitadores */
  if (i == strlen(string_entrada) - 1) {
    for (i = 0; (int)i < quant_elem; ++i) {
      free(delimitadores[i]);
    }
    free(delimitadores);
    return NULL;
  }

  return delimitadores;

}

int* string_para_numero(char* string_entrada) {

  unsigned int i;
  /* Número = -1 se o último caracter não era um número */
  int numero = -1;
  int quant_nums = 0;
  int* numeros = (int*)malloc(sizeof(numero));
  if (numeros == NULL) {
    printf("\n - Ocorreu algum problema na alocação dinâmica de memória! -\n");
    free(numeros);
    return NULL;
  }
  numeros[quant_nums] = 0;

  for (i = 0; i < strlen(string_entrada); ++i) {
    /* Checar cada caracter se é um numero ou nao */
    if (string_entrada[i] < '0' || string_entrada[i] > '9') {
      numero = -1;
    } else {

      /* Começando um novo número inteiro */
      if (numero == -1) {
        numero = 0;
        ++quant_nums;
        int* tmp = (int*)realloc(numeros, (sizeof(numero) * quant_nums)
                                            + sizeof(numero));
        if (tmp == NULL) {
          printf("\n - Ocorreu algum problema");
          printf(" na alocação dinâmica de memória! -\n");
          free(numeros);
          return NULL;
        } else {
          numeros = tmp;
        }
        numeros[quant_nums] = 0;
      } else {
        /* Para ter números maiores que 9 */
        numero *= 10;
      }
      numero += string_entrada[i] - '0';
      numeros[quant_nums] = numero;

    }
  }

  numeros[0] = quant_nums;

  return numeros;

}
