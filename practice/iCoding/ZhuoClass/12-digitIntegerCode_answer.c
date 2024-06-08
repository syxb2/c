/*
12位整数编码

用12位的存储空间表示整数，一般只能有212=4096个数字。现采用如下编码方式：

用8位表示一个常数 immed_8，用4位表示该常数要进行移位操作的移位数 rotate_imm，
最终这12位表示的数值是： immed_8 循环右移 rotate_imm*2 位后所得到的值。

示例：0x3fc可以由8位常数0xff循环右移30位得到，是常数表达式。
示例：0x1fe，虽然可以由0xff循环右移31位得到，但是移动的位数不是偶数，因此不符合该编码方式。

如果只考虑正整数，请编写程序，

该程序从标准输入读取一个非负32位十进制整数 K，
如果 K 可以采用此编码方式，则输出 -1，程序结束；
如果不行，该程序将试着找出两个离 K 最近的两个数 m 和 n，要求：
m 比 K 小，且 m 及 K-m 都可以采用上述编码；
n 比 K 大，且 n 及 K-n 都可以采用上述编码；

如果 m 和 n 都找到，则输出 K，m 和 n，格式如下：
K,m,n

即输出的三个数用英文逗号隔开；
否则输出 -2。

背景知识参考：
https://blog.csdn.net/aspenstars/article/details/71247704
*/

#include <stdio.h>

#define MAX_IMMED 0xFF
#define UINT_MAX 4294967295U

unsigned int rotate_right(unsigned int value, int shift) {
    return (value >> shift) | (value << (32 - shift));
}

int can_be_encoded(unsigned int num) {
    for (int imm = 0; imm <= MAX_IMMED; imm++) {
        for (int r = 0; r < 16; r++) {
            if (rotate_right(imm, r * 2) == num) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    unsigned int K;
    if (scanf("%u", &K) != 1) {
        return -1;
    }

    if (can_be_encoded(K)) {
        printf("-1\n");
        return 0;
    }

    unsigned int m = 0, n = UINT_MAX;
    for (unsigned int i = K - 1; i > 0; i--) {
        if (can_be_encoded(i) && can_be_encoded(K - i)) {
            m = i;
            break;
        }
    }
    for (unsigned int i = K + 1; i < UINT_MAX; i++) {
        if (can_be_encoded(i) && can_be_encoded(i - K)) {
            n = i;
            break;
        }
    }

    if (m > 0 && n < UINT_MAX) {
        printf("%u,%u,%u\n", K, m, n);
    } else {
        printf("-2\n");
    }

    return 0;
}