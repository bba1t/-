#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  s21_size_t i = 0;
  while (i < s21_strlen(src) || i < s21_strlen(dest)) {
    dest[i] = src[i];
    i++;
  }
  return dest;
}