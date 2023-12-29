#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 30

int main()
{
    srand(time(NULL)); // 初始化随机数发生器。只在main函数里调用一次即可

    int a[N];
    int i, j;

    // 用随机数填充数组
    for (i = 0; i < N; ++i)
    {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    putchar('\n');

    // TODO:
    bool swapped = true;

    // <-------------bubble（冒泡排序法）-------------->
    // 循环数量: [n(n+1)]/2 - 数量级是n^2
    // 额外花费空间 - 一个变量
    for (i = 0; i < N - 1 && swapped; ++i)
    {
        swapped = false;
        for (j = 0; j < N - i - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                swapped = true;
            }
        }
    }

    // <-------------选择排序法------------->
    // for (i = 0; i < N - 1; i++)
    // {
    //     /* code */
    //     for (j = i + 1; j < N; j++)
    //     {
    //         /* code */
    //         if (a[i] > a[j])
    //         {
    //             // 经典的交换方法：
    //             int t = a[i];
    //             a[i] = a[j];
    //             a[j] = t;
    //         }
    //     }
    // }

    for (i = 0; i < N; ++i)
        printf("%d ", a[i]);
    putchar('\n');

    return 0;
}