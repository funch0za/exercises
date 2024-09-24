#include <getopt.h>
#include <stdlib.h>
#include <string.h> 
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

enum {MAXN = 1000, TABN = 100};

void set_args(int argc, char **argv, int *b, int *e, int *n, int *s, int *t,
              int *v);
void usage();
int open_file(char *filename);

int main(int argc, char **argv) {
  int b = 0, e = 0, n = 0, s = 0, t = 0, v = 0;
  set_args(argc, argv, &b, &e, &n, &s, &t, &v);

  int number = 0, space_flag = 0;
  for (int j = 1; j < argc; ++j) {
    if (argv[j][0] != '-') {
      int fd = open_file(argv[j]);

      char current[MAXN];
      read(fd, current, MAXN);
      do {
        if (space_flag == 1 && current[0] == '\n') {
          continue;
        }

        if (current[0] == '\n' && s == 1) {
          space_flag = 1;
        } else {
          space_flag = 0;
        }

        if (n == 1 || (b == 1 && current[0] != '\n')) {
          ++number;
          char tab[TABN];
          sprintf(tab, "%6d\t", number);
          write(0, tab, strlen(tab)); 
        }

        if (e == 1 && current[strlen(current) - 1] == '\n') {
          current[strlen(current) - 1] = '$';
        }

        if (t == 1 || v == 1) {
          for (size_t k = 0; k < strlen(current); ++k) {
            if (t == 1 && current[k] == '\t') {
              write(0, "^I", 1);
            } else if (v == 1 && current[k] == 127) {
              write(0, "^?", 1);
            } else if (v == 1 && 0 <= current[k] && current[k] <= 31 &&
                       current[k] != '\n' && current[k] != '\t') {
              char ch[1] = {'@' + current[k]};
              write(0, "^", 1);
              write(0, ch, 1);
            } else {
              char ch[1] = {current[k]};
              write(0, ch, 1);
            }
          }
        } else {
          write(0, current, strlen(current));
        }

        if (e == 1 && current[strlen(current) - 1] == '$') {
          char *ch = "\n";
          write(0, ch, 1);
        }
      } while (read(fd, current, MAXN) != 0);
      close(fd);
    }
  }
  return 0;
}

void set_args(int argc, char **argv, int *b, int *e, int *n, int *s, int *t,
              int *v) {
  struct option options[4];

  options[0].name = "number-nonblank";
  options[0].has_arg = 0;
  options[0].val = 'b';
  options[0].flag = 0;

  options[1].name = "number";
  options[1].has_arg = 0;
  options[1].val = 'n';
  options[1].flag = 0;

  options[2].name = "squeeze-blank";
  options[2].has_arg = 0;
  options[2].val = 's';
  options[2].flag = 0;

  options[3].name = 0;
  options[3].has_arg = 0;
  options[3].val = 0;
  options[3].flag = 0;

  int current;
  while ((current = getopt_long(argc, argv, "benstTv", options, NULL)) != -1) {
    if (current == 'b') {
      *b = 1;
    } else if (current == 'v') {
      *v = 1;
    } else if (current == 'E') {
      *e = 1;
    } else if (current == 'e') {
      *e = 1;
      *v = 1;
    } else if (current == 'n') {
      *n = 1;
    } else if (current == 's') {
      *s = 1;
    } else if (current == 'T') {
      *t = 1;
    } else if (current == 't') {
      *t = 1;
      *v = 1;
    } else {
      usage();
    }
  }
}

void usage() {
  char *error_msg = "cat [OPTION] [FILE]...";
  write(2, error_msg, strlen(error_msg));
  exit(-1);
}

int open_file(char *filename) {
  int fd = open(filename, O_RDONLY);
  
  if (fd == -1) {
    write(2, filename, strlen(filename));
    char *error_msg = ": No such file or directory\n";
    write(2, error_msg, strlen(error_msg));
    exit(-1);
  }

  return fd;
}


