#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  int flag = 0;

  static s21_size_t count = 0;
  static char *p_str = S21_NULL;

  if (str) {
    p_str = str;
    count = 0;
  } else {
    if (p_str) {
      p_str += count;
      count = 0;
    } else {
      flag++;
    }
  }

  if (!flag) {
    p_str += s21_strspn(p_str, delim);
    s21_size_t len_p_str = s21_strlen(p_str);
    s21_size_t len_delim = s21_strlen(delim);

    if (!s21_strcspn(p_str, delim)) {
      p_str = NULL;
    } else {
      for (s21_size_t i = 0; (i < len_p_str) && !flag; i++) {
        for (s21_size_t j = 0; (j < len_delim) && !flag; j++) {
          if (p_str[i] == delim[j]) {
            p_str[i] = '\0';
            count = i + 1;
            flag++;
          }
        }
      }
      if (!flag) {
        count += len_p_str;
      }
    }
  }
  return p_str;
}
