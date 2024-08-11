#include <stdio.h>

char lower(char c) { return ('A' <= c && c <= 'Z') ? ('a' + c - 'A') : c; }

int main() {
  putchar(lower('c'));
  putchar(lower('A'));
  putchar(lower('F'));
  putchar(lower('0'));
  putchar(lower('L'));
  putchar(lower('Z'));
  putchar(lower('z'));
  putchar(lower('_'));
}