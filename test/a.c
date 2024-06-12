#include <stdio.h>

void f(int* x) {
    *x = 520;

    return;
}

void g(int x) {
    x = 1314;

    return;
}


int main() {
    int a;

    a = 0;
    f(&a); // f 函数的参数是指针，所以传入的是 a 的地址，这样 f 函数就可以通过指向 a 的指针而修改 a 的值
    printf("%d\n", a);

    a = 0;
    g(a); // g 函数的参数是值，所以传入的是 a 的值，这样 g 函数修改的是 a 的副本，而不是 a 本身
    printf("%d\n", a);

    return 0;
}
