#include <stdio.h>

int main()
{
    int a, b, c;

    scanf("%d/%d/%d", &a, &b, &c);
    printf("You entered the date %d%02d%02d\n", c, a, b);

    return 0;
}