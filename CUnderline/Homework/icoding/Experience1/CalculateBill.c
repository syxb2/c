#include <stdio.h>

int main()
{
    int a, b, c, d, e;

    scanf("%d", &a);
    b = a / 20;
    c = a % 20 / 10;
    d = a % 10 / 5;
    e = a % 5;

    printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 blls: %d\n", b, c, d, e);

    return 0;
}