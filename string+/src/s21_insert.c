#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *arr = S21_NULL;
  if (src == S21_NULL || !s21_strlen(src) || s21_strlen(src) < start_index) {
    arr = S21_NULL;
  } else if (str == S21_NULL || !s21_strlen(str)) {
    arr = S21_NULL;
  } else {
    arr = (char *)calloc(s21_strlen(src) + s21_strlen(str) + 1, sizeof(char));
    for (s21_size_t i = 0; i < s21_strlen(src) + s21_strlen(str); i++) {
      if (i < start_index) {
        arr[i] = src[i];
      } else if (i < start_index + s21_strlen(str)) {
        arr[i] = str[i - start_index];
      } else {
        arr[i] = src[i - s21_strlen(str)];
      }
    }
  }
  return arr;
  // free(arr);
}