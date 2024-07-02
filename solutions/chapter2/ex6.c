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
