/**
 * @file testa_soma_string_stdin.cpp
 * 
 * @brief Arquivo que usa a função soma_string em arquivos.
 * O arquivo de entrada é o entrada.txt e o de saída é o saida.txt
 *
 * @author Pedro Nogueira - 14/0065032
 *
 */

#include <string_soma.hpp>


int main() {
  char *string_entrada = (char *)malloc(sizeof(char));
  if (string_entrada == NULL) {
    printf("\n - Ocorreu algum problema na alocação dinâmica de memória! -\n");
    return 0;
  }
  char *string_aux;
  char caracter;
  int tamanho = 1;
  while (scanf("%c", &caracter) != EOF) {
    string_entrada[tamanho-1] = caracter;
    string_aux = (char *)realloc(string_entrada, (tamanho + 1) * sizeof(char));
    if (string_aux == NULL) {
      printf("\n - Ocorreu algum problema");
      printf(" na alocação dinâmica de memória! -\n");
      free(string_entrada);
      return 0;
    }
    string_entrada = string_aux;
    ++tamanho;
  }
  string_entrada[tamanho - 1] = '\0';
  int soma = soma_string(string_entrada);
  printf("%d", soma);
  return 0; // ./testa_soma_string_stdin <entrada.txt >saida.txt
}
