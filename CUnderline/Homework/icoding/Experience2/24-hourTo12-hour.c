#include <stdio.h>

int main() {
    int a, b;
    scanf("%d:%d", &a, &b);
    if (a == 0) {
        a = 12;
        printf("%d:%d AM\n", a, b);
    }
    else if (a <= 12) {
        a = a + 0;
        printf("%d:%d AM\n", a, b);
    }
    else {
        a = a - 12;
        printf("%d:%d PM\n", a, b);
    }

    return 0;
}