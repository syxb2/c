#include <stdio.h>

int main() {
    char c;
    int i;

    i = 0;
    // while ((c = getchar()) != '\n')
    // {
    //     int j = c - '0';
    //     i = i * 10 + j;
    // }
    c = getchar();
    while ((c = getchar()) != '\n') {
        int j = c - '0';
        i = i * 10 + j;
        c = getchar();
    }
    printf("%d\n", i);

    return 0;
}