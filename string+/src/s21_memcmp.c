#include <string.h>

#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *sr_1 = (unsigned char *)str1;
  unsigned char *sr_2 = (unsigned char *)str2;
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