#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') {
      ++nl;
    }
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    } else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
}

/*
$cat -nv input.txt
     1
     2	^M
     3	G5
     4	?,*
На строке №2 непечатаемый символ.
Данный алгоритм считает что это слово.
Команда wс наоборот, не считает это символом, записывает только в счетчик
символов.
*/
