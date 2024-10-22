#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  char *sr_1 = (char *)str1;
  char *sr_2 = (char *)str2;
  s21_size_t i = 0;
  int c = 0;
  while (i < n) {
    if (sr_1[i] != sr_2[i]) {
      c = sr_1[i] - sr_2[i];
      break;
    }
    i++;
  }
  return c;
}