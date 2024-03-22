#include <stdio.h>

#define MAXSIZE    200 

int main() {
    int c = 0;
    scanf("%d", &c);
    for (int d = 0; d < c; ++d) {
        int mk[MAXSIZE] = { 0 };
        int m = 0, n = 0;
        scanf("%d %d", &m, &n);
        --n;
        for (int i = 1; i <= m; ++i) {
            mk[i] = 1;
        }
        int i = 1;
        for (int j = 0; j < m - 1; ++j) {
            for (int a = 0; a < n; ++a) {
                if (mk[i] == 1) {
                    ++i;
                }
                else if (mk[i] == 2) {
                    i += 2;
                }
                else if (mk[i] == 0) {
                    for (; mk[i] == 0; ) {
                        ++i;
                        if (i == MAXSIZE - 1) {
                            i = 0;
                        }
                    }
                    ++i;
                }
            }
            for (; mk[i] == 0; ) {
                ++i;
                if (i == MAXSIZE - 1) {
                    i = 0;
                }
            }
            mk[i] = 0;
            ++i;
        }
        for (int b = 0; b < MAXSIZE; ++b) {
            if (mk[b] == 1) {
                printf("%d\n", b);
            }
        }

    }
    return 0;
}