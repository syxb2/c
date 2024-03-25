#include <stdio.h>

char a[1000002];

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int w = 0; w < n; ++w) {
        char *p = a;
        int len = 0;
        scanf("%s", a);
        for (; *p != '\0';) {
            if (*p != 'e') ++len;
            ++p;
        }
        p = a;
        do {
            int temp = len;
            for (int i = 0; i < len; ++i) {
                if (*p == '\0') p = a;
                if (len < 3) {
                    break;
                }
                else {
                    for (; *p == 'e';) ++p;
                    char a1 = *p;
                    ++p;
                    for (; *p == 'e';) ++p;
                    char a2 = *p;
                    ++p;
                    for (; *p == 'e';) ++p;
                    char a3 = *p;
                    --p;
                    for (; *p == 'e';) --p;

                    if (a1 != a2 && a1 != a3 && a2 != a3) {
                        *p = 'e';
                        --len;
                        p = a;
                    }
                }
            }
            if (len == temp) {
                p = a;
                break;
            }
        } while (len >= 3);
        for (; *p != '\0';) {
            if (*p != 'e') printf("%c", *p);
            ++p;
        }
        printf("\n");
    }

    return 0;
}