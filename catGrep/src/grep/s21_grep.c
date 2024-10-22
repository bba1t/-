#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Options {
  int e;
  int v;
  int i;
  int n;
  int l;
  int c;
  int s;
  int h;
  int f;
} opt;

void parser(int argc, char *argv[], opt *options, char pattern[],
            int *count_files, int *count_optind);
void reader(char *argv[], opt *options, char pattern[], int count_files,
            int count_optind);

int main(int argc, char *argv[]) {
  int count_files = 0;
  int count_optind = 0;
  int QWE = 0;

  char pattern[1024];
  opt options = {0};

  parser(argc, argv, &options, pattern, &count_files, &count_optind);

  if (options.e || options.f) {
    QWE = argc;
  } else {
    QWE = argc - 1;
  }

  while (optind < QWE) {
    reader(argv, &options, pattern, count_files, count_optind);
    optind++;
  }
  return 0;
}

void parser(int argc, char *argv[], opt *options, char pattern[],
            int *count_files, int *count_optind) {
  int opt = 0;
  while ((opt = getopt_long(argc, argv, "e:vinlcshf:", NULL, NULL)) != -1) {
    switch (opt) {
      case 'v': {
        options->v = 1;
        break;
      }
      case 'i': {
        options->i = 1;
        break;
      }
      case 'n': {
        options->n = 1;
        break;
      }
      case 'l': {
        options->l = 1;
        break;
      }
      case 'c': {
        options->c = 1;
        break;
      }
      case 's': {
        options->s = 1;
        break;
      }
      case 'h': {
        options->h = 1;
        break;
      }
      case 'e': {
        options->e = 1;
        strcat(pattern, optarg);
        strcat(pattern, "|");
        break;
      }
      case 'f': {
        options->f = 1;
        size_t l;
        char *tmp = NULL;

        FILE *f = fopen(optarg, "r");
        while (getline(&tmp, &l, f) != EOF) {
          strcat(pattern, tmp);
          if (pattern[strlen(pattern) - 1] == '\n') {
            pattern[strlen(pattern) - 1] = '\0';
          }
          strcat(pattern, "|");
        }

        break;
      }
      default:
        fprintf(stderr, "usage");

        pattern[strlen(pattern) - 1] = '\0';
    }
  }

  if (options->e || options->f) {
    *count_files = argc - optind;
  } else {
    *count_files = argc - optind - 1;
  }

  *count_optind = optind;
}

