#include <stdio.h>

int main()
{
    int a[10] = {0};
    int b;
    char c = 0;

    while (c != '\n')
    {
        c = getchar();
        b = c - 48;
        ++a[b];
    }
    printf("Digit: 0 1 2 3 4 5 6 7 8 9\n");
    printf("Occurrences:");
    for (int i = 0; i <= 9; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}