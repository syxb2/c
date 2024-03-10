// 利用cosx的泰勒展开式求解cosx的近似值：

// #include <stdio.h>
// #include <math.h> // 调用c语言的数学库。

// int main()
// {
//     const long n = 8;  // const表示n是一个常量；long表示n是一个长整数。 // n代表保留的位数。
//     float x, cosx, a; // a表示分子
//     long b, i, sign;   // b表示分母；sign表示每一项的正负号；i表示循环次数的二倍（因为cosx的泰勒展开式的每一项递推2（偶数））

//     // 初始化：
//     cosx = 1.0;
//     sign = -1;

//     scanf("%lf", &x);

//     a = x * x;
//     b = 2;
//     // 初始化结束

//     for (i = 2; i <= n * 2; i += 2)
//     {
//         cosx += sign * a / b;

//         // 递推：
//         a *= x * x;
//         b *= (i + 1) * (i + 2);
//         sign *= -1;
//     }

//     printf("cosx=%.5lf\n", cosx);

//     // 验证结果是否正确：
//     printf("cos(x)=%.5lf\n", cos(x));

//     return 0;
// }

// #include <stdio.h>
// #include <math.h> // 调用c语言的数学库。

// int main()
// {
//     const long n = 20; // const表示n是一个常量；long表示n是一个长整数。 // n代表计算的项数。
//     const float _2pi = 2.0 * 3.1415926;

//     float x, cosx, a; // a表示分子
//     long b, i, sign;   // b表示分母；sign表示每一项的正负号；i表示循环次数的二倍（因为cosx的泰勒展开式的每一项递推2（偶数））

//     // 初始化：
//     cosx = 1.0;
//     sign = -1;

//     scanf("%lf", &x);
//     x -= (int)(x / _2pi) * _2pi; // 由cosx的周期为2pi从而缩小x，从而减小cosx泰勒展开式的误差。

//     a = x * x;
//     b = 2;
//     // 初始化结束

//     for (i = 2; i <= n * 2; i += 2)
//     {
//         cosx += sign * a / b;

//         // 递推：
//         a *= x * x;
//         b *= (i + 1) * (i + 2);
//         sign *= -1;
//     }

//     printf("cosx=%.5lf\n", cosx);

//     // 验证结果是否正确：
//     printf("cos(x)=%.5lf\n", cos(x));

//     return 0;
// }

#include <stdio.h>
#include <math.h> // 调用c语言的数学库。

int main() {
    // 先确定需要变量的个数：分子，分母，更改正负号，cosx的值，自变量x。共五个变量。
    const long n = 20; // const表示n是一个常量；long表示n是一个长整数。 // n代表计算的项数。
    const float _2pi = 2.0 * 3.1415926;
    const float esp = 1E-7; // 1E-7是科学计数法表示10的-7次方（0.0000001）。

    float b, x, cosx, a, cosx_old; // a表示分子 // 这里把b改为float是因为long存不下b了，b太大了。
    long i, sign;                   // b表示分母；sign表示每一项的正负号；i表示循环次数的二倍（为什么要乘2？因为cosx的泰勒展开式的每一项递推2（偶数））

    // 初始化：
    cosx = 1.0;
    cosx_old = 2.0; // 给出一个不可能的初始值（使差值一定不小于1E-7）（反正在第一次循环之后会改变）
    sign = -1;

    scanf("%lf", &x);
    x -= (int) (x / _2pi) * _2pi; // 由cosx的周期为2pi从而缩小x，从而减小cosx泰勒展开式的误差。
    // (int)(x / _2pi) 表示将x / _2pi强制转换为整形

    a = x * x;
    b = 2;
    // 初始化结束

    for (i = 2; i <= n * 2; i += 2) {
        cosx += sign * a / b;

        // 递推：
        a *= x * x;
        b *= (i + 1) * (i + 2);
        sign *= -1;

        // 使结果精确到小数点后七位:

        // 如果连续两次cosx的结果之差小于1E-7，则中断for循环直接输出结果
        if (fabs(cosx_old - cosx) < esp) // fabs - 取绝对值
        {
            break; // 中断循环
        }
        cosx_old = cosx;
    }

    printf("cosx=%.5lf\n", cosx);

    // 验证结果是否正确：
    printf("cos(x)=%.5lf\ni=%ld\n", cos(x), i);

    return 0;
}