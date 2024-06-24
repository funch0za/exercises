#include <stdbool.h>
#include <stdio.h>

#define ERROR fputs("compilation error", stderr)
#define OPEN 1
#define CLOSE 0

void check_bracket(int *sum, int type);

int main(void) {
  int round, square, shape, comment;
  round = 0;
  square = 0;
  shape = 0;
  comment = 0;

  char c;
  while ((c = getchar()) != EOF) {
    switch (c) {
      case '(':
        check_bracket(&round, OPEN);
        break;
      case ')':
        check_bracket(&round, CLOSE);
        break;
      case '[':
        check_bracket(&square, OPEN);
        break;
      case ']':
        check_bracket(&square, CLOSE);
        break;
      case '{':
        check_bracket(&shape, OPEN);
        break;
      case '}':
        check_bracket(&shape, CLOSE);
        break;
      default:
        break;
    }
  }

  if (round != 0 || square != 0 || shape != 0) {
    ERROR;
  }
}

void check_bracket(int *sum, int type) {
  switch (type) {
    case OPEN:
      ++(*sum);
      break;
    case CLOSE:
      --(*sum);
      break;
    default:
      break;
  }

  if (sum < 0) {
    ERROR;
  }
}