#include <stdio.h>

#define N 8

int main()
{
    int yh[N][N] = {1};
    int i, j;

    for (i = 1; i < N; ++i)
    {
        yh[i][0] = 1;
        for (j = 1; j <= i; ++j)
        {
            yh[i][j] = yh[i - 1][j - 1] + yh[i - 1][j];
        }
    }

    for (i = 0; i < N; ++i)
    {
        for (j = 0; j <= i; ++j)
        {
            printf("%4d", yh[i][j]);
        }
        putchar('\n');
    }

    return 0;
}