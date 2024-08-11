#include <stdio.h>

int bitcount_1(unsigned);
int bitcount_2(unsigned);

int main() {
  for (unsigned i = 0; i <= 100; ++i) {
    int b1 = bitcount_1(i), b2 = bitcount_2(i);
    printf("i = %u\tbitcount_1 = %d\tbitcount_2 = %d\n", i, b1, b2);
    if (b1 != b2) {
      puts("ERROR");
    }
  }
}

int bitcount_1(unsigned x) {
  int b = 0;
  for (; x != 0; x >>= 1) {
    if (x & 1) {
      ++b;
    }
  }
  return b;
}

int bitcount_2(unsigned x) {
  int b = 0;
  while (x) {
    x &= (x - 1);
    ++b;
  }
  return b;
}