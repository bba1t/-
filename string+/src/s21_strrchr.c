#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *sr = (char *)str;
  s21_size_t i = s21_strlen(sr);
  while (i > 0 || c == '\0') {
    if (sr[i] == (char)c) {
      return &sr[i];
    }
    i--;
  }
  return S21_NULL;
}
