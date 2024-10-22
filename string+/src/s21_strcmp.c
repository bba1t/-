#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  char *sr_1 = (char *)str1;
  char *sr_2 = (char *)str2;
  s21_size_t i = 0;
  int c = 0;
  while (sr_1[i] == sr_2[i] && sr_1[i] != '\0') {
    i++;
  }
  c = sr_1[i] - sr_2[i];
  return c;
}