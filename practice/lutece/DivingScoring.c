#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int m = 0;
        scanf("%d", &m);
        float sum = 0;
        float input = 0;
        float max = 0, min = 100;
        for (int i = 0; i < m; ++i) {
            scanf("%f", &input);
            sum += input;
            if (input > max) max = input;
            if (input < min) min = input;
        }
        float res = (sum - max - min) / (m - 2);
        printf("%.2f\n", res);
    }

    return 0;
}