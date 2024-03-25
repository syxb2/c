#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, t;
    scanf("%d %d %d", &n, &m, &t);

    int **arr = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        arr[i] = (int *) malloc(m * sizeof(int));
    }
    int **count = (int **) malloc(m * sizeof(int *));
    for (int i = 0; i < m; ++i) {
        count[i] = (int *) malloc(t * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < t; i++) {
            count[j][i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            count[j][arr[i][j] - 1]++;
        }
    }

    for (int i = 0; i < t; i++) {
        int min_count = count[0][i];
        int max_count = count[0][i];
        for (int j = 1; j < m; j++) {
            if (count[j][i] < min_count) {
                min_count = count[j][i];
            }
            if (count[j][i] > max_count) {
                max_count = count[j][i];
            }
        }
        printf("%d %d\n", min_count, max_count);
    }

    return 0;
}
