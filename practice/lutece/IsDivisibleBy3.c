#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        int a, b, m;
        scanf("%d %d %d", &a, &b, &m);
        int fib_mod[8] = { a % 3, b % 3 };
        for (int i = 2; i < 8; i++) {
            fib_mod[i] = (fib_mod[i - 1] + fib_mod[i - 2]) % 3;
        }
        for (int i = 0; i < m; i++) {
            int n;
            scanf("%d", &n);
            printf("%s\n", fib_mod[n % 8] == 0 ? "Yes" : "No");
        }
        if (t != T - 1) {
            printf("\n");
        }
    }

    return 0;
}
