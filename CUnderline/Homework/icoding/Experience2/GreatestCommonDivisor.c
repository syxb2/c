// 提示：求最大公约数的经典算法 Euclid 算法如下：
// 分别让变量 m 和 n 存储两个整数。如果 n 为 0，那么停止操作，m 中的值是 GCD ；否则计算 m 除以 n 的余数，把 n 保存到 m 中，并把余数保存到 n 中；重复上述操作，每次都先判断n是否为 0 。

#include <stdio.h>

int main()
{
    int m, n, a;
    scanf("%d%d", &m, &n);
    while (n != 0)
    {
        /* code */
        a = m; // 引入中间变量a，使m不在单次循环中改变
        m = n;
        n = a % n;
    }
    printf("%d\n", m);

    return 0;
}