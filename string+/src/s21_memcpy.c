#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *ds = (unsigned char *)dest;
  unsigned char *sr = (unsigned char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    ds[i] = sr[i];
  }
  return ds;
}
