#include <stdio.h>
#include <string.h>

char a[100002] = { '\0' };

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int w = 0; w < n; ++w) {
        for (int i = 0; i < 100002; ++i) {
            a[i] = '\0';
        }
        scanf("%s", a);
        while (1) {
            if (strlen(a) < 3) {
                printf("%s\n", a);
                break;
            }
            else {
                while (1) {
                    int len = strlen(a);
                    for (int i = 0; a[i + 2] != '\0';) {
                        if (a[i] != a[i + 1] && a[i] != a[i + 2] && a[i + 1] != a[i + 2]) {
                            for (int j = i + 1; a[j] != '\0'; ++j) {
                                a[j] = a[j + 1];
                            }
                        }
                        else {
                            ++i;
                        }
                    }
                    int len1 = strlen(a);
                    if (len1 == len) {
                        printf("%s\n", a);
                        break;
                    }
                }
                break;
            }
        }
    }

    return 0;
}