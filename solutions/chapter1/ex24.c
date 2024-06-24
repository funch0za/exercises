#include <stdbool.h>
#include <stdio.h>

#define ERROR fputs("compilation error\n", stderr)

enum brackets_type {
    OPEN = 1,
    CLOSE = -1
};

enum states {
  OUT = 0,
  ONE_LINE_COMMENT = 1,
  MULTILINE_COMMENT = 2,
  QUOTE = 3,
  QUOTE_DOUBLE = 4
};

#ifdef DEBUG_LEVEL
  #define DEBUG fprintf(stderr, "last char = %c char = %c round = %d square = %d shape = %d\n", b, c, round, square, shape); print_state(state)
#else
  #define DEBUG
#endif

void print_state(int state) {
  switch (state) {
    case OUT:
      fputs("OUT\n", stderr);
      break;
    case ONE_LINE_COMMENT:
      fputs("ONE LINE COMMENT\n", stderr);
      break;
    case MULTILINE_COMMENT:
      fputs("MULTILINE COMMENT\n", stderr);
      break;
    case QUOTE:
      fputs("QUOTE\n", stderr);
      break;
    case QUOTE_DOUBLE:
      fputs("QUOTE DOUBLE\n", stderr);
      break;
    default:
      fputs("?\n", stderr);
      break;
  }
}

void check_bracket(int *sum, int type);

int main(void) {
  int round, square, shape;
  round = 0;
  square = 0;
  shape = 0;

  int state; // comment
  state = OUT;

  char b, c;
  b = EOF;
  while ((c = getchar()) != EOF) {
    switch (c) {
      case '\n':
        if (state == ONE_LINE_COMMENT) {
          state = OUT;
        }
        break;
      case '\'':
        if (state == OUT) {
          state = QUOTE;
        } else if (state == QUOTE) {
          if (b != '\\') {
            state = OUT;
          }
        }
        break;
      case '"':
        if (state == OUT) {
          state = QUOTE_DOUBLE;
        } else if (state == QUOTE_DOUBLE) {
          if (b != '\\') {
            state = OUT;
          }
        }
        break;
      case '*':
        if (b == '/' && state == OUT) {
          state = MULTILINE_COMMENT;
        }
        break;
      case '/':
        if (b == '*') {
          if (state == MULTILINE_COMMENT) {
            state = OUT;
          } else {
            ERROR;
          }
        } else if (b == '/') {
          state = ONE_LINE_COMMENT;
        }
        break;
      default:
        break;
    }

    if (state == OUT) {
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

    DEBUG;
    b = c;
  }

  if (round != 0 || square != 0 || shape != 0 || state != OUT) {
    ERROR;
  }

  DEBUG;
}

void check_bracket(int *sum, int type) {
  *sum += type;

  if (sum < 0) {
    ERROR;
  }
}