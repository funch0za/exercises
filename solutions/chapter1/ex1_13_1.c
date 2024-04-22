#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_LEN 45

int main()
{
    int c, len, state;

    printf("%3c", ' ');
    for (int i = 1; i <= MAX_LEN; ++i) {
        printf("%3d", i);
    }
    putchar('\n');

    state = OUT;
    len = 0;
    for (int n = 0; (c = getchar()) != EOF;) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                ++n;
                printf("%2d ", n);
                for (int i = 0; i < len; ++i) {
                    printf("%3c", '#');
                }
                putchar('\n');
            }
            state = OUT;
            len = 0;
        } else {
            if (state == OUT) {
                state = IN;
            }
            ++len;
        }
    }
}
