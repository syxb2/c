#include <stdio.h>
void decompose(float d, int* i, float* f) {
    *i = (int) d;
    *f = d - *i;
}
int main() {
    int i;
    float f, d;
    scanf("%lf", &d);
    decompose(d, &i, &f);
    printf("%d,%.3f\n", i, f);
    return 0;
}