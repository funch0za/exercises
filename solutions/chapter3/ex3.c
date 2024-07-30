#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

enum { N = 100 };

void fill_segment(char left, char right, char *s);
void expand(char *s1, char *s2);
bool check_char(char l, char r);

int main(void) {
  char s1[N], s2[N];
  while (fgets(s1, N, stdin) != NULL) {
    expand(s1, s2);
    puts(s2);
  }
}

void fill_segment(char left, char right, char *s) {
  for (int i = 0; left + i < right; ++i) {
    s[i] = left + i;
  }
}

bool check_char(char l, char r) {
  return (isdigit(l) && isdigit(r)) || (isalpha(l) && isalpha(r));
}

void expand(char *s1, char *s2) {
  int s2_len = 0;
  for (size_t i = 0; i < strlen(s1); ++i) {
    if (s1[i] == '-' && i + 1 < strlen(s1) && i > 0 &&
        check_char(s1[i - 1], s1[i + 1])) {
      fill_segment(s1[i - 1] + 1, s1[i + 1], s2 + s2_len);
      if (s1[i - 1] == s1[i + 1]) {
        ++i;
      } else {
        s2_len += s1[i + 1] - s1[i - 1] - 1;
      }
    } else {
      s2[s2_len] = s1[i];
      ++s2_len;
    }
  }
  s2[s2_len] = '\0';
}
