#include <soma_string.h>

#include "gtest/gtest.h"


TEST (SomaSucesso, DoisMaisDois) {
  char string_entrada[] = "2,2 ";
  ASSERT_EQ (4, soma_string(string_entrada));
}

TEST (SomaSucesso, TresMaisTresMaisTres) {
  char string_entrada[] = "3, 3, 3 ";
  ASSERT_EQ (9, soma_string(string_entrada));
}

TEST (SomaSucesso, OnzeMaisDez) {
  char string_entrada[] = "11   ,   10 ";
  ASSERT_EQ (21, soma_string(string_entrada));
}

TEST (Fail, Letras) {
  char string_entrada[] = "MMMMMMMMMMMMMMMMMM ";
  ASSERT_EQ (0, soma_string(string_entrada));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
