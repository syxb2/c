#include <stdio.h>

int main()
{
    int a;
    printf("请输入风速：");
    scanf("%d", &a);
    if (a < 1)
    {
        printf("Calm\n");
    }

    else if (a <= 3)
    {
        printf("Light air\n");
    }

    else if (a <= 27)
    {
        printf("Breeze\n");
    }

    else if (a <= 47)
    {
        printf("Gale\n");
    }

    else if (a <= 63)
    {
        printf("Storm\n");
    }

    else
    {
        printf("Hurricane\n");
    }

    return 0;
}