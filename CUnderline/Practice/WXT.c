#include <stdio.h>

int main() {
    int n, a, b, c;

    scanf("%d", &n);

    a = n / 100;
    b = n % 100 / 10;
    c = n % 10;

    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b < c) {
        int temp = b;
        b = c;
        c = temp;
    }
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    printf("%d%d%d\n", a, b, c);

    return 0;
}