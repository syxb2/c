#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_arr() {
    int a = rand();
    int b;
    switch (a % 4) {
        case 0:
            b = 12;
            break;
        case 1:
            b = -12;
            break;
        case 2:
            b = 1;
            break;
        case 3:
            b = -1;
            break;
    }
    return b;
}

int main() {
    srand(time(NULL));
    printf("%d\n", rand());
    printf("%d\n", random_arr());

    return 0;
}