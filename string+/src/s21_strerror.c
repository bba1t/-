#include "s21_string.h"

char* s21_strerror(int errnum) {
  char* ERRORS[] = ERR_LIST;
  char* error = S21_NULL;
  static char buf[100] = {0};
  if (errnum >= 0 && errnum < N) {
    error = ERRORS[errnum];
  } else {
    char* undef = "Unknown error ";
    s21_sprintf(buf, "%s%d", undef, errnum);
  }
  return error == S21_NULL ? buf : error;
}