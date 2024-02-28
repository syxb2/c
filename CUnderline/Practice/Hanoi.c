#include <stdio.h>

void Hanoi(int n, char A, char B, char C) { // 这里A是移动前的柱子，B是移动后的柱子，C是辅助的柱子
    if (n == 1) {
        printf("%c --> %c\n", A, B);
        return;
    }

    Hanoi(n - 1, A, C, B);
    Hanoi(1, A, B, C);
    Hanoi(n - 1, C, B, A);
}
// 递推使用的一般规律：随着递推的进行，int n 中的n会逐渐减小，当 n 减小为1时，递推再依次返回



int main() {
    int n;
    scanf("%d", &n);
    Hanoi(n, 'A', 'B', 'C');

    return 0;
}