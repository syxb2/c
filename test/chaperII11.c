#include <stdio.h>

int main() {
    double pi_1, pi_2, e;

    scanf("%lf", &e);

    for (int n = 2; 1; ++n) { // 最好把循环计数变量的定义写在循环括号内部，
                              // 这样当跳出循环时 i 就会被销毁，再使用 i 时就不会用到已经使用过的 i（有值的 i ）
        // 应该先后计算两次 pi，最后比较
        // 第一次计算
        double t = 0;
        double a = 1, b = 1;
        int i = 1;
        for (; i < n; ++i) {
            a *= i;
            b *= (2 * i + 1);
            t += a / b; // 这里 a/b 是个整数，所以应该把 a b 也声明为 double（在 13 行）
        }
        pi_1 = 2 * (1 + t);

        // 第二次计算
        a *= i;
        b *= (2 * i + 1);
        t += a / b;
        pi_2 = 2 * (1 + t);

        if (pi_2 - pi_1 < e) { // 后一次计算结果 减去 前一次计算结果
            printf("%d %.7lf\n", n + 1, pi_2); // 输出 后一次的迭代（循环）次数，和后一次的计算结果
            break;
        }
    }

    return 0;
}