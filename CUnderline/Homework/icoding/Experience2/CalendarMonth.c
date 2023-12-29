#include <stdio.h>

int main()
{
    int daymount, startday = 1;
    int i = 1, j = 0, m, temp = 0;
    // int a[5][7];
    scanf("%d%d", &daymount, &startday);
    printf("日一二三四五六\n");
    for (m = 0; m < startday - 1; ++m)
    {
        printf("  ");
    }
    for (m = 1; m < 9 - startday; ++m)
    {
        printf(" %d", m);
    }
    printf("\n");
    i = 9 - startday;
    while (i <= 22)
    {
        while (j < 7 + temp)
        {
            if (i < 10)
            {
                printf(" %d", i);
            }
            else
            {
                printf("%d", i);
            }
            ++j;
            ++i;
        }
        printf("\n");
        temp += 7;
    }
    // printf("\n");
    if (startday <= 5 || daymount < 30)
    {
        for (m = 30 - startday; m <= daymount; ++m)
        {
            printf("%d", m);
        }
        printf("\n");
    }
    else if (startday == 6 && daymount == 31)
    {
        printf("24252627282930\n31\n");
    }
    else if (startday == 7 && daymount == 31)
    {
        printf("23242526272829\n3031\n");
    }
    else if (startday == 6 && daymount == 30)
    {
        printf("24252627282930\n");
    }
    else if (startday == 7 && daymount == 30)
    {
        printf("23242526272829\n30\n");
    }

    return 0;
}