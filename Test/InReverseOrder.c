/*
#include <stdio.h>

int* InRev(int len, long num) {
    static int arr[256] = { '\0' };
    for (int i = 0; i < len; ++i) {
        arr[i] = num % 10;
        num /= 10;
    }
    return arr;
}

int main() {
    long num, len = 0;
    scanf("%ld", &num);
    long n = num;
    for (; n != 0; n /= 10, ++len);
    int* arr = InRev(len, num);

    for (; *arr != '\0'; arr += 1) {
        printf("%d", *arr);
    }
    printf("\n");


    return 0;
}
*/

#include<stdio.h>

int main() {
    int x = 0;
    scanf("%d", &x);
    int res = 0;
    while (x != 0) {
        res *= 10;
        res += (x % 10);
        x /= 10;
    }
    printf("%d\n", res);

    return 0;
}
