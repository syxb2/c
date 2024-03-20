#include <stdio.h>

void printmat(char(*m)[128], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%c", (m[i])[j]);
        }
        printf("\n");
    }
}

int main() {
    int a = 0;
    scanf("%d", &a);
    for (int m = 0; m < a; ++m) {
        char mat[128][128] = { { '\0' } };
        char res[128][128] = { { '\0' } };
        int n = 0;
        scanf("%d", &n);
        char temp = '\0';
        for (int i = 0; i < n; ++i) {
            scanf("%c", &temp);
            for (int j = 0; j < n; ++j) {
                scanf("%c", &temp);
                for (; temp != '\n' && temp != '\0';) {
                    mat[i][j] = temp;
                    break;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res[j][n - i - 1] = mat[i][j];
            }
        }
        // printmat(mat, n);
        // printf("\n");
        printmat(res, n);
        printf("\n");
    }

    return 0;
}