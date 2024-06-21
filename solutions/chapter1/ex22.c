#include <stdio.h>

#define N 3

int main() {
  int endline = 0;
  char c;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      endline = 0;
      putchar('\n');
    } else if (endline >= N) {
      if (c != ' ' && c != '\t') {
        endline = 1;
        putchar('\n');
      }
      putchar(c);
    } else {
      ++endline;
      putchar(c);	
    }
  }
}