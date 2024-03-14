//swap-by-val.c

#include <stdio.h>

/*
    因为C语言的传值调用，所以此swap不能真正地完成两个数的交换
*/
void swap(int x, int y) {
    int t = x;
    x = y;
    y = t;
}

int main() {
    int a, b;

    scanf("%d%d", &a, &b);
    printf("a=%d, b=%d\n", a, b);
    swap(a, b);
    printf("a=%d, b=%d\n", a, b);

    return 0;
}