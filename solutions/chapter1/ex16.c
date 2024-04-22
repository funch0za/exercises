#include <stdio.h>

int my_getline();

int main()
{
    int len;
    int max;
    max = 0;
    while ((len = my_getline()) > 0) {
        if (len > max) {
            max = len;
        }
    }
    if (max > 0) {
        printf("%d", max);
    }

    return 0;
}

int my_getline()
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i);

    if (c == '\n') {
        ++i;
    }

    return i;
}
