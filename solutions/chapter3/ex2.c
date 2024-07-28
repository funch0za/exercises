#include <stdio.h>

enum {N = 100};

void escape(char t[N], char s[N]) {
  size_t t_i = 0, s_i = 0;
  for (; t[t_i] != '\0'; ++t_i, ++s_i) {
    switch (t[t_i]) {
      case '\a':
        s[s_i] = '\\';
        ++s_i;
        s[s_i] = 'a';
        break;
      case '\b':
        s[s_i] = '\\';
        ++s_i;
        s[s_i] = 'b';
        break;
      case '\t':
        s[s_i] = '\\';
        ++s_i;
        s[s_i] = 't';
        break;
      case '\n':
        s[s_i] = '\\';
        ++s_i;
        s[s_i] = 'n';
        break;
      case '\v':
        s[s_i] = '\\';
        ++s_i;
        s[s_i] = 'v';
        break;
      case '\f':
        s[s_i] = '\\';
        ++s_i;
        s[s_i] = 'f';
        break;
      case '\\':
        s[s_i] = '\\';
        ++s_i;
        s[s_i] = '\\';
        break;
      case '\r':
        s[s_i] = '\\';
        ++s_i;
        s[s_i] = 'r';
        break;
      default:
        s[s_i] = t[t_i];
        break;
    }
  }

  ++s_i;
  s[s_i] = '\0';
} 

void unescape(char t[N], char s[N]) { 
  size_t t_i = 0, s_i = 0;
  for (; t[t_i] != '\0'; ++t_i, ++s_i) {
    switch (t[t_i]) {
      case '\\':
        ++t_i;
        switch (t[t_i]) {
          case 'a':
            s[s_i] = '\a';
            break;
          case 'b':
            s[s_i] = '\b';
            break;
          case 't':
            s[s_i] = '\t';
            break;
          case 'n':
            s[s_i] = '\n';
            break;
          case 'v':
            s[s_i] = '\v';
            break;
          case 'f':
            s[s_i] = '\f';
            break;
          case 'r':
            s[s_i] = '\r';
            break;
        }        
        break;
      default:
        s[s_i] = t[t_i];
        break;
    }
  }
  ++s_i;
  s[s_i] = '\0';
}

int main(void) {
  char t[N];
  fgets(t, N, stdin);
  fputs(t, stdout);
  char s[N];
  escape(t, s);
  fputs(s, stdout);
  fputs("\n", stdout);
  unescape(s, t);
  fputs(t, stdout);
}
