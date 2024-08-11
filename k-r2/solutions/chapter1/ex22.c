#include <stdio.h>

#define N 3

// balabalabbala

/*
adadmaksnkjfnjksdnfs
*/

int main() {
  int endline = 0;
  char c;

  int a = 5 * 8 / 2;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      endline = 0;
      putchar('\n');
      /*
         ddddd */
    } else if (endline >= N) {
      if (c != ' ' && c != '\t') { /*ababbababababababab */
        endline = 1;
        putchar('\n');
      }
      // 1
      // 2
      //

      //
      putchar(c);
    } else {
      ++endline;
      putchar(c); // abbabab
    }
  }
}
