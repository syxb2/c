# include <stdio.h>

int main() {
    char a = '0', b = '0'; // "char"是字符声明函数


    // printf("%c,%d\n", a, a); // %c - 输出字符0 // %d - 输出字符0的ASCII码
    // printf("%c\n", a + 1);
    // printf("%d\n", a - 48);
    // printf("%d\n", a - '0');

    scanf("%c", &b);
    a = getchar(); // getchar函数 - 要求输入一个字符

    putchar(a); // putchar函数 - 输出一个字符
    putchar(b);


    return 0;
}