#include <stdio.h>

int main()
{
    int spaces, tabs, ends;
    spaces = 0;
    tabs = 0;
    ends = 0;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++ends;
        }
        if (c == '\t') {
            ++tabs;
        }
        if (c == ' ') {
            ++spaces;
        }
    }

    printf("spaces = %d\ntabs = %d\nends = %d", spaces, tabs, ends);
}
