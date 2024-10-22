#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t n = s21_strlen(needle);
  while (*haystack) {
    if (s21_memcmp(haystack, needle, n) == 0) {
      return (char *)haystack;
    }
    haystack++;
  }
  return 0;
}