#include<stdio.h>

int f(float x, float y, float t, float s, int i) {
    float jd = 0, xz = 0, time = 0;
    xz = y * t;
    float tempjd = jd;
    float tempxz = xz;
    float tm = 0;
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
    printf("Case #%d: %.3f\n", i, time);

    return 0;
}

int main() {
    int i = 0;
    scanf("%d", &i);
    float x, y, t, s;
    for (int n = 0; n < i; ++n) {
        scanf("%f %f %f %f", &x, &y, &t, &s);
        f(x, y, t, s, n + 1);
    }

    return 0;
}