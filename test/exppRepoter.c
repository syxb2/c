#include <stdio.h>

int yz(int n);

int main() {
    int i, j, m, k;
    scanf("%d %d", &m, &k);
    int mark = 0;

    for (i = m; i <= k; i++) {
        for (j = m + 1; j <= k; j++) {
            if (j > i) {
                if (yz(i) == j && yz(j) == i) {
                    printf("%d-%d\n", i, j);
                    mark = 1;
                }
            }
        }
    }
    if (mark == 0) printf("None\n");

    return 0;
}

int yz(int n) {
    int a, s;
    for (a = 1, s = 0; a < n; a++) {
        if (n % a == 0)
            s += a;
    }
    return s;
}
