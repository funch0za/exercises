#include <stdio.h>

int main()
{
    int c;
    int last_c = '&';

    while ((c = getchar()) != EOF) {
        if ((c == ' ' && last_c != ' ') || c != ' ') {
            putchar(c);
        }
        last_c = c;
    }
}
