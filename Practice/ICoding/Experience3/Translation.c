#include <stdio.h>

int main() {
    char a = 0;
    // scanf("%c");
    while (a != '\n') {
        a = getchar();
        if (a <= 90 && a > 64) {
            if (a <= 67) {
                printf("2");
            }
            else if (a <= 70) {
                printf("3");
            }
            else if (a <= 73) {
                printf("4");
            }
            else if (a <= 76) {
                printf("5");
            }
            else if (a <= 79) {
                printf("6");
            }
            else if (a <= 83) {
                printf("7");
            }
            else if (a <= 86) {
                printf("8");
            }
            else if (a <= 90) {
                printf("9");
            }
            else {
                break;
            }
        }
    }
    printf("\n");

    return 0;
}