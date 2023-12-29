#include <stdio.h>

// 生成随机数：
#include <stdlib.h>
#include <time.h>

#define N 10 // 宏定义N为常量10

int main()
{
    int a[N] = {7, 1, 3, 6, 4, 6, 9, 2, 0, 8};
    int max, j;

    srand(time(NULL)); // 随机数初始化只需在main函数中执行一次 // srand括号中的东西叫做种子，用time当种子可以使每时每刻产生的随机数都不同
    // 如果随机数初始化器没有被执行，则rand()表示的数组在所有的电脑上是固定的

    for (j = 0; j < N; ++j)
    {
        a[j] = rand() % 100; // 产生的随机数在0～100之间（除以100的余数只能是0～100）
    }

    j = 0;
    max = a[j];
    for (int i = 0; i < N; ++i)
    {
        if (max < a[i])
        {
            max = a[i];
            // printf("%d\n", i);
            j = i;
        }
    }

    printf("max in a:%d@%d\n", max, j);

    return 0;
}