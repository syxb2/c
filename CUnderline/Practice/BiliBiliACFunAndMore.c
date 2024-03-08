#include<stdio.h>

int f(double x, double y, double t, double s, int i) {
    double jd = 0, xz = 0, time = 0;
    xz = y * t;
    double tempjd = jd;
    double tempxz = xz;
    double tm = 0;
    while (jd < s) {
        tempjd = jd;
        tempxz = xz;
        if (jd <= xz) {
            ++time;
            jd += x;
            xz += y;
            if (jd > xz && xz <= s) {
                --time;
                jd = tempjd;
                xz = tempxz;
                tm = (xz - jd) / (x - y);
                time += tm;
                xz += tm * y;
                jd = 0;
            }
            else if (jd > xz && xz > s) {
                --time;
                jd = tempjd;
                xz = tempxz;
                tm = (xz - jd) / (x - y);
                time += tm;
                if ((xz += y * tm) <= s) time += t;
                xz = s;
                jd = 0;
            }
            if (xz > s) xz = s;
        }
    }
    if (jd > s) {
        --time;
        jd = tempjd;
        xz = tempxz;
        tm = (xz - jd) / (x - y);
        time += tm;
    }
    printf("Case #%d: %.3lf\n", i, time);

    return 0;
}

int main() {
    int i = 0;
    scanf("%d", &i);
    double x[10], y[10], t[10], s[10];
    for (int n = 0; n < i; ++n) {
        scanf("%lf %lf %lf %lf", &x[n], &y[n], &t[n], &s[n]);
    }
    for (int n = 0; n < i; ++n) {
        f(x[n], y[n], t[n], s[n], n + 1);
    }

    return 0;
}