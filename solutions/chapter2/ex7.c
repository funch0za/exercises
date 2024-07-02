#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned getbits(unsigned x, int p, int n);
void print_bits(unsigned x);

unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p + 1 - n)) & ~(~(unsigned)0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
	unsigned mask = (~(unsigned)0) >> p;
	mask <<= p;
	mask >>= (p - n + 1);
	mask = ~mask;
	mask <<= (p - n + 1);
	mask = ~mask;
	x &= mask;
	y &= ~(~0 << n);
	y <<= (p - n + 1);
	x |= y;
	return x;
}

unsigned invert(unsigned x, int p, int n) {
	return setbits(x, p, n, ~getbits(x, p, n));
}

void print_bits(unsigned int x) {
	for (int i = 31; i >= 0; --i) {
		if (((x >> i) & 1) == 1) {
			putchar('1');
		} else {
			putchar('0');
		}
	}
	putchar('\n');
}