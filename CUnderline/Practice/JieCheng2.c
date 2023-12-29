// #include <stdio.h>

// int main()
// {
//     unsigned long n, fact;
//     double s;

//     scanf("%d", &n);

//     while (i <= n)
//     {
//         fact = 1 / 1;
//             ++n;
//     }

//     return 0;
// }

// 递推

#include <stdio.h>

int main()
{
    unsigned long n, fact, i;
    double s;

    scanf("%lu", &n); // %lu是unsigned的占位符
    s = 0.0;
    fact = 1;
    for (i = 1; i <= n;)
    {
        s += 1.0 / fact; // 等价于s = s + (1.0 / fact);（括号可以省略） // 不能写s += 1，因为如果这么写那计算结果就是整形（余数会被省略）
        ++i;             // 把i的自加写到循环体内是因为如果写到括号内的话，在循环的最后一次会多执行一次i的自加，从而导致结果比正确结果大1
        fact *= i;
    }

    printf("%lf\n", s); // %lf是double的占位符

    return 0;
}