void reader(char *argv[], opt *options, char pattern[], int count_files,
            int count_optind) {
  char *tmp_line = NULL;  //строка для считывания с файла, замена simvol
  size_t len = 0;   //размер для гетлайна
  int success = 1;  //для regexec
  regex_t re;
  int compare = REG_NOMATCH;  //для -v
  int count_str = 1;          //для -n
  int c_flag = 0;
  int c2_flag = 0;
  int e_flag = 0;
  int v_flag = 0;
  FILE *fp;

  if (options->e || options->f) {
    fp = fopen(argv[optind], "r");
  } else {
    sprintf(pattern, "%s", argv[count_optind]);
    fp = fopen(argv[optind + 1], "r");
  }

  if (fp) {
    if (options->i) {
      regcomp(&re, pattern, REG_ICASE);
    } else {
      regcomp(&re, pattern, REG_EXTENDED);
    }

    while (getline(&tmp_line, &len, fp) != EOF) {
      if (tmp_line) {
        success = regexec(&re, tmp_line, 0, NULL, 0);

        if (options->c || options->l) {
          if (!options->v && !options->e) {
            e_flag = 1;
          }

          if (options->c) {
            if (success == REG_NOMATCH && options->v) {
              c_flag++;
            } else if (success == 0 && (options->e || e_flag == 1)) {
              c2_flag++;
            }
          }

          else if (options->l) {
            if ((success == REG_NOMATCH && options->v) ||
                (success == 0 && e_flag == 1)) {
              if (options->e) {
                printf("%s\n", argv[optind]);
              } else {
                printf("%s\n", argv[optind + 1]);
              }
              break;
            } else if (success == 0 && (options->e || options->f)) {
              printf("%s\n", argv[optind]);
              break;
            }
          }

        }

        else {
          if (options->v) {
            v_flag = 1;
            if (success == compare) {
              if (count_files > 1) {
                if (options->h) {
                  if (v_flag == 1 || options->f) {
                    if (options->n) {
                      printf("%d:", count_str);
                    }

                    printf("%s", tmp_line);
                    if (tmp_line[strlen(tmp_line) - 1] != '\n') {
                      printf("\n");
                    }
                  }
                }

                else {
                  if (options->e || options->f) {
                    printf("%s:", argv[optind]);
                  } else {
                    printf("%s:", argv[optind + 1]);
                  }

                  if (options->n) {
                    printf("%d:", count_str);
                  }

                  printf("%s", tmp_line);
                  if (tmp_line[strlen(tmp_line) - 1] != '\n') {
                    printf("\n");
                  }
                }
              }

              else {
                if (v_flag == 1 || options->f) {
                  if (options->n) {
                    printf("%d:", count_str);
                  }
                  printf("%s", tmp_line);
                  if (tmp_line[strlen(tmp_line) - 1] != '\n') {
                    printf("\n");
                  }
                }
              }
            }
          }

          else {
            e_flag = 1;
            if (success == 0) {
              if (count_files > 1) {
                if (options->h) {
                  if (e_flag == 1 || options->f) {
                    if (options->n) {
                      printf("%d:", count_str);
                    }

                    printf("%s", tmp_line);
                    if (tmp_line[strlen(tmp_line) - 1] != '\n') {
                      printf("\n");
                    }
                  }
                }

                else {
                  if (options->e || options->f) {
                    printf("%s:", argv[optind]);
                  } else {
                    printf("%s:", argv[optind + 1]);
                  }

                  if (options->n) {
                    printf("%d:", count_str);
                  }

                  printf("%s", tmp_line);
                  if (tmp_line[strlen(tmp_line) - 1] != '\n') {
                    printf("\n");
                  }
                }
              }

              else {
                if (options->f || e_flag == 1) {
                  if (options->n) {
                    printf("%d:", count_str);
                  }

                  printf("%s", tmp_line);
                  if (tmp_line[strlen(tmp_line) - 1] != '\n') {
                    printf("\n");
                  }
                }
              }
            }
          }
          count_str++;
        }
      }
    }

    if (options->c) {
      if (count_files > 1) {
        if (options->h) {
          if (options->l && options->c &&
              (options->v || options->h || options->n || options->f)) {
            if (c_flag > 0 || c2_flag > 0) {
              printf("1\n");
            } else {
              printf("0\n");
            }
          } else if (options->v) {
            printf("%d\n", c_flag);
          } else {
            printf("%d\n", c2_flag);
          }
        } else {
          if (options->e || options->f) {
            printf("%s:", argv[optind]);
          } else {
            printf("%s:", argv[optind + 1]);
          }

          if (options->l && options->c &&
              (options->v || options->h || options->n || options->f)) {
            if (c_flag > 0 || c2_flag > 0) {
              printf("1\n");
            } else {
              printf("0\n");
            }
          } else if (options->v) {
            printf("%d\n", c_flag);
          } else {
            printf("%d\n", c2_flag);
          }
        }
      } else {
        if (options->l && options->c &&
            (options->v || options->h || options->n || options->f)) {
          if (c_flag > 0 || c2_flag > 0) {
            printf("1\n");
          } else {
            printf("0\n");
          }
        } else if (options->v) {
          printf("%d\n", c_flag);
        } else {
          printf("%d\n", c2_flag);
        }
      }

      if (options->l && (c_flag > 0 || c2_flag > 0)) {
        if (options->e || options->f) {
          printf("%s\n", argv[optind]);
        } else {
          printf("%s\n", argv[optind + 1]);
        }
      }
    }

  } else {
    if (options->s == 0) {
      fprintf(stderr, "No such file or directory\n");
    }
  }
  fclose(fp);
  free(tmp_line);
  regfree(&re);
}
