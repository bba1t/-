#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i_1 = 0;
  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    int log = 0;
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        log = 1;
        break;
      }
    }
    if (!log) {
      i_1++;
    } else {
      break;
    }
  }
  return i_1;
}