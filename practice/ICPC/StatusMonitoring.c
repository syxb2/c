#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0, m = 0, t = 0;
    scanf("%d %d %d", &n, &m, &t);
    int **arr = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        arr[i] = (int *) malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= t; ++i) {
        int max = 0, min = 100000;
        for (int j = 0; j < m; ++j) {
            int temp = 0;
            for (int k = 0; k < n; ++k) {
                if (arr[k][j] == i) {
                    ++temp;
                }
            }
            if (temp > max) {
                max = temp;
            }
            if (temp < min) {
                min = temp;
            }
        }
        printf("%d %d\n", min, max);
    }

    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0, m = 0, t = 0;
    scanf("%d %d %d", &n, &m, &t);
    int **arr = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        arr[i] = (int *) malloc(m * sizeof(int));
    }

    int count[t + 1][m];
    for (int i = 0; i <= t; ++i) {
        for (int j = 0; j < m; ++j) {
            count[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
            count[arr[i][j]][j]++;
        }
    }

    for (int i = 1; i <= t; ++i) {
        int max = 0, min = n;
        for (int j = 0; j < m; ++j) {
            if (count[i][j] > max) {
                max = count[i][j];
            }
            if (count[i][j] < min) {
                min = count[i][j];
            }
        }
        printf("%d %d\n", min, max);
    }

    return 0;
}
*/