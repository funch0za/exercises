#include <stdio.h>

int my_getline(int cnt, int flag);

int main()
{
    while (my_getline(0, 0) > 0) {
    }
}

int my_getline(int cnt, int flag)
{
    int c;
    c = getchar();

    if (c != EOF) {
        ++cnt;
        if (c != ' ' && c != '\t' && c != '\n') {
            flag = 1;
        }
    }

    if (EOF == c || '\n' == c) {
        if (1 == flag && cnt > 1) {
            putchar('\n');
        }
        return cnt;
    }

    cnt = my_getline(cnt, flag);

    if (1 == flag && ' ' != c && '\t' != c) {
        putchar(c);
    }

    return cnt;
}
