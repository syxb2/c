#include <stdio.h>

int main() {
    int N = 0;
    scanf("%d", &N);
    for (int a = 0; a < N; ++a) {
        int n = 0;
        int k = 0;
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; ++i) {
            int s = 1;
            for (int j = 2; j <= i && j <= k; ++j) {
                if (i % j == 0) {
                    if (s == 0) {
                        s = 1;
                    }
                    else {
                        s = 0;
                    }
                }
            }
            if (s == 1) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }

    return 0;
}