#include <stdio.h>

int main()
{
    [[maybe_unused]] int i = 0;
    int *p;

    p = &i;
    *p = 1;
    ++*p;

    // printf("%p\n", p);
    printf("%d\n", i);

    // int a[5] = {1, 2, 3, 4, 5};
    // int *p;

    // for (p = &a[0]; p <= &a[4]; ++p)
    // {
    //     printf("%d\n", *p);
    // }

    return 0;
}