# Trab1MP

Trabalho 1  

Trabalho de Métodos de Programação  
14/0065032 - Pedro Nogueira  
UnB  

## Arquivos

### makefile

  Dentro do makefile, as variáveis headers, mainObject e objects devem receber o nome dos headers, o nome do arquivo com a main e os objetos gerados pelos programas.  

   * make help - Mostra os comandos make que podem ser feitos  
   * make clean - Apaga os .o's localizados em src/obj  
   * make - Compila o programa  
   * make execute - Executa o programa já compilado  

### lib, include e src

  Organização que o makefile entende.  

   * lib - Recebe bibliotecas importadas  
   * include - Onde vão os headers (nesse caso, .hpp's)  
   * src - Onde vai o código (.cpp's) e os objetos (.o's, na pasta obj)  

### src/obj/[arquivo].gcno

  Cobertura de testes que o gcov detecta.  

## Como rodar

  Entre no diretório onde o makefile está e execute os comandos indicados no makefile (mande  - make help - no terminal).  

## Testes

  Os testes foram rodados com o gtest e chegaram a uma cobertura de 77.63% do código, mas as linhas que os testes não cobriram foram todas verificações de alocação de memória.  

### Testes de sucesso sem delimitadores a mais

  Todos os casos em que o programa rodaria uma string com sucesso e retornaria a soma dos números contidos nela.  

### Testes de falha sem delimitadores a mais

  Todos os casos em que o programa rodaria uma string com falha e retornaria -1.  

   * Letras - String só com letras.  
   * MuitosNumerosNaLinha - Mais que 3 números em alguma linha.  
   * CaracterErrado - Com algum caracter não esperado.  
   * ComecaCaracter - Começando com caracter.  
   * ComecaDelimitador - Começando com o caracter de delimitador padrão.  
   * TerminaDelimitador - Terminando com o delimitador padrão.  
   * SoDelimitador - Só tendo o delimitador na string.  
   * UmCaracterNaoQuebraLinha - Só tendo um número, mas não quebrando linha no final.  
   * NaoTerminaQuebraDeLinha - Não terminando com quebra de linha.  

### Testes de sucesso com delimitadores a mais

  Todos os casos em que o programa rodaria uma string com mais delimitadores indicados com sucesso e retornaria a soma dos números contidos nela.  

### Testes de falha com delimitadores a mais

  Todos os casos em que o programa rodaria uma string com mais delimitadores indicados com falha e retornaria -1.  

   * DelimitadorVazio - O delimitador foi passado vazio.  
   * SegundoDelimitadorVazio - O segundo delimitador foi passado vazio.  
   * DelimitadoresNaoTerminamNaQuebraDeLinha - A lista de delimitadores não termina em quebra de linha.  
   * CaracterIntrusoUmDelimitadorAntes - Caracter intruso na lista de delimitadores, antes dos delimitadores.  
   * CaracterIntrusoUmDelimitadorDepois - Caracter intruso na lista de delimitadores, no meio dos delimitadores.  
   * DelimitadoresNaoEncerram - Lista de delimitadores não termina com quebra de linha.  
   * SoDelimitadores - Só tem a lista de delimitadores.  
   * SoDelimitadoresSemQuebraDeLinha - Só tem a lista de delimitadores, ainda mais sem quebra de linha.  