#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list ptr;
  va_start(ptr, format);
  int hflag = 0;
  int lflag = 0;
  int Lflag = 0;
  s21_size_t accuracy = 0;
  s21_size_t amount = 0;
  int k = 0;
  int minus = 0;
  int plus = 0;
  int probel = 0;
  char g_row[1000] = {0};
  double g_y = 0;
  int flag_e = 0;
  int sharp = 0;
  int nool = 0;
  int once_width = 0;
  int term_nol = 0;
  *str = '\0';
  for (s21_size_t i = 0; i < s21_strlen(format) && !term_nol; i++) {
    if (format[i] == '%' && format[i + 1] != '%') {  // спецификаторы
      while (1) {
        if (format[i] == 'c' || format[i] == 'd' || format[i] == 'i' ||
            format[i] == 'f' || format[i] == 's' || format[i] == 'u' ||
            format[i] == 'e' || format[i] == 'E' || format[i] == 'g' ||
            format[i] == 'G' || format[i] == 'n' || format[i] == 'p' ||
            format[i] == 'o' || format[i] == 'x' || format[i] == 'X') {
          if (format[i] == 'c') {
            char row[1000] = {0};
            char y = va_arg(ptr, int);
            row[0] = y;
            if (row[0] == '\0') {
              term_nol++;
            }
            if (amount > s21_strlen(row)) {
              if (minus) {
                s21_strcat(str, row);
                s21_size_t j = 0;
                for (; j < amount - s21_strlen(row); j++) {
                  s21_strcat(str, " ");
                }
              } else {
                for (s21_size_t j = 0; j < amount - s21_strlen(row); j++) {
                  s21_strcat(str, " ");
                }
                s21_strcat(str, row);
              }
            } else {
              s21_strcat(str, row);
            }
          }

          if (format[i] == 'd' || format[i] == 'i') {
            char row[1000] = {0};

            if (hflag) {
              short int y = va_arg(ptr, int);
              if (nool) {
                if (y < 0) {
                  accuracy = amount - 1;
                } else
                  accuracy = amount;
              }
              if (accuracy == 0 && y == 0 && k == 1) {
              } else
                itoa(y, row, accuracy);
            }
            if (lflag) {
              long int y = va_arg(ptr, long int);
              if (nool) {
                if (y < 0) {
                  accuracy = amount - 1;
                } else
                  accuracy = amount;
              }
              if (accuracy == 0 && y == 0 && k == 1) {
              } else
                itoa(y, row, accuracy);
            }
            if (!hflag && !lflag) {
              int y = va_arg(ptr, int);
              if (nool) {
                if (y < 0) {
                  accuracy = amount - 1;
                } else
                  accuracy = amount;
              }
              if (accuracy == 0 && y == 0 && k == 1) {
              } else
                itoa(y, row, accuracy);
            }
            if (amount > s21_strlen(row)) {
              if (probel && row[0] != '-') {
                s21_strcat(str, " ");
              }
              if (!minus) {
                s21_size_t j = 0;
                if (plus && row[0] != '-') {
                  j = 1;
                }
                for (; j < amount - s21_strlen(row); j++) {
                  s21_strcat(str, " ");
                }
              }
              if (plus && row[0] != '-') {
                s21_strcat(str, "+");
              }

              s21_strcat(str, row);
              if (minus) {
                s21_size_t j = 0;
                if (plus && row[0] != '-') {
                  j = 1;
                }
                for (; j < amount - s21_strlen(row); j++) {
                  s21_strcat(str, " ");
                }
              }
            } else {
              if (probel && row[0] != '-') {
                s21_strcat(str, " ");
              }
              if (plus && row[0] != '-') {
                s21_strcat(str, "+");
              }
              s21_strcat(str, row);
            }
          }

          if (format[i] == 'e' || format[i] == 'E' || format[i] == 'g' ||
              format[i] == 'G') {
            char row[1000] = {0};
            long double y = 0;
            if (Lflag) {
              y = va_arg(ptr, long double);
            } else {
              y = va_arg(ptr, double);
            }

            if (format[i] == 'g' || format[i] == 'G') {
              g_y = y;
            }
            unsigned long long int_y = 0;
            if (y < 0) {  //////////// логика спецификатора
              int_y = -(unsigned long long)y;
            } else {
              int_y = (unsigned long long)y;
            }
            s21_size_t count = 0;
            int flag_m = 0, flag_p = 0;

            if (k == 0) {
              accuracy = 6;
            }
            if (int_y != 0 || y == 0) {
              flag_p++;
              while (int_y >= 1) {
                count++;
                int_y = int_y / 10;
              }
              y = y / pow(10, count - 1);
            } else {
              flag_m++;
              int v_ume = 0;
              if (y < 0) {
                y = -y;
                v_ume++;
              }

              while (y < 0.99999999) {
                count++;
                y = y * 10;
              }

              if (v_ume) {
                y = -y;
              }
            }

            int accuracy1 = accuracy;
            if (g_y < 0) {
              y = -y;
            }
            if ((format[i] == 'g' || format[i] == 'G') &&
                y != 0) {  //спецификатор g--->
              int check = y;
              double check_fraction = y;
              int count = 0;
              int count_null = 0;
              s21_size_t count_for_0_after_point = 0;
              while (check >= 1) {
                count++;
                check = check / 10;
              }
              if (count == 0) {  //вывод значимых чисел при ноль целых->

                while (count_for_0_after_point < accuracy) {
                  check_fraction = check_fraction * 10;
                  count++;
                  if ((int)check_fraction >= 1 ||
                      count_for_0_after_point != 0) {
                    count_for_0_after_point++;
                    if ((int)check_fraction % 10 == 0) {
                      if (!sharp) count_null++;
                    } else {
                      count_null = 0;
                    }
                  }
                }
                accuracy = count - count_null;
              }  //<-
              else {
                if (accuracy != 0) accuracy = accuracy - count;
                while ((count_for_0_after_point < accuracy)) {
                  check_fraction = check_fraction * 10;
                  count_for_0_after_point++;
                  if ((int)check_fraction % 10 == 0) {
                    if (!sharp) count_null++;
                  } else {
                    count_null = 0;
                  }
                }
                if (accuracy != 0) accuracy = accuracy - count_null;
              }
            }
            if (g_y < 0) {
              y = -y;
            }
            ftoa(y, row, accuracy);
            if (accuracy == 0 && sharp) {
              row[s21_strlen(row)] = '.';
            }
            accuracy = accuracy1;
            if (format[i] == 'e' || format[i] == 'g') {
              row[s21_strlen(row)] = 'e';
            } else if (format[i] == 'E' || format[i] == 'G') {
              row[s21_strlen(row)] = 'E';
            }
            if (flag_m) {
              row[s21_strlen(row)] = '-';
            }
            if (flag_p) {
              row[s21_strlen(row)] = '+';
              if (y != 0) count--;
            }

            char degree[100] = {0};
            if (count < 10) {
              itoa(count, degree, 2);
            } else {
              itoa(count, degree, 0);
            }
            s21_strcat(row, degree);
            if (((format[i] == 'g' && count > 4 && flag_m) ||
                 (format[i] == 'g' && count >= accuracy && flag_p) ||
                 (format[i] == 'G' && count > 4 && flag_m) ||
                 (format[i] == 'G' && count >= accuracy && flag_p)) &&
                y != 0) {
              flag_e++;

              for (s21_size_t j = 0; j < s21_strlen(row); j++) {
                g_row[j] = row[j];
              }
            }
            if (format[i] != 'g' && format[i] != 'G') {
              if (amount > s21_strlen(row)) {
                if (probel && row[0] != '-') {
                  s21_strcat(str, " ");
                }
                if (!minus) {
                  s21_size_t j = 0;
                  if (nool && row[0] == '-') {
                    s21_strcat(str, "-");
                    j = 1;
                    row[0] = '0';
                  }
                  if (plus && row[0] != '-') {
                    j = 1;
                  }
                  for (; j < amount - s21_strlen(row); j++) {
                    if (nool)
                      s21_strcat(str, "0");
                    else
                      s21_strcat(str, " ");
                  }
                }
                if (plus && row[0] != '-') {
                  s21_strcat(str, "+");
                }
                s21_strcat(str, row);
                if (minus) {
                  s21_size_t j = 0;
                  if (plus && row[0] != '-') {
                    j = 1;
                  }
                  for (; j < amount - s21_strlen(row); j++) {
                    s21_strcat(str, " ");
                  }
                }
              } else {
                if (probel && row[0] != '-') {
                  s21_strcat(str, " ");
                }
                if (plus && row[0] != '-') {
                  s21_strcat(str, "+");
                }
                s21_strcat(str, row);
              }
            }
          }

          if (format[i] == 'f' ||
              ((format[i] == 'g' || format[i] == 'G') && !flag_e)) {
            char row[1000] = {0};
            long double y = 0;
            if (Lflag) {
              y = va_arg(ptr, long double);
            } else {
              y = va_arg(ptr, double);
            }

            if (format[i] == 'g' || format[i] == 'G') {
              y = g_y;
            }

            if (k == 0) {
              accuracy = 6;
            }
            if (g_y < 0) {
              y = -y;
            }
            if ((format[i] == 'g' || format[i] == 'G') &&
                y != 0) {  //спецификатор g--->
              int check = y;
              double check_fraction = y;
              int count = 0;
              int count_null = 0;
              s21_size_t count_for_0_after_point = 0;
              if (accuracy == 0) {
                accuracy = +1;
              }
              while (check >= 1) {
                count++;
                check = check / 10;
              }
              if (count == 0) {  //вывод значимых чисел при ноль целых->

                while (count_for_0_after_point < accuracy) {
                  check_fraction = check_fraction * 10;
                  count++;
                  if (count_for_0_after_point + 1 == accuracy &&
                      count_for_0_after_point != 0) {
                    check_fraction = round(check_fraction);
                  }
                  if ((int)check_fraction >= 1 ||
                      count_for_0_after_point != 0) {
                    count_for_0_after_point++;
                    if ((int)check_fraction % 10 == 0) {
                      if (!sharp) count_null++;
                    } else {
                      count_null = 0;
                    }
                  }
                }
                if (accuracy != 0) accuracy = count - count_null;
              }  //<-
              else {
                if (accuracy != 0) accuracy = accuracy - count;
                while ((count_for_0_after_point < accuracy)) {
                  check_fraction = check_fraction * 10;
                  count_for_0_after_point++;
                  if ((int)check_fraction % 10 == 0) {
                    if (!sharp) count_null++;
                  } else {
                    count_null = 0;
                  }
                }
                if (accuracy != 0) accuracy = accuracy - count_null;
              }
            }
            if (g_y < 0) {
              y = -y;
            }
            if ((format[i] == 'g' || format[i] == 'G') && y == 0) {
              if (sharp) {
                accuracy = accuracy - 1;
              } else
                accuracy = 0;
            }
            if (sharp && accuracy == 0 && y == 0) accuracy = 1;

            ftoa(y, row, accuracy);
            if (accuracy == 0 && sharp) {
              row[s21_strlen(row)] = '.';
            }
            for (s21_size_t j = 0; j < s21_strlen(row); j++) {
              g_row[j] = row[j];
            }  //

            if (format[i] != 'g' && format[i] != 'G') {  //спецификатор g<---
              if (amount > s21_strlen(row)) {
                if (probel && row[0] != '-') {
                  s21_strcat(str, " ");
                }

                if (!minus) {
                  s21_size_t j = 0;
                  if (plus && row[0] != '-') {
                    j = 1;
                  }
                  s21_size_t strl = s21_strlen(row);
                  if (row[0] == '-' && !nool) {
                    strl = strl;
                  }
                  if (nool && row[0] == '-') {
                    s21_strcat(str, "-");
                    row[0] = '0';
                    j = 1;
                  }

                  for (; j < amount - strl; j++) {
                    if (nool)
                      s21_strcat(str, "0");
                    else
                      s21_strcat(str, " ");
                  }
                }
                if (plus && row[0] != '-') {
                  s21_strcat(str, "+");
                }
                s21_strcat(str, row);
                if (minus) {
                  s21_size_t j = 0;
                  if (plus && row[0] != '-') {
                    j = 1;
                  }
                  for (; j < amount - s21_strlen(row); j++) {
                    s21_strcat(str, " ");
                  }
                }
              } else {
                if (probel && row[0] != '-') {
                  s21_strcat(str, " ");
                }
                if (plus && row[0] != '-') {
                  s21_strcat(str, "+");
                }
                s21_strcat(str, row);
              }
            }
          }

          if (format[i] == 's') {
            char *row = NULL;
            int c = 0;
            int m = 1;
            if (k) {
              int z = s21_strlen(str);
              row = va_arg(ptr, char *);
              if (minus) {
                for (s21_size_t p = 0; p < accuracy; z++, c++, p++) {
                  str[z] = row[c];
                }
                str[z] = '\0';
                if (amount > accuracy) {
                  s21_size_t j = 0;
                  for (; j < amount - accuracy; j++) {
                    s21_strcat(str, " ");
                  }
                } else if (amount == accuracy && amount != 0) {
                  s21_size_t j = 0;
                  for (; j < amount - s21_strlen(row); j++) {
                    s21_strcat(str, " ");
                  }
                }
              } else {
                if (amount > accuracy) {
                  s21_size_t j = 0;

                  for (; j < amount - accuracy; j++) {
                    s21_strcat(str, " ");
                  }
                  z = s21_strlen(str);
                } else if (amount == accuracy && amount != 0) {
                  s21_size_t j = 0;
                  for (; j < amount - s21_strlen(row); j++) {
                    s21_strcat(str, " ");
                  }
                  z = s21_strlen(str);
                }
                for (s21_size_t p = 0; p < accuracy; z++, c++, p++) {
                  str[z] = row[c];
                }
                str[z] = '\0';
              }
            } else {
              int z = s21_strlen(str);
              row = va_arg(ptr, char *);
              if (minus) {
                for (s21_size_t p = 0; p < s21_strlen(row) + m; z++, c++, p++) {
                  str[z] = row[c];
                }
                if (amount > s21_strlen(row)) {
                  s21_size_t j = 0;
                  for (; j < amount - s21_strlen(row); j++) {
                    s21_strcat(str, " ");
                  }
                }
              } else {
                if (amount > s21_strlen(row)) {
                  s21_size_t j = 0;

                  for (; j < amount - s21_strlen(row); j++) {
                    s21_strcat(str, " ");
                  }
                  z = s21_strlen(str);
                }
                for (s21_size_t p = 0; p < s21_strlen(row) + m; z++, c++, p++) {
                  str[z] = row[c];
                }
                str[z] = '\0';
              }
            }
          }

          if (format[i] == 'o') {
            char row[1000] = {};
            int tmp;
            s21_size_t i = 0;
            if (lflag) {
              long int Q = va_arg(ptr, long int);
              if (Q == 0) {
                row[0] = '0';
              }
              while (Q != 0) {
                tmp = Q % 8;
                if (tmp == 0)
                  row[i] = tmp + '0';
                else if (tmp == 1)
                  row[i] = tmp + '0';
                else if (tmp == 2)
                  row[i] = tmp + '0';
                else if (tmp == 3)
                  row[i] = tmp + '0';
                else if (tmp == 4)
                  row[i] = tmp + '0';
                else if (tmp == 5)
                  row[i] = tmp + '0';
                else if (tmp == 6)
                  row[i] = tmp + '0';
                else if (tmp == 7)
                  row[i] = tmp + '0';
                Q /= 8;
                i++;
              }
            }
            if (hflag) {
              short int Q = 0;
              Q = va_arg(ptr, int);
              if (Q == 0) {
                row[0] = '0';
              }
              while (Q > 0) {
                tmp = Q % 8;
                if (tmp == 0)
                  row[i] = tmp + '0';
                else if (tmp == 1)
                  row[i] = tmp + '0';
                else if (tmp == 2)
                  row[i] = tmp + '0';
                else if (tmp == 3)
                  row[i] = tmp + '0';
                else if (tmp == 4)
                  row[i] = tmp + '0';
                else if (tmp == 5)
                  row[i] = tmp + '0';
                else if (tmp == 6)
                  row[i] = tmp + '0';
                else if (tmp == 7)
                  row[i] = tmp + '0';
                Q /= 8;
                i++;
              }
            }
            if (!hflag && !lflag) {
              int Q = va_arg(ptr, int);
              if (Q == 0) {
                row[0] = '0';
              }
              while (Q > 0) {
                tmp = Q % 8;
                if (tmp == 0)
                  row[i] = tmp + '0';
                else if (tmp == 1)
                  row[i] = tmp + '0';
                else if (tmp == 2)
                  row[i] = tmp + '0';
                else if (tmp == 3)
                  row[i] = tmp + '0';
                else if (tmp == 4)
                  row[i] = tmp + '0';
                else if (tmp == 5)
                  row[i] = tmp + '0';
                else if (tmp == 6)
                  row[i] = tmp + '0';
                else if (tmp == 7)
                  row[i] = tmp + '0';
                Q /= 8;
                i++;
              }
            }
            reverse(row);
            char row2[1000] = {};

            //все три флага вместе или точность и ширина отдельно
            if ((accuracy > i && sharp == 1 && amount > i) ||
                (accuracy > i && amount > i)) {
              s21_size_t diff_accuracy = accuracy - i;  //разница точноть
              s21_size_t diff_amount = amount - i;  //разница ширина

              //если точность больше ай, то шарп уже не работает
              //если точность больше ширины, работает только она
              if (diff_accuracy >= diff_amount) {
                for (s21_size_t j = 0; j < diff_accuracy;
                     j++) {  //нули в начало
                  row2[j] = '0';
                }
                for (s21_size_t j = diff_accuracy; j < accuracy;
                     j++) {  //копирую
                  row2[j] = row[j - diff_accuracy];
                }
                s21_strcat(str, row2);
              } else if (diff_amount > diff_accuracy)  //ширина
              {
                if (!minus)  //пробелы слева
                {
                  s21_size_t j = 0;  //сохраняю его потому иногда может не быть
                                     //в начале нулей
                  for (; j < diff_amount; j++) {  //пробелы в начало
                    if (nool == 1) {
                      row2[j] = '0';
                    } else {
                      row2[j] = ' ';
                    }
                  }
                  j -= 1;  //-1 потому что после цикла j увеличивается на 1, хз
                           //почему

                  for (s21_size_t i = 0; i < diff_accuracy;
                       i++) {  //последние элементы row2 меняю на нули
                               // diff_accuracy раз
                    row2[j] = '0';
                    j--;
                  }
                  for (s21_size_t i = diff_amount; i < amount; i++) {  //копирую
                    row2[i] = row[i - diff_amount];
                  }
                  s21_strcat(str, row2);
                } else if (minus) {
                  s21_size_t j = 0, i = 0;  //сохраняю j потому что нужно
                                            //хранить новые адреса для массива

                  //нули вставятся 100%, потому что если вошел сюда, то точность
                  //> ай
                  for (; j < diff_accuracy;
                       j++) {  //ставлю нули в начало для точности
                    row2[j] = '0';
                  }
                  //после цикла j увеличится на 1, это подходит

                  for (; j < accuracy;
                       j++) {  //копирую оставшееся, accuracy потому она хранит
                               //строку с нулями в начале и до конца оригинала
                    row2[j] = row[i];
                    i++;
                  }

                  for (; j < amount;
                       j++) {  //вставляю порбелы, amount потому что он хранит
                               //все до конца строки, включая пробелы
                    row2[j] = ' ';
                  }
                  s21_strcat(str, row2);
                }
              }
            }
            //точность и шарп или отдельно точность
            else if ((accuracy > i && sharp == 1) ||
                     accuracy > i)  //если точность больше ай, то шарп вообще не
                                    //работает
            {
              s21_size_t difference = accuracy - i;  //нахожу разницу

              for (s21_size_t j = 0; j < difference;
                   j++) {  //вставляю в начало нового массива нули
                row2[j] = '0';
              }
              for (s21_size_t j = difference; j < accuracy;
                   j++) {  //копирую дальше
                row2[j] = row[j - difference];
              }
              s21_strcat(str, row2);
            }
            //ширина и шарп или отдельно ширина
            else if ((amount > i && sharp == 1) || amount > i) {
              s21_size_t difference = amount - i;

              if (!minus)  //если минуса нет, пробелы идут слева
              {
                s21_size_t j = 0;
                for (; j < difference; j++) {  //заполняю начало пробелами
                  if (nool == 1) {  //если есть флаг 0, вместо пробелов нули
                    row2[j] = '0';
                  } else {
                    row2[j] = ' ';
                  }
                }
                //если есть шарп, то меняю последний пробел на ноль
                if (sharp == 1) {
                  row2[j - 1] = '0';  //-1 потому что после цикла j
                                      //увеличивается на 1, хз почему
                }

                for (s21_size_t j = difference; j < amount;
                     j++) {  //копирую дальше
                  row2[j] = row[j - difference];
                }
                s21_strcat(str, row2);
              } else if (minus == 1)  //если минус есть, пробелы идут справа
              {
                if (sharp == 1) {
                  row2[0] = '0';
                  i++;
                }
                for (s21_size_t j = 0; j < i; j++) {
                  if (sharp ==
                      1) {  //если есть шарп, оставляю место для нуля в начале
                    row2[j + 1] = row[j];
                  } else {
                    row2[j] = row[j];
                  }
                }

                for (s21_size_t j = i; j < amount; j++) {
                  row2[j] = ' ';
                }
                s21_strcat(str, row2);
              }
            }
            //отдельно шарп
            else if (sharp == 1) {
              row2[0] = '0';
              for (s21_size_t j = 0; j < i; j++) {
                row2[j + 1] = row[j];
              }
              s21_strcat(str, row2);
            }
            //если нет флагов
            else {
              s21_strcat(str, row);
            }
          }

          if (format[i] == 'x') {
            char row[1000] = {};
            int tmp;
            s21_size_t i = 0;

            if (lflag) {
              long int Q = va_arg(ptr, long int);
              if (Q == 0) {
                row[0] = '0';
              }
              while (Q > 0) {
                tmp = Q % 16;
                if (tmp == 0)
                  row[i] = tmp + '0';
                else if (tmp == 1)
                  row[i] = tmp + '0';
                else if (tmp == 2)
                  row[i] = tmp + '0';
                else if (tmp == 3)
                  row[i] = tmp + '0';
                else if (tmp == 4)
                  row[i] = tmp + '0';
                else if (tmp == 5)
                  row[i] = tmp + '0';
                else if (tmp == 6)
                  row[i] = tmp + '0';
                else if (tmp == 7)
                  row[i] = tmp + '0';
                else if (tmp == 8)
                  row[i] = tmp + '0';
                else if (tmp == 9)
                  row[i] = tmp + '0';
                else if (tmp == 10)
                  row[i] = 'a';
                else if (tmp == 11)
                  row[i] = 'b';
                else if (tmp == 12)
                  row[i] = 'c';
                else if (tmp == 13)
                  row[i] = 'd';
                else if (tmp == 14)
                  row[i] = 'e';
                else if (tmp == 15)
                  row[i] = 'f';
                else if (tmp == 16) {
                  row[i] = 10 + '0';
                }

                Q /= 16;
                i++;
              }
            }

            if (hflag) {
              short int Q = va_arg(ptr, int);
              if (Q == 0) {
                row[0] = '0';
              }
              while (Q > 0) {
                tmp = Q % 16;
                if (tmp == 0)
                  row[i] = tmp + '0';
                else if (tmp == 1)
                  row[i] = tmp + '0';
                else if (tmp == 2)
                  row[i] = tmp + '0';
                else if (tmp == 3)
                  row[i] = tmp + '0';
                else if (tmp == 4)
                  row[i] = tmp + '0';
                else if (tmp == 5)
                  row[i] = tmp + '0';
                else if (tmp == 6)
                  row[i] = tmp + '0';
                else if (tmp == 7)
                  row[i] = tmp + '0';
                else if (tmp == 8)
                  row[i] = tmp + '0';
                else if (tmp == 9)
                  row[i] = tmp + '0';
                else if (tmp == 10)
                  row[i] = 'a';
                else if (tmp == 11)
                  row[i] = 'b';
                else if (tmp == 12)
                  row[i] = 'c';
                else if (tmp == 13)
                  row[i] = 'd';
                else if (tmp == 14)
                  row[i] = 'e';
                else if (tmp == 15)
                  row[i] = 'f';
                else if (tmp == 16) {
                  row[i] = 10 + '0';
                }

                Q /= 16;
                i++;
              }
            }

            if (!hflag && !lflag) {
              int Q = va_arg(ptr, int);
              if (Q == 0) {
                row[0] = '0';
              } else if (Q == INT32_MIN) {
                s21_strcat(row, "00000008");
                i = 8;
              }
              while (Q > 0) {
                tmp = Q % 16;
                if (tmp == 0)
                  row[i] = tmp + '0';
                else if (tmp == 1)
                  row[i] = tmp + '0';
                else if (tmp == 2)
                  row[i] = tmp + '0';
                else if (tmp == 3)
                  row[i] = tmp + '0';
                else if (tmp == 4)
                  row[i] = tmp + '0';
                else if (tmp == 5)
                  row[i] = tmp + '0';
                else if (tmp == 6)
                  row[i] = tmp + '0';
                else if (tmp == 7)
                  row[i] = tmp + '0';
                else if (tmp == 8)
                  row[i] = tmp + '0';
                else if (tmp == 9)
                  row[i] = tmp + '0';
                else if (tmp == 10)
                  row[i] = 'a';
                else if (tmp == 11)
                  row[i] = 'b';
                else if (tmp == 12)
                  row[i] = 'c';
                else if (tmp == 13)
                  row[i] = 'd';
                else if (tmp == 14)
                  row[i] = 'e';
                else if (tmp == 15)
                  row[i] = 'f';
                else if (tmp == 16) {
                  row[i] = 10 + '0';
                }

                Q /= 16;
                i++;
              }
            }
            reverse(row);
            char row2[1000] = {};

            //все три флага вместе или точность и ширина отдельно
            if ((accuracy > i && sharp == 1 && amount > i) ||
                (accuracy > i && amount > i)) {
              s21_size_t diff_accuracy = accuracy - i;  //разница точноть
              s21_size_t diff_amount = amount - i;  //разница ширина

              //если точность больше ширины, работает только она
              if (diff_accuracy >= diff_amount) {
                s21_size_t j = 0;  //сохраняю все движения по новому массиву

                if (sharp) {
                  row2[0] = '0';
                  row2[1] = 'x';
                  j += 2;
                  diff_accuracy += 2;
                  accuracy += 2;
                }

                for (; j < diff_accuracy;
                     j++) {  //нули в начало или после шарпа
                  row2[j] = '0';
                }

                for (; j < accuracy; j++) {  //копирую
                  row2[j] = row[j - diff_accuracy];
                }
                s21_strcat(str, row2);
              }
              //если ширина больше точности, она срабатывает, но если точность
              //больше ай, то она меняет пробелы на нули
              else if (diff_amount > diff_accuracy)  //ширина
              {
                if (!minus)  //пробелы слева
                {
                  s21_size_t j = 0;  //сохраняю его потому иногда может не быть
                                     //в начале нулей

                  //если есть шарп и при этом после замены всех пробелов на нули
                  //останется только один пробел надо будет увелить мамссив на
                  //один, чтобы было место для шарпа(там 2 символа) поэтому я с
                  //самого начала увеличиваю j оставляя место
                  if ((diff_amount - diff_accuracy == 1) &&
                      sharp == 1) {  //если есть
                    j += 1;
                    amount += 1;
                    diff_amount += 1;
                  }

                  for (; j < diff_amount; j++) {  //пробелы в начало
                    if (nool == 1) {
                      row2[j] = '0';
                    } else {
                      row2[j] = ' ';
                    }
                  }
                  j -= 1;  //-1 потому что после цикла j увеличивается на 1, хз
                           //почему

                  for (s21_size_t i = 0; i < diff_accuracy;
                       i++) {  //последние элементы row2 меняю на нули
                               // diff_accuracy раз
                    row2[j] = '0';
                    j--;
                  }

                  if (sharp == 1) {
                    row2[j] = 'x';
                    row2[j - 1] = '0';
                  }

                  for (s21_size_t i = diff_amount; i < amount; i++) {  //копирую
                    row2[i] = row[i - diff_amount];
                  }
                  s21_strcat(str, row2);
                } else if (minus) {
                  s21_size_t j = 0;  //указатель

                  if (sharp) {  //если есть шарп, сразу двигаю указатель и
                                //остальные элементы
                    row2[0] = '0';
                    row2[1] = 'x';
                    j += 2;
                    diff_accuracy += 2;
                    accuracy += 2;
                  }

                  for (; j < diff_accuracy; j++) {  //нули
                    row2[j] = '0';
                  }

                  for (; j < accuracy; j++) {  //копирую
                    row2[j] = row[j - diff_accuracy];
                  }

                  for (; j < amount; j++) {  //пробелы в конце
                    row2[j] = ' ';
                  }

                  s21_strcat(str, row2);
                }
              }
            }
            //ширина и шарп или отдельно ширина
            else if ((amount > i && sharp == 1) || amount > i) {
              s21_size_t difference = amount - i;

              if (!minus)  //если минуса нет, пробелы идут слева
              {
                s21_size_t j = 0;
                for (; j < difference; j++) {  //заполняю начало пробелами
                  if (nool == 1) {  //если есть флаг 0, вместо пробелов нули
                    row2[j] = '0';
                  } else {
                    row2[j] = ' ';
                  }
                }

                //если есть шарп, то меняю последний пробел на ноль
                if (sharp == 1 && row[0] != '0') {
                  if (nool ==
                      1) {  //если есть ноль, то шарп печатается в начале
                    row2[1] = 'x';
                    row2[0] = '0';
                  } else {
                    row2[j - 1] = 'x';  //-1 потому что после цикла j
                                        //увеличивается на 1, хз почему
                    row2[j - 2] = '0';
                  }
                }

                if (row[0] == '0') {
                  j -= 1;
                  row2[j] = '0';
                } else {
                  for (; j < amount; j++) {  //копирую дальше
                    row2[j] = row[j - difference];
                  }
                }
                s21_strcat(str, row2);
              } else if (minus == 1) {
                s21_size_t j = 0;
                if (sharp == 1) {
                  row2[0] = '0';
                  row2[1] = 'x';
                  i += 2;
                  j += 2;
                }

                // j равен 0 или 2, ай равен исходному значению или +2
                for (; j < i; j++) {
                  if (sharp) {
                    row2[j] = row[j - 2];
                  } else {
                    row2[j] = row[j];
                  }
                }

                // j будет равен ай
                for (; j < amount; j++) {
                  row2[j] = ' ';
                }
                s21_strcat(str, row2);
              }
            }
            // //точность и шарп или отдельно точность
            else if ((accuracy > i && sharp == 1) || accuracy > i) {
              s21_size_t difference = accuracy - i;
              s21_size_t j = 0;  //сохраняю j потому что нужно хранить новые
                                 //адреса для массива row2

              if (sharp == 1) {
                row2[0] = '0';
                row2[1] = 'x';
                j = 2;
                difference += 2;
                accuracy += 2;
              }

              for (; j < difference;
                   j++) {  //вставляю в начало нового массива нули
                row2[j] = '0';
              }

              for (; j < accuracy; j++) {
                row2[j] = row[j - difference];
              }
              s21_strcat(str, row2);
            }
            //шарп отдельно
            else if (sharp == 1 && row[i] != '0') {
              row2[0] = '0';
              row2[1] = 'x';

              for (s21_size_t j = 0; j < i; j++) {
                row2[j + 2] = row[j];
              }
              s21_strcat(str, row2);
            }
            //если нет флагов
            else {
              s21_strcat(str, row);
            }
          }

          if (format[i] == 'X') {
            char row[1000] = {};
            int tmp;
            s21_size_t i = 0;

            if (lflag) {
              long int Q = va_arg(ptr, long int);
              if (Q == 0) {
                row[0] = '0';
              }
              if (Q < 0) {
                Q = Q * (-1);
              }
              while (Q > 0) {
                tmp = Q % 16;
                if (tmp == 0)
                  row[i] = tmp + '0';
                else if (tmp == 1)
                  row[i] = tmp + '0';
                else if (tmp == 2)
                  row[i] = tmp + '0';
                else if (tmp == 3)
                  row[i] = tmp + '0';
                else if (tmp == 4)
                  row[i] = tmp + '0';
                else if (tmp == 5)
                  row[i] = tmp + '0';
                else if (tmp == 6)
                  row[i] = tmp + '0';
                else if (tmp == 7)
                  row[i] = tmp + '0';
                else if (tmp == 8)
                  row[i] = tmp + '0';
                else if (tmp == 9)
                  row[i] = tmp + '0';
                else if (tmp == 10)
                  row[i] = 'A';
                else if (tmp == 11)
                  row[i] = 'B';
                else if (tmp == 12)
                  row[i] = 'C';
                else if (tmp == 13)
                  row[i] = 'D';
                else if (tmp == 14)
                  row[i] = 'E';
                else if (tmp == 15)
                  row[i] = 'F';
                else if (tmp == 16) {
                  row[i] = 10 + '0';
                }

                Q /= 16;
                i++;
              }
            }

            if (hflag) {
              short int Q = va_arg(ptr, int);
              if (Q == 0) {
                row[0] = '0';
              }
              if (Q < 0) {
                Q = Q * (-1);
              }
              while (Q > 0) {
                tmp = Q % 16;
                if (tmp == 0)
                  row[i] = tmp + '0';
                else if (tmp == 1)
                  row[i] = tmp + '0';
                else if (tmp == 2)
                  row[i] = tmp + '0';
                else if (tmp == 3)
                  row[i] = tmp + '0';
                else if (tmp == 4)
                  row[i] = tmp + '0';
                else if (tmp == 5)
                  row[i] = tmp + '0';
                else if (tmp == 6)
                  row[i] = tmp + '0';
                else if (tmp == 7)
                  row[i] = tmp + '0';
                else if (tmp == 8)
                  row[i] = tmp + '0';
                else if (tmp == 9)
                  row[i] = tmp + '0';
                else if (tmp == 10)
                  row[i] = 'A';
                else if (tmp == 11)
                  row[i] = 'B';
                else if (tmp == 12)
                  row[i] = 'C';
                else if (tmp == 13)
                  row[i] = 'D';
                else if (tmp == 14)
                  row[i] = 'E';
                else if (tmp == 15)
                  row[i] = 'F';
                else if (tmp == 16) {
                  row[i] = 10 + '0';
                }

                Q /= 16;
                i++;
              }
            }

            if (!hflag && !lflag) {
              int Q = va_arg(ptr, int);
              if (Q == 0) {
                row[0] = '0';
              } else if (Q == INT32_MIN) {
                s21_strcat(row, "00000008");
                i = 8;
              }
              while (Q > 0) {
                tmp = Q % 16;
                if (tmp == 0)
                  row[i] = tmp + '0';
                else if (tmp == 1)
                  row[i] = tmp + '0';
                else if (tmp == 2)
                  row[i] = tmp + '0';
                else if (tmp == 3)
                  row[i] = tmp + '0';
                else if (tmp == 4)
                  row[i] = tmp + '0';
                else if (tmp == 5)
                  row[i] = tmp + '0';
                else if (tmp == 6)
                  row[i] = tmp + '0';
                else if (tmp == 7)
                  row[i] = tmp + '0';
                else if (tmp == 8)
                  row[i] = tmp + '0';
                else if (tmp == 9)
                  row[i] = tmp + '0';
                else if (tmp == 10)
                  row[i] = 'A';
                else if (tmp == 11)
                  row[i] = 'B';
                else if (tmp == 12)
                  row[i] = 'C';
                else if (tmp == 13)
                  row[i] = 'D';
                else if (tmp == 14)
                  row[i] = 'E';
                else if (tmp == 15)
                  row[i] = 'F';
                else if (tmp == 16) {
                  row[i] = 10 + '0';
                }

                Q /= 16;
                i++;
              }
            }
            reverse(row);
            char row2[1000] = {};

            //все три флага вместе или точность и ширина отдельно
            if ((accuracy > i && sharp == 1 && amount > i) ||
                (accuracy > i && amount > i)) {
              s21_size_t diff_accuracy = accuracy - i;  //разница точноть
              s21_size_t diff_amount = amount - i;  //разница ширина

              //если точность больше ширины, работает только она
              if (diff_accuracy >= diff_amount) {
                s21_size_t j = 0;  //сохраняю все движения по новому массиву

                if (sharp) {
                  row2[0] = '0';
                  row2[1] = 'X';
                  j += 2;
                  diff_accuracy += 2;
                  accuracy += 2;
                }

                for (; j < diff_accuracy;
                     j++) {  //нули в начало или после шарпа
                  row2[j] = '0';
                }

                for (; j < accuracy; j++) {  //копирую
                  row2[j] = row[j - diff_accuracy];
                }
                s21_strcat(str, row2);
              }
              //если ширина больше точности, она срабатывает, но если точность
              //больше ай, то она меняет пробелы на нули
              else if (diff_amount > diff_accuracy)  //ширина
              {
                if (!minus)  //пробелы слева
                {
                  s21_size_t j = 0;  //сохраняю его потому иногда может не быть
                                     //в начале нулей

                  //если есть шарп и при этом после замены всех пробелов на нули
                  //останется только один пробел надо будет увелить мамссив на
                  //один, чтобы было место для шарпа(там 2 символа) поэтому я с
                  //самого начала увеличиваю j оставляя место
                  if ((diff_amount - diff_accuracy == 1) &&
                      sharp == 1) {  //если есть
                    j += 1;
                    amount += 1;
                    diff_amount += 1;
                  }

                  for (; j < diff_amount; j++) {  //пробелы в начало
                    if (nool == 1) {
                      row2[j] = '0';
                    } else {
                      row2[j] = ' ';
                    }
                  }
                  j -= 1;  //-1 потому что после цикла j увеличивается на 1, хз
                           //почему

                  for (s21_size_t i = 0; i < diff_accuracy;
                       i++) {  //последние элементы row2 меняю на нули
                               // diff_accuracy раз
                    row2[j] = '0';
                    j--;
                  }

                  if (sharp == 1) {
                    row2[j] = 'X';
                    row2[j - 1] = '0';
                  }

                  for (s21_size_t i = diff_amount; i < amount; i++) {  //копирую
                    row2[i] = row[i - diff_amount];
                  }
                  s21_strcat(str, row2);
                } else if (minus) {
                  s21_size_t j = 0;  //указатель

                  if (sharp) {  //если есть шарп, сразу двигаю указатель и
                                //остальные элементы
                    row2[0] = '0';
                    row2[1] = 'X';
                    j += 2;
                    diff_accuracy += 2;
                    accuracy += 2;
                  }

                  for (; j < diff_accuracy; j++) {  //нули
                    row2[j] = '0';
                  }

                  for (; j < accuracy; j++) {  //копирую
                    row2[j] = row[j - diff_accuracy];
                  }

                  for (; j < amount; j++) {  //пробелы в конце
                    row2[j] = ' ';
                  }

                  s21_strcat(str, row2);
                }
              }
            }
            //ширина и шарп или отдельно ширина
            else if ((amount > i && sharp == 1) || amount > i) {
              s21_size_t difference = amount - i;

              if (!minus)  //если минуса нет, пробелы идут слева
              {
                s21_size_t j = 0;
                for (; j < difference; j++) {  //заполняю начало пробелами
                  if (nool == 1) {  //если есть флаг 0, вместо пробелов нули
                    row2[j] = '0';
                  } else {
                    row2[j] = ' ';
                  }
                }
                //если есть шарп, то меняю последний пробел на ноль
                if (sharp == 1 && row[0] != '0') {
                  if (nool ==
                      1) {  //если есть ноль, то шарп печатается в начале
                    row2[1] = 'X';
                    row2[0] = '0';
                  } else {
                    row2[j - 1] = 'X';  //-1 потому что после цикла j
                                        //увеличивается на 1, хз почему
                    row2[j - 2] = '0';
                  }
                }

                if (row[0] == '0') {
                  j -= 1;
                  row2[j] = '0';
                } else {
                  for (; j < amount; j++) {  //копирую дальше
                    row2[j] = row[j - difference];
                  }
                }

                s21_strcat(str, row2);
              } else if (minus == 1) {
                s21_size_t j = 0;

                //если есть шарп сразу сразу увеличиваю j и i
                if (sharp == 1) {
                  row2[0] = '0';
                  row2[1] = 'X';
                  i += 2;
                  j += 2;
                }

                for (; j < i; j++) {
                  if (sharp) {
                    row2[j] = row[j - 2];
                  } else {
                    row2[j] = row[j];
                  }
                }

                // j будет равен ай
                for (; j < amount; j++) {
                  row2[j] = ' ';
                }
                s21_strcat(str, row2);
              }
            }
            // //точность и шарп или отдельно точность
            else if ((accuracy > i && sharp == 1) || accuracy > i) {
              s21_size_t difference = accuracy - i;
              s21_size_t j = 0;  //сохраняю j потому что нужно хранить новые
                                 //адреса для массива row2

              if (sharp == 1) {
                row2[0] = '0';
                row2[1] = 'X';
                j = 2;
                difference += 2;
                accuracy += 2;
              }

              for (; j < difference;
                   j++) {  //вставляю в начало нового массива нули
                row2[j] = '0';
              }

              for (; j < accuracy; j++) {
                row2[j] = row[j - difference];
              }
              s21_strcat(str, row2);
            }
            //шарп отдельно
            else if (sharp == 1 && row[i] != '0') {
              row2[0] = '0';
              row2[1] = 'X';

              for (s21_size_t j = 0; j < i; j++) {
                row2[j + 2] = row[j];
              }
              s21_strcat(str, row2);
            }
            //если нет флагов
            else {
              s21_strcat(str, row);
            }
          }

          if (format[i] == 'u') {
            char row[1000] = {};
            if (hflag) {
              unsigned short int y = va_arg(ptr, int);
              if (nool) accuracy = amount;
              if (accuracy == 0 && y == 0 && k == 1) {
              } else
                itoa(y, row, accuracy);
            }
            if (lflag) {
              unsigned long int y = va_arg(ptr, long int);
              if (nool) accuracy = amount;
              if (accuracy == 0 && y == 0 && k == 1) {
              } else
                itoa(y, row, accuracy);
            }
            if (!hflag && !lflag) {
              unsigned int y = va_arg(ptr, int);
              if (nool) accuracy = amount;
              if (accuracy == 0 && y == 0 && k == 1) {
              } else
                itoa(y, row, accuracy);
            }
            if (amount > s21_strlen(row)) {
              if (!minus) {
                for (s21_size_t j = 0; j < amount - s21_strlen(row); j++) {
                  s21_strcat(str, " ");
                }
              }

              s21_strcat(str, row);
              if (minus) {
                for (s21_size_t j = 0; j < amount - s21_strlen(row); j++) {
                  s21_strcat(str, " ");
                }
              }
            } else {
              s21_strcat(str, row);
            }
          }

          if (format[i] == 'g' || format[i] == 'G') {
            char row[1000] = {};

            for (s21_size_t j = 0; j < s21_strlen(g_row); j++) {
              row[j] = g_row[j];
            }

            if (amount > s21_strlen(row)) {
              if (probel && row[0] != '-') {
                s21_strcat(str, " ");
              }
              if (!minus) {
                s21_size_t j = 0;
                if (nool && row[0] == '-') {
                  s21_strcat(str, "-");
                  j = 1;
                  row[0] = '0';
                }
                if (plus && row[0] != '-') {
                  j = 1;
                }
                for (; j < amount - s21_strlen(row); j++) {
                  if (nool)
                    s21_strcat(str, "0");
                  else
                    s21_strcat(str, " ");
                }
              }
              if (plus && row[0] != '-') {
                s21_strcat(str, "+");
              }
              s21_strcat(str, row);
              if (minus) {
                s21_size_t j = 0;
                if (plus && row[0] != '-') {
                  j = 1;
                }
                for (; j < amount - s21_strlen(row); j++) {
                  s21_strcat(str, " ");
                }
              }
            } else {
              if (probel && row[0] != '-') {
                s21_strcat(str, " ");
              }
              if (plus && row[0] != '-') {
                s21_strcat(str, "+");
              }
              s21_strcat(str, row);
            }
          }

          if (format[i] == 'n') {
            int *z = va_arg(ptr, int *);
            int j = 0;
            char *p = str;
            while (*p) {
              if (*p != '%') {
                p++;
                j++;
              }
            }
            *z = j;
          }

          if (format[i] == 'p') {
            char row[1000] = {};
            unsigned long long int Q = va_arg(ptr, unsigned long long int);
            int tmp = 0;
            size_t z = 0;
            while (Q > 0) {
              tmp = fmod(Q, 16);
              if (tmp == 0) row[z] = tmp + '0';
              if (tmp == 1) row[z] = tmp + '0';
              if (tmp == 2) row[z] = tmp + '0';
              if (tmp == 3) row[z] = tmp + '0';
              if (tmp == 4) row[z] = tmp + '0';
              if (tmp == 5) row[z] = tmp + '0';
              if (tmp == 6) row[z] = tmp + '0';
              if (tmp == 7) row[z] = tmp + '0';
              if (tmp == 8) row[z] = tmp + '0';
              if (tmp == 9) row[z] = tmp + '0';
              if (tmp == 10) {
                row[z] = 'a';
              }
              if (tmp == 11) {
                row[z] = 'b';
              }
              if (tmp == 12) {
                row[z] = 'c';
              }
              if (tmp == 13) {
                row[z] = 'd';
              }
              if (tmp == 14) {
                row[z] = 'e';
              }
              if (tmp == 15) {
                row[z] = 'f';
              }
              if (tmp == 16) {
                row[z] = 10 + '0';
              }
              Q /= 16;
              z++;
            }
            reverse(row);
            if (amount > s21_strlen(row)) {
              s21_size_t j = 0;
              if (!s21_strlen(row)) {
                for (; j < amount - s21_strlen(row) - 2 - 1; j++) {
                  s21_strcat(str, " ");
                }
                s21_strcat(str, "0x");
                if (!s21_strlen(row)) {
                  s21_strcat(str, "0");
                }
                s21_strcat(str, row);
              } else {
                for (; j < amount - s21_strlen(row) - 2; j++) {
                  s21_strcat(str, " ");
                }
                s21_strcat(str, "0x");
                if (!s21_strlen(row)) {
                  s21_strcat(str, "0");
                }
                s21_strcat(str, row);
              }
            } else {
              s21_strcat(str, "0x");
              if (!s21_strlen(row)) {
                s21_strcat(str, "0");
              }
              s21_strcat(str, row);
            }
          }

          break;
        }
        if (format[i] == 'h') {
          hflag++;
        }
        if (format[i] == 'l') {
          lflag++;
        }
        if (format[i] == 'L') {
          Lflag++;
        }

        if (((format[i] >= 49 && format[i] <= 57) || format[i] == '*') &&
            once_width == 0) {  // ширина
          once_width++;
          if (format[i] != '*') {
            int u = 0;
            while (format[i] >= 48 && format[i] <= 57) {
              u++;
              i++;
            }
            i = i - u;
            int index = 0;
            for (int j = 0; j < u; i++, j++) {
              index = ((int)(format[i]) - 48) * pow(10, u - j - 1);
              amount = amount + index;
            }
            i--;
          } else {
            amount = va_arg(ptr, int);
          }
        }

        if (format[i] == '.') {  // точность

          i += 1;
          if (format[i] != '*') {
            while (format[i] != 'c' && format[i] != 'd' && format[i] != 'i' &&
                   format[i] != 'f' && format[i] != 's' && format[i] != 'u' &&
                   format[i] != 'e' && format[i] != 'E' && format[i] != 'g' &&
                   format[i] != 'G' && format[i] != 'n' && format[i] != 'l' &&
                   format[i] != 'h' && format[i] != 'L' && format[i] != 'p' &&
                   format[i] != 'o' && format[i] != 'x' && format[i] != 'X') {
              k++;
              i++;
            }
            if (k == 0) {
              accuracy = 0;
            }
            i = i - k;
            int index = 0;
            for (int j = 0; j < k; j++, i++) {
              index = ((int)(format[i]) - 48) * pow(10, k - j - 1);
              accuracy = accuracy + index;
            }
            i--;

          }

          else {
            accuracy = va_arg(ptr, int);
          }
          k = 1;
        }

        if (format[i] == ' ' || format[i] == '-' || format[i] == '+' ||
            format[i] == '#' || format[i] == '0' ||
            format[i] == '%') {  // флаги

          if (format[i] == '-') {
            minus++;
          }
          if (format[i] == '+') {
            plus++;
          }
          if (format[i] == '#') {
            sharp++;
          }
          if (format[i] == '0' && ((format[i - 1] < 48 || format[i - 1] > 59) &&
                                   format[i] != '.')) {
            nool++;
          }
          if (format[i] == ' ' && !plus) {
            probel++;
          }
        }
        i++;
      }
      hflag = 0, lflag = 0, Lflag = 0, accuracy = 0, amount = 0, minus = 0,
      plus = 0, probel = 0, flag_e = 0, g_y = 0, k = 0, g_y = 0, sharp = 0,
      nool = 0, once_width = 0;
      s21_size_t j1 = s21_strlen(g_row);
      for (s21_size_t j = 0; j < j1; j++) {
        g_row[j] = '\0';
      }
    } else if (format[i] == '%' && format[i] == '%') {
      char *row = (char *)format;
      char arr[100] = {0};
      char arr_1[100] = {0};
      char arr_2[100] = {0};
      s21_size_t z = 0;
      for (s21_size_t p = 0; p < s21_strlen(row); p++) {
        if (row[p] == '%') {
          arr_1[p - p + z] = '%';
        }
        if (row[p] == '%') {
          z++;
        }
      }
      s21_strcat(arr, arr_1);
      for (s21_size_t p = 0; p < s21_strlen(arr) / 2; p++) {
        arr_2[p] = '%';
      }
      s21_strcat(str, arr_2);
      break;
    } else {
      char row[100] = {0};
      row[0] = format[i];
      s21_strcat(str, row);
    }
  }
  va_end(ptr);
  return s21_strlen(str);
}

