#include <stdio.h>
#include <limits.h>

int main(void) {
	puts("From <limits.h>");
	printf("CHAR %d - %d\n", CHAR_MIN, CHAR_MAX);
	printf("SHORT %d - %d\n", SHRT_MIN , SHRT_MAX);
	printf("INT %d - %d\n", INT_MIN, INT_MAX);
	printf("LONG %ld - %ld\n", LONG_MIN, LONG_MAX);

	puts("\nFrom calculate");
	printf("CHAR %d - %d\n", -(1 << (sizeof(char) * 8 - 1)), (1 << (sizeof(char) * 8 - 1)) - 1);
	printf("SHORT %d - %d\n", -(1 << (sizeof(short) * 8 - 1)), (1 << (sizeof(short) * 8 - 1)) - 1);
	printf("INT %d - %d\n", -(1LL << (1LL * sizeof(int) * 8 - 1)), (1LL << (1LL * sizeof(int) * 8 - 1)) - 1);
	printf("LONG %ld - %ld\n", -((long)1 << ((long) sizeof(long) * 8 - 1)), ((long)1 << ((long) sizeof(long) * 8 - 1)) - 1);
}