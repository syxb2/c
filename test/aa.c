#include <stdio.h>

int main() {
    int A, B, N;
    scanf("%d", &N);

    for (A = 1; A <= 9; A++)
        for (B = 2; B <= 9; B++)
            if (A < B && (A * 10 + B) * (B * 10 + A) == N) {
                printf("%d\n", A * 10 + B);
                return 0;
            }

    printf("NO\n");

    return 0;
}