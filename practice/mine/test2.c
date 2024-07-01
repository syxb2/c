#include <stdio.h>

int max_repeat_length(const char *s) {
    const char *p = s, *q = p + 1;
    int maxlen[128] = { 0 };
    int i = 1;
    while (*q != '\0') {
        while (*p == *q) {
            ++p;
            ++q;
            ++(maxlen[i]);
        }
        ++i;
        ++p;
        ++q;
    }
    int a = 0;
    for (int j = 0; j < 128; ++j) {
        if (maxlen[j + 1] > maxlen[j])
            a = maxlen[j + 1] + 1;
    }

    return a;
}

char str[10000];

int main() {
    scanf("%s", str);
    printf("%d\n", max_repeat_length(str));

    return 0;
}