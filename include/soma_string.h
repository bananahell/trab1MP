#include <cstdlib>
#include <cstring>


/**
 * @brief Soma numeros em uma string.
 * Funcao que pega os numeros separados por um separador designado e os soma.
 * 
 * @param string_entrada - String com os numeros a serem somados.
 * 
 * @return total - A soma total dos numeros da string.
 */
int soma_string(char* string_entrada);

/**
 * @brief Isola os numeros em uma string.
 * Funcao que separa os numeros dentro de uma string.
 * 
 * @param string_entrada - String com os numeros a serem somados.
 * 
 * @return numeros - Numeros que estao dentro da string passada.
 */
int* string_para_numero(char* string_entrada);

/**
 * @brief Checa se a string e valida.
 * Checa a validade da string passada conforme a especificacao:
 * - numero delimitador numero
 * - se tem algum caracter intruso
 * - se comeca ou termina errado
 * 
 * @param string_entrada - String com os numeros a serem somados.
 * 
 * @return bool - Verdadeiro se a string for valida.
 */
bool checa_string(char* string_entrada);
