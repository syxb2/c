// 将十六进制字符串转换为十进制数值
#include <stdio.h>

int htoi(const char *s) {
    int i = 0, d;

    while (*s) {
        if (*s <= '9' && *s >= '0') {
            d = *s - '0'; // 直接写 -‘0’ 而不是写 -48 即可
        }
        else {
            d = *s - 'a' + 10;
        }
        i = i * 16 + d;
        ++s;
    }

    return i;
}

int main() {
    char s[10];

    scanf("%s", s);
    printf("%d\n", htoi(s));

    return 0;
}