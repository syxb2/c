#include <stdio.h>

int main() {
    int n = 0;
    int a, b, c;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        if (b < a) {
            int temp = a;
            a = b;
            b = temp;
        }
        if (c < b) {
            int temp = b;
            b = c;
            c = temp;
        }
        if (b < a) {
            int temp = a;
            a = b;
            b = temp;
        }
        if (a == b) printf("%d\n", c);
        else printf("%d\n", b);
    }

    return 0;
}