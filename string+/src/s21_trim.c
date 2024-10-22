#include "s21_string.h"

s21_size_t start_index(const char *src, const char *trim_chars);
s21_size_t end_index(const char *src, const char *trim_chars);

void *s21_trim(const char *src, const char *trim_chars) {
  char *arr = S21_NULL;
  if (trim_chars == S21_NULL || !s21_strlen(trim_chars)) {
    trim_chars = " ";
  }
  if (src == S21_NULL) {
    arr = S21_NULL;
  } else {
    arr = (char *)calloc(s21_strlen(src) + 1, sizeof(char));
    s21_size_t i = 0;
    s21_size_t k = 0;
    for (i = 0, k = 0; i < s21_strlen(src); i++) {
      int log = 0;
      for (s21_size_t j = 0; j < s21_strlen(trim_chars); j++) {
        if (i < start_index(src, trim_chars) ||
            i > end_index(src, trim_chars)) {
          if (src[i] == trim_chars[j]) {
            log = 1;
          }
        }
      }
      if (log) {
        continue;
      } else {
        arr[k++] = src[i];
      }
    }
  }
  return arr;
  // free(arr);
}

s21_size_t start_index(const char *src, const char *trim_chars) {
  int start_index = 0;
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    int log = 0;
    for (s21_size_t j = 0; j < s21_strlen(trim_chars); j++) {
      if (src[i] == trim_chars[j]) {
        log = 1;
      }
    }
    if (log) {
      start_index++;
    } else {
      break;
    }
  }
  return start_index;
}

s21_size_t end_index(const char *src, const char *trim_chars) {
  int end_index = 0;
  for (s21_size_t i = s21_strlen(src) - 1; i > 0; i--) {
    int log = 0;
    for (s21_size_t j = 0; j < s21_strlen(trim_chars); j++) {
      if (src[i] == trim_chars[j]) {
        log = 1;
      }
    }
    if (log != 1) {
      end_index = i;
      break;
    }
  }
  return end_index;
}
