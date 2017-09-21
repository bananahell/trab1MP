/**
 * @file testa_string_soma.cpp
 * 
 * @brief Arquivo com os testes em gtest da função string_soma. Cobertura está em 78.44%.
 *
 * @author Pedro Nogueira - 14/0065032
 *
 */

#include <string_soma.hpp>

#include "gtest/gtest.h"


TEST(SucessoSemDelimitador, DoisMaisDois) {
  char string_entrada[] = "2,2\n";

  ASSERT_EQ(4, soma_string(string_entrada));
}

TEST(SucessoSemDelimitador, TresMaisTresMaisTres) {
  char string_entrada[] = "3,3,3\n";

  ASSERT_EQ(9, soma_string(string_entrada));
}

TEST(SucessoSemDelimitador, OnzeMaisDez) {
  char string_entrada[] = "11,10\n";

  ASSERT_EQ(21, soma_string(string_entrada));
}

TEST(SucessoSemDelimitador, Quatro) {
  char string_entrada[] = "4\n";

  ASSERT_EQ(4, soma_string(string_entrada));
}

TEST(SucessoSemDelimitador, Zero) {
  char string_entrada[] = "0\n";

  ASSERT_EQ(0, soma_string(string_entrada));
}

TEST(SucessoSemDelimitador, Vazio) {
  char string_entrada[] = "\n";

  ASSERT_EQ(0, soma_string(string_entrada));
}

TEST(SucessoComDelimitador, UmDelimitador) {
  char string_entrada[] = "//[;]\n3;7\n";

  ASSERT_EQ(10, soma_string(string_entrada));
}

TEST(SucessoComDelimitador, DoisDelimitadores) {
  char string_entrada[] = "//[**][$%]\n3**7$%10\n";

  ASSERT_EQ(20, soma_string(string_entrada));
}

TEST(SucessoSemDelimitador, NumeroMaiorQueMil) {
  char string_entrada[] = "//[br][hue]\n1200hue300br10000\n";

  ASSERT_EQ(300, soma_string(string_entrada));
}

TEST(FalhaSemDelimitador, Letras) {
  char string_entrada[] = "MMMMMMMMMMMMMMMMMM\n";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

TEST(FalhaSemDelimitador, MuitosNumerosNaLinha) {
  char string_entrada[] = "1,2,3,4\n";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

TEST(FalhaSemDelimitador, CaracterErrado) {
  char string_entrada[] = "1.2\n";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

TEST(FalhaSemDelimitador, ComecaCaracter) {
  char string_entrada[] = ".1,2\n";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

TEST(FalhaSemDelimitador, ComecaDelimitador) {
  char string_entrada[] = ",2,3\n";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

TEST(FalhaSemDelimitador, TerminaDelimitador) {
  char string_entrada[] = "1,2,\n";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

TEST(FalhaSemDelimitador, SoDelimitador) {
  char string_entrada[] = ",\n";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

TEST(FalhaSemDelimitador, UmCaracterNaoQuebraLinha) {
  char string_entrada[] = "*";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

TEST(FalhaSemDelimitador, NaoTerminaQuebraDeLinha) {
  char string_entrada[] = "1,2";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

TEST(FalhaComDelimitador, DelimitadorVazio) {
  char string_entrada[] = "//[]\n1,2";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

TEST(FalhaComDelimitador, SegundoDelimitadorVazio) {
  char string_entrada[] = "//[#][]\n1,2";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

TEST(FalhaComDelimitador, DelimitadoresNaoTerminamNaQuebraDeLinha) {
  char string_entrada[] = "//[#][((]\nui1,2";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

TEST(FalhaComDelimitador, CaracterIntrusoUmDelimitadorAntes) {
  char string_entrada[] = "//*[#]\n1;2";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

TEST(FalhaComDelimitador, CaracterIntrusoUmDelimitadorDepois) {
  char string_entrada[] = "//[#]#\n1,2";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

TEST(FalhaComDelimitador, DelimitadoresNaoEncerram) {
  char string_entrada[] = "//[#]1#2";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

TEST(FalhaComDelimitador, SoDelimitadores) {
  char string_entrada[] = "//[#]\n";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

TEST(FalhaComDelimitador, SoDelimitadoresSemQuebraDeLinha) {
  char string_entrada[] = "//[#]";

  ASSERT_EQ(-1, soma_string(string_entrada));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
