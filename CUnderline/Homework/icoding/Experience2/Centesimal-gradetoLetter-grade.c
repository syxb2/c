#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);

    if (a >= 0 && a <= 100)
    {
        switch (a / 10)
        {
        case 10:;
        case 9 /* constant-expression */:
            /* code */
            printf("Letter grade: A\n");
            break;
        case 8:
            printf("Letter grade: B\n");
            break;
        case 7:
            printf("Letter grade: C\n");
            break;
        case 6:
            printf("Letter grade: D\n");
            break;
        default:
            printf("Letter grade: F\n");
            break;
        }
    }
    else
    {
        printf("Error, grade must be between 0 and 100.\n");
    }

    return 0;
}