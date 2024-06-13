#include <stdio.h>

#define N 4

int main()
{
    char c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (int i = 0; i < N; ++i) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }
} 
