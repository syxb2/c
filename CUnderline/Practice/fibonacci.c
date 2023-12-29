// #include <stdio.h>

// int main()
// {
//     int a = 1, b = 1, i;
//     int c = 1;

//     int x = 0;
//     scanf("%d", &i);
//     if (i == 1)
//         // printf("%d\n", c);
//         ;
//     else if (i == 2)
//         // printf("%d\n", c);
//         ;
//     else
//         while (x < i - 2)
//         {
//             c = a + b;
//             a = b;
//             b = c;

//             ++x;
//             /* code */
//         }

//     printf("%d\n", c);

//     return 0;
// }

#include <stdio.h>

int main()
{
    unsigned long n, f1 = 1, f2 = 1, f3 = 1;

    scanf("%lu", &n);
    for (unsigned long i = 3; i <= n; ++i)
    {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }

    printf("%lu\n", f3);

    return 0;
}