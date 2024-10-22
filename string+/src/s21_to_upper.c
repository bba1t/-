#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *res = S21_NULL;
  if (str != S21_NULL) {
    res = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
    for (s21_size_t i = 0; str[i] != '\0'; i++) {
      if (str[i] >= 97 && str[i] <= 122) {
        res[i] = str[i] - 32;
      } else {
        res[i] = str[i];
      }
    }
  }
  return res;
  // free(res);
}