#include <stdio.h>

int main() {
    char *a = "asdasdasd";
    printf("%s\n", a);
    for (; *a != '\0'; ++a) printf("%c", *a);
    printf("\n");

    return 0;
}