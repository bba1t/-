#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *sr = (char *)str;
  s21_size_t i = 0;
  while (i < s21_strlen(sr) || c == '\0') {
    if (sr[i] == (char)c) {
      return &sr[i];
    }
    i++;
  }
  return S21_NULL;
}