#include <stdio.h>

int main() {
    unsigned long n, fact, i;

    scanf("%lu", &n);
    fact = 1;
    for (i = 1; i <= n; ++i)
        fact *= i; // 等价于fact = fact * i;
    printf("%lu\n", fact);

    return 0;
}