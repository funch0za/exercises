#include <stdio.h>

#define OUT 0
#define ONE_LINE_COMMENT 1
#define MULTILINE_COMMENT 2

int main() {
  int state = OUT;
  char a, b, c;
  a = EOF;
  b = EOF;
  c = EOF;
  while ((c = getchar()) != EOF) {
    if (b != EOF) {
      switch (state) {
      case ONE_LINE_COMMENT:
        if (c == '\n') {
          state = OUT;
          putchar('\n');
        }
        break;
      case MULTILINE_COMMENT:
        if (b == '*' && c == '/') {
          state = OUT;
        }
        break;
      case OUT:
        if (b == '/' && c == '/') {
          state = ONE_LINE_COMMENT;
        } else if (b == '/' && c == '*') {
          state = MULTILINE_COMMENT;
        } else {
          if (c != '/') {
            putchar(c);
          }
          if (b == '/') {
            if (a != EOF && a != '*') {
              putchar(b);
            }
            putchar(c);
          }
        }
        break;
      }
    }

    a = b;
    b = c;
  }
}