int itoa(long long int n, char s[], int prepoint) {
  int i;

  long long int sign;

  if ((sign = n) < 0) {
    n = -n;
  }

  i = 0;

  do {
    s[i++] = n % 10 + '0';

  } while ((n /= 10) > 0);

  for (; i < prepoint; i++) {
    s[i] = '0';
  }

  if (sign < 0 || prepoint == -1)
    s[i++] = '-';

  else {
    if (prepoint == -1) s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);

  return i;
}

void reverse(char s[]) {
  int i, j;
  char c;

  for (i = 0, j = s21_strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void ftoa(double n, char *res, int afterpoint) {
  int posle = 0, sign = 0, flag = 0;
  long long int test = n;
  long long int ipart = n;
  double fpart = n - (double)ipart;
  if (fpart < 0) {
    fpart *= (-1);
  }
  if (ipart == 0 && n < 0) {
    sign = -1;
  }

  if (afterpoint != 0) {
    while (test != n) {
      posle++;
      if (posle != afterpoint) {
        n *= 10;
        test = (int)n;
      } else {
        break;
      }
    }
    int i = itoa(ipart, res, sign);
    res[i] = '.';
    if (fpart == 0) {  // не трогать
      fpart = 0.1;     // не трогать
      flag = 1;        // не трогать
    }                  // не трогать
    fpart = fpart * pow(10, afterpoint);
    fpart = round(fpart);
    itoa(fpart, res + i + 1,
         afterpoint);  // не трогать( скажи,что будешь делать)
    if (flag) {          // не трогать
      res[i + 1] = '0';  // не трогать
    }                    // не трогать
  } else if (afterpoint == 0) {
    if (ipart >= 1 && fpart >= 0.5) {
      ipart += 1;
    } else if (ipart < 1 && fpart > 0.5) {
      ipart = ipart + 1;
    } else {
      ipart = ipart;
    }
    itoa(ipart, res, sign);
  }
}
