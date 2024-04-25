#include <stdio.h>

#define MAXLEN 1000

int my_getline(char s[]);
void reverse(char s[], int len);
void clean_str(char s[]);

int main()
{
    int len;
    char s[MAXLEN];
    while ((len = my_getline(s)) > 0) {
        reverse(s, len);
        printf("%s\n", s);
        clean_str(s);
    }
}

int my_getline(char s[])
{
    int c;
    int len = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        s[len] = c;
        ++len;
    }
    if (c == '\n' && len == 0) {
        return 1;
    }
    return len;
}

void reverse(char s[], int len)
{
    for (int i = 0; i < len / 2; ++i) {
        char tmp = s[len - i - 1];
        s[len - i - 1] = s[i];
        s[i] = tmp;
    }
}

void clean_str(char s[])
{
    s[0] = '\0';
}
