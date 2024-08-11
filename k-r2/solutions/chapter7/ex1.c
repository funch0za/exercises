#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
  for (int i = 0; i < strlen(argv[0]); ++i) {
    if (islower(argv[0][i])) {
      putchar(toupper(argv[0][i]));
    } else {
      putchar(tolower(argv[0][i]));
    }
  }
}
