#include <stdio.h>

int main() {
    double a, b, c, e, f, g, r;
    scanf("%lf", &a); // a是贷款金额
    scanf("%lf", &b); // b是利率
    scanf("%lf", &c); // c是每月还款金额
    r = b / 100 / 12; // r是月利率

    // d = a * r;             // d是月利润
    e = a - c + a * r; // e - 1month
    f = e - c + e * r; // f - 2month
    g = f - c + f * r; // g - 3month

    printf("Balance remaining after first payment: $%.2lf\nBalance remaining after second payment: $%.2lf\nBalance remaining after third payment: $%.2lf\n", e, f, g);

    return 0;
}