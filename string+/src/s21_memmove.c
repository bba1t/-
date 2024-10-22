#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *res = (char *)calloc(n, sizeof(char));
  s21_memcpy(res, src, n);
  s21_memcpy(dest, res, n);
  free(res);
  return dest;
}