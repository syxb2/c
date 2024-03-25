#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long a[10000001];

int compare(const void *a, const void *b) {
    return (*(long long*) a - *(long long*) b);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n, a0, A, B, C, P;
        memset(a, 0, sizeof(a));
        scanf("%d %d %d %d %d %d", &n, &a0, &A, &B, &C, &P);
        a[0] = a0;
        for (int j = 1; j <= n; j++) {
            a[j] = (A * a[j - 1] * a[j - 1] + B * a[j - 1] + C) % P;
        }
        qsort(a, n, sizeof(long long), compare);
        int pd = 1;
        for (int j = 0; j < n; j++) {
            if (a[j] == a[j + 1]) {
                printf("Repetitive\n");
                pd = 0;
                break;
            }
        }
        if (pd) printf("Different\n");
    }
    return 0;
}
