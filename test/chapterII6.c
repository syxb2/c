#include <stdio.h>

int main() {
    int m, n, sum;
    scanf("%d %d", &m, &n);
    sum = n - m + 1; // m 和 n 反了

    for (int i = m; i <= n; ++i) {
        int temp = i, r, rf = 0; // r 存储本次循环的个位数；rf 存储上个循环的个位数 r
        // temp 临时存储 i（因为 i 是循环计数变量，如果在循环内部改变了 i，循环的次数就不对了）

        while (temp != 0) {
            r = temp % 10;
            temp /= 10;
            if (r == 4) {
                sum -= 1;
                break;
            }
            else if (r * 10 + rf == 62) {
                sum -= 1;
                break;
            }
            rf = r;
        }

    }
    printf("%d\n", sum);

    return 0;
}