#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *sr = (unsigned char *)str;
  s21_size_t i = 0;
  while (i < n) {
    if (sr[i] == (char)c) {
      return &sr[i];
    }
    i++;
  }
  return S21_NULL;
}
