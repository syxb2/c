#include <stdio.h>

// #define PI 3.1415926 // macro - 定义一个宏（宏定义：一处修改处处生效）
// 定义"PI"为"3.1415926"

const double PI = 3.1415926;
// 定义常量的第二种方法：定义一个常量
// const是定义函数
// 一个程序中的定义方式最好只有一种，不要一会define一会const

int main()
{
    double radius, volumn;
    // radius(半径)，volumn(体积)

    printf("请输入球的半径：");
    scanf("%lf", &radius);
    // %lf表示长浮点型
    volumn = 4.0 / 3.0 * PI * radius * radius * radius;
    printf("体积 = %lf\n", volumn);

    return 0;
}