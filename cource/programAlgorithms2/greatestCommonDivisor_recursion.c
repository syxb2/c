#include <stdio.h>

int gcd(int a, int b) {
    if (a % b != 0)
        return gcd(b, a % b);
    else return b;

}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", gcd(a, b));

    return 0;
}