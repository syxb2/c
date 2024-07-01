#include <stdio.h>
#define N 10

int main() {
    int a[N] = { 2, 2, 3, 5, 7, 2, 5, 1, 9, 4 };
    int i, j, temp;

    for (i = 0; i < N - 1; i++) // 外循环设置排序趟数，N个数进行N-1次排序
    {
        /* code */
        for (j = 0; j < N - i - 1; j++) // 内循环设置每趟比较的次数，第i躺比较i-1次。
        {
            /* code */
            if (a[j] > a[j + 1]) // 相邻元素比较，若逆序则交换
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < N - 1; i++) {
        /* code */
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}