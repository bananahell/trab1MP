/**
 * @file string_soma.hpp
 * 
 * @brief Arquivo com a declaração das funções que transformam string em número.
 *
 * @author Pedro Nogueira - 14/0065032
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>


/**
 * @brief Soma numeros em uma string.
 * Função que pega os números separados por um separador designado e os soma.
 * 
 * @param string_entrada - String com os números a serem somados.
 * 
 * @return total - A soma total dos números da string.
 */
int soma_string(char* string_entrada);

/**
 * @brief Isola os números em uma string.
 * Função que separa os números dentro de uma string.
 * 
 * @param string_entrada - String com os números a serem somados.
 * 
 * @return numeros - Números que estão dentro da string passada.
 */
int* string_para_numero(char* string_entrada);

/**
 * @brief Checa se a string é válida.
 * Checa a validade da string passada conforme a especificação:
 * - número delimitador número
 * - se tem algum caracter intruso
 * - se comeca ou termina errado
 * - etc.
 * 
 * @param string_entrada - String com os números a serem somados.
 * 
 * @return bool - Verdadeiro se a string for válida.
 */
bool checa_string(char* string_entrada);

/**
 * @brief Valida os delimitadores passados
 * Se foi passado delimitador na string, essa função valida a suposta linha.
 * 
 * @param string_entrada - String com os números a serem somados.
 * 
 * @return delimitadores - Array com os delimitadores encontrados (primeiro
 *                         elemento é o índice indicando a quantidade de
 *                         elementos.
 */
char** checa_delimitadores(char* string_entrada);
