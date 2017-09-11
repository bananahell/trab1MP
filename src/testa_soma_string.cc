#include <soma_string.h>

#include "gtest/gtest.h"


TEST (Sucesso, DoisMaisDois) {
  char string_entrada[] = "2,2\n";
  ASSERT_EQ (4, soma_string(string_entrada));
}

TEST (Sucesso, TresMaisTresMaisTres) {
  char string_entrada[] = "3,3,3\n";
  ASSERT_EQ (9, soma_string(string_entrada));
}

TEST (Sucesso, OnzeMaisDez) {
  char string_entrada[] = "11,10\n";
  ASSERT_EQ (21, soma_string(string_entrada));
}

TEST (Sucesso, Quatro) {
  char string_entrada[] = "4\n";
  ASSERT_EQ (4, soma_string(string_entrada));
}

TEST (Sucesso, Zero) {
  char string_entrada[] = "0\n";
  ASSERT_EQ (0, soma_string(string_entrada));
}

TEST (Sucesso, Vazio) {
  char string_entrada[] = "\n";
  ASSERT_EQ (0, soma_string(string_entrada));
}

TEST (Falha, Letras) {
  char string_entrada[] = "MMMMMMMMMMMMMMMMMM\n";
  ASSERT_EQ (-1, soma_string(string_entrada));
}

TEST (Falha, CaracterErrado) {
  char string_entrada[] = "1.2\n";
  ASSERT_EQ (-1, soma_string(string_entrada));
}

TEST (Falha, ComecaCaracter) {
  char string_entrada[] = ".1,2\n";
  ASSERT_EQ (-1, soma_string(string_entrada));
}

TEST (Falha, ComecaDelimitador) {
  char string_entrada[] = ",2,3\n";
  ASSERT_EQ (-1, soma_string(string_entrada));
}

TEST (Falha, TerminaDelimitador) {
  char string_entrada[] = "1,2,\n";
  ASSERT_EQ (-1, soma_string(string_entrada));
}

TEST (Falha, SoDelimitador) {
  char string_entrada[] = ",\n";
  ASSERT_EQ (-1, soma_string(string_entrada));
}

TEST (Falha, UmCaracterNaoQuebraLinha) {
  char string_entrada[] = "*";
  ASSERT_EQ (-1, soma_string(string_entrada));
}

TEST (Falha, NaoTerminaQuebraDeLinha) {
  char string_entrada[] = "1,2";
  ASSERT_EQ (-1, soma_string(string_entrada));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
