#include <stdbool.h>
#include <stdio.h>

#define TAB_SIZE 4
#define MAX_SIZE 1000

struct my_str {
  int len, count_of_spaces;
  char s[MAX_SIZE];
};

void my_getline(struct my_str *str);
void init_my_str(struct my_str *str);
bool is_space_str(struct my_str *str);
void entab(int len);

int main() {
  struct my_str str;
  do {
    my_getline(&str);
    if (is_space_str(&str)) {
      entab(str.len);
    } else {
      printf("%s\n", str.s);
    }
  } while (str.len > 0);
}

void init_my_str(struct my_str *str) {
  str->len = 0;
  str->count_of_spaces = 0;
  for (int i = 0; i < MAX_SIZE; ++i) {
    str->s[i] = '\0';
  }
}

bool is_space_str(struct my_str *str) {
  return str->len == str->count_of_spaces;
}

void my_getline(struct my_str *str) {
  init_my_str(str);
  int c;
  while ((c = getchar()) != EOF && c != '\n') {
    str->s[str->len] = c;
    if (str->s[str->len] == ' ') {
      ++str->count_of_spaces;
    }
    ++str->len;
  }

  if (c == '\n' && str->len == 0) {
    str->len = 1;
  }
}

void entab(int len) {
  int tabs, spaces;
  if (TAB_SIZE == 1) {
    tabs = 0;
    spaces = len;
  } else {
    tabs = len / TAB_SIZE;
    spaces = len % TAB_SIZE;
  }

  for (int i = 0; i < tabs; ++i) {
    putchar('\t');
  }
  for (int i = 0; i < spaces; ++i) {
    putchar(' ');
  }
  putchar('\n');
}
