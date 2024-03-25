#include <stdio.h>

int isLeapYear(int year) {
    if (year % 400 == 0) {
        return 1;
    }
    else if (year % 4 == 0 && year % 100 != 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int monthday(int month, int year) {
    switch (month) {
        case 1:
            return 31;
        case 2:
            if (isLeapYear(year))
                return 29;
            return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
    }
    return 0;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int a = 0; a < n; ++a) {
        int y = 0, m = 0, d = 0;
        int num = 0;
        scanf("%d %d %d", &y, &m, &d);
        for (int i = 1; i < m; ++i) {
            num += monthday(i, y);
        }
        num += d;
        printf("%d\n", num);
    }

    return 0;
}