#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Options {
  int s;
  int n;
  int b;
  int t;
  int e;
  int v;
} opt;

void parser(int argc, char *argv[], opt *options);
void reader(char *argv[], opt *options);

int main(int argc, char *argv[]) {
  opt options = {0};
  parser(argc, argv, &options);

  if (options.b) {
    options.n = 0;
  }

  while (optind < argc) {
    reader(argv, &options);
    optind++;
  }

  return 0;
}

void parser(int argc, char *argv[], opt *options) {
  int opt = 0;
  int options_index = 0;

  static struct option long_options[] = {
      {"squeeze-blank", no_argument, NULL, 's'},
      {"number", no_argument, NULL, 'n'},
      {"number-nonblank", no_argument, NULL, 'b'},
      {"T", no_argument, NULL, 't'},
      {"E", no_argument, NULL, 'e'},
      {0, no_argument, NULL, 'v'},
      {0, 0, 0, 0}};

  while ((opt = getopt_long(argc, argv, "+snbtev", long_options,
                            &options_index)) != -1) {
    switch (opt) {
      case 's': {
        options->s = 1;
        break;
      }
      case 'n': {
        options->n = 1;
        break;
      }
      case 'b': {
        options->b = 1;
        break;
      }
      case 't': {
        options->t = 1;
        options->v = 1;
        break;
      }
      case 'T': {
        options->t = 1;
        break;
      }
      case 'e': {
        options->e = 1;
        options->v = 1;
        break;
      }
      case 'E': {
        options->e = 1;
        break;
      }
      case 'v': {
        options->v = 1;
        break;
      }
      default:
        fprintf(stderr, "usage");
    }
  }
}

void reader(char *argv[], opt *options) {
  FILE *fp = fopen(argv[optind], "r");

  if (fp) {
    int simvol;
    int s_X = 0;
    int n_X = 0, n_count = 0, n_str_count = 1;
    int b_X = 0, b_count = 0, b_str_count = 1;

    while ((simvol = fgetc(fp)) != EOF) {
      if (options->s) {
        if (simvol == '\n' && s_X == '\n') {
          simvol = fgetc(fp);
          while (simvol == '\n') {
            simvol = fgetc(fp);
          }

          if ((options->e) && (options->n)) {
            printf("%6d	", (n_str_count + 1));
            printf("$\n");
            n_str_count++;

          } else if (options->e) {
            printf("$\n");
          } else if (options->n) {
            printf("%6d\t\n", (n_str_count + 1));
            n_str_count++;
          } else {
            printf("\n");
          }
        }
        s_X = simvol;
      }

      if (options->n) {
        if (n_count == 0) {
          printf("%6d	", n_str_count);
        }

        if (n_X == '\n' && simvol != EOF) {
          n_str_count++;
          printf("%6d\t", n_str_count);
        }
        n_X = simvol;
        n_count++;
      }

      if (options->b) {
        if (b_count == 0 && simvol != '\n') {
          printf("%6d	", b_str_count);
        }

        if ((b_X == '\n') && (simvol != '\n')) {
          b_str_count++;
          printf("%6d	", b_str_count);
        }
        b_X = simvol;
        b_count++;
      }

      if (options->t) {
        if (simvol == 9) {
          printf("^");
          simvol += 64;
        }
      }

      if (options->e) {
        if (simvol == '\n') {
          printf("$");
        }
      }

      if (options->v) {
        if ((simvol >= 0 && simvol <= 8) || (simvol >= 11 && simvol <= 31) ||
            simvol == 127) {
          printf("^");
          if (simvol == 127) {
            simvol = 63;
          } else {
            simvol += 64;
          }
        }
      }

      if (simvol != EOF) {
        printf("%c", simvol);
      }
    }
  } else {
    fprintf(stderr, "No such file or directory");
  }
  fclose(fp);
}
