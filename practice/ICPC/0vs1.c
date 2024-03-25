#include <stdio.h>
#include <string.h>

char c[10001];
int start;

int same(int left, int right) {
    if (start == 0 && c[left] == '1' && c[right] == '1') {
        ++start;
        return 1;
    }
    int a = c[left];
    if (c[left + 1] == c[right - 1] != a)
        return 2;
    else
        return c[left] - '0';
}

int unsame(int left, int right) {
    if (c[left + 1] != c[right - 1])
        return 2;
    else
        return c[left + 1] - '0';
}

int main() {
    int n;
    int m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        scanf("%s", c);
        int left = 0, right = m - 1;
        int pd;
        start = 0;
        if (!strcmp(c, "000")) {
            printf("0\n");
            continue;
        }
        else if (!strcmp(c, "001") || !strcmp(c, "010") || !strcmp(c, "100")) {
            printf("-1\n");
            continue;
        }
        else if (!strcmp(c, "011") || !strcmp(c, "101") || !strcmp(c, "110") || !strcmp(c, "111")) {
            printf("1\n");
            continue;
        }
        while (right - left >= 2) {
            if (c[left] == c[right]) {
                pd = same(left, right);
                if (pd == 2) {
                    left++;
                    right--;
                }
                else if (pd == 1) {
                    printf("1\n");
                    break;
                }
                else if (pd == 0) {
                    printf("0\n");
                    break;
                }
            }
            else {
                pd = unsame(left, right);
                if (pd == 2) {
                    left++;
                    right--;
                }
                else if (pd == 1) {
                    printf("1\n");
                    break;
                }
                else if (pd == 0) {
                    printf("0\n");
                    break;
                }
            }
        }
        printf("-1\n");
    }

    return 0;
}