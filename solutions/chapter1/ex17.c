#include <stdio.h>

#define MIN_LEN 80

int my_getline(int cnt);

int main()
{
    while (my_getline(0) > 0) {

    }
}

int my_getline(int cnt)
{
    int c;
    c = getchar();

    if (c == EOF || c == '\n') {
        if (cnt == 0 && c == '\n') {
            cnt = 1;
        }
        if (cnt > MIN_LEN) {
            putchar('\n');
        }
        return cnt;
    }

    cnt = my_getline(cnt + 1);

    if (cnt > MIN_LEN) {
        putchar(c);
    }

    return cnt;
}
