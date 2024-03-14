// 修改如下程序，使其可以检测 UPC 的有效性。在用户输入UPC后，程序将输出 VALID 或 NOT VALID 。

// #include <stdio.h>

// int main(void)
// {
//     int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total;

//     printf("Enter the first (single) digit:");
//     scanf("%1d", &d);

//     printf("Enter the first group of five digits:");
//     scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);

//     printf("Enter the second group of five digits:");
//     scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);

//     first_sum = d + i2 + i4 + j1 + j3 + j5;
//     second_sum = i1 + i3 + i5 + j2 + j4;
//     total = 3 * first_sum + second_sum;

//     printf("Check digit: %d\n", 9 - ((total - 1) % 10));

//     return 0;
// }

// UPC条形码知识及其效验计算方法：https://www.getupc.com/upctiaoxingmazhishijieshaojixiaoyanjisuanfangfa/

// 以下是答案：

#include <stdio.h>

int main(void) {
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total, x, y;

    printf("Enter the first (single) digit:");
    scanf("%1d", &d);

    printf("Enter the first group of five digits:");
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);

    printf("Enter the second group of five digits:");
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
    printf("Enter the last single digit:");
    scanf("%d", &y);
    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = 3 * first_sum + second_sum;
    x = 9 - ((total - 1) % 10);
    if (x == y)
        printf("VALID\n");
    else
        printf("NOT VALID\n");

    return 0;
}
