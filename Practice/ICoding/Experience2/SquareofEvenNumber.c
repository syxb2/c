#include <stdio.h>

int main() {
    int a, i, b;
    printf("请输入一个整数：\n");
    scanf("%d", &a);

    if (a % 2 == 0) {
        for (i = 2; i != a + 2; i = i + 2) {
            b = i * i;
            printf("%d\n", b);
        }
    }
    else {
        a = a - 1;
        for (i = 2; i != a + 2; i = i + 2) {
            b = i * i;
            printf("%d\n", b);
        }
    }

    return 0;
}
