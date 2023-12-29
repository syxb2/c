// decompose.c

#include <stdio.h>

void decompose(double d, int *i, double *f) {
    *i = (int)d; // 强制类型转换
    *f = d - *i;
}

int main() {
    double d;
    scanf("%lf", &d);

    /*
    int *i;
    double *f;
    decompse(d, i, f);  // 错误：i和f都是野指针
    */
    int i;
    double f;
    decompose(d, &i, &f);
    printf("d=%lf, i=%d, f=%lf\n", d, i, f);

    return 0;
}