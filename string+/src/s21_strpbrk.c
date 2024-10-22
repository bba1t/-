#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *sr_1 = (char *)str1;
  char *sr_2 = (char *)str2;
  for (s21_size_t i = 0; i < s21_strlen(sr_1); i++) {
    for (s21_size_t j = 0; j < s21_strlen(sr_2); j++) {
      if (sr_1[i] == sr_2[j]) {
        return sr_1 + i;
      }
    }
  }
  return S21_NULL;
}