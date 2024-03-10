/* 判断一个字符串是否是回文字符串 */

#include <stdio.h>
#include <stdbool.h>

bool is_palindrome(const char *s) {
    const char *p = s;
    while (*p) {
        ++p;
    }
    --p;

    while (s < p) {
        if (*s != *p) return false;
        ++s, --p;
    }


    return true;
}

int main() {
    char buf[128];
    scanf("%s", buf);
    printf(is_palindrome(buf) ? "yes\n" : "no\n");

    return 0;
}