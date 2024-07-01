#include <stdio.h>
#include <stdbool.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
void print_bit(unsigned x);

unsigned setbits(unsigned x, int p, int n, unsigned y) {
	unsigned mask = (~(unsigned)0) >> p;
	mask <<= p;
	mask >>= (p - n);
	mask = ~mask;
	mask <<= (p - n);
	mask = ~mask;
	x &= mask;
	y &= ~(~0 << n);
	y <<= (p - n);
	x |= y;
	return x;
}
