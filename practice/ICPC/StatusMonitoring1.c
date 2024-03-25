#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0, m = 0, t = 0;
    scanf("%d %d %d", &n, &m, &t);
    int **arr = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        arr[i] = (int *) malloc(m * sizeof(int));
    }
    int **count = (int **) malloc(m * sizeof(int *));
    for (int i = 0; i < m; ++i) {
        arr[i] = (int *) malloc(t * sizeof(int));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
            ++count[j][arr[i][j]];
        }
    }
    for (int i = 1; i <= t; ++i) {
        printf("%d %d\n", count[i], count[i]);
    }

    return 0;
}
