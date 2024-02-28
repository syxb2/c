#include <stdio.h>
#include <string.h>

char* planets[ ] = {
    "Mercury",
    "Venus",
    "Earth",
    "Mars",
    "Jupiter",
    "Sature",
    "Neptune",
    "Uranus"
};

void print_planets(char* pl[ ], int n) {
    for (int i = 0; i < n; ++i) {
        puts(pl[i]); // puts 可以自动换行
    }
}

void sort_planets(char* pl[ ], int n) {
    int i = 0, j = 0;
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - i - 1; ++j) {
            if (strcmp(pl[j], pl[j + 1]) > 0) {
              // 交换指针（地址），而不是交换字符串（因为字符串常量位于常量存储区，不能变动）
                char* t = pl[j];
                pl[j] = pl[j + 1];
                pl[j + 1] = t;
            }
        }
    }
}

int main() {
    print_planets(planets, 8);
    sort_planets(planets, 8);
    print_planets(planets, 8);

    return 0;
}