#include <stdio.h>

// 1 - red win; 2 - yellow win
int jud(int r, int y, char bl) {
    if (r < 7 && y < 7) {
        if (bl == 'B') {
            return 2;
        }
        if (bl == 'L') {
            return 1;
        }
    }
    else if (r == 7 && y < 7) {
        return 1;
    }
    else if (r < 7 && y == 7) {
        return 2;
    }
    else if (r == 7 && y == 7) {
        if (bl == 'B') {
            return 1;
        }
        if (bl == 'L') {
            return 2;
        }
    }
    return 0;
}

int main() {
    int a = 1;
    for (; a != 0;) {
        char arr[128] = { '\0' };
        char *str = arr;
        int r = 0, y = 0;
        scanf("%d", &a);
        if (a == 0) return 0;
        scanf("%s", arr);
        for (int j = 0; j < a; ++j, ++str) {
            switch (*str) {
                case 'R':
                    ++r;
                    break;
                case 'Y':
                    ++y;
                    break;
                case 'B':
                    if (jud(r, y, *str) == 1)
                        printf("Red\n");
                    else if (jud(r, y, *str) == 2)
                        printf("Yellow\n");
                    break;
                case 'L':
                    if (jud(r, y, *str) == 1)
                        printf("Red\n");
                    else if (jud(r, y, *str) == 2)
                        printf("Yellow\n");
                    break;
            }
        }
    }

    return 0;
}