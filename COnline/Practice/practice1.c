#include <stdio.h>
int main() {
    int a = 0;
    int b = 0;
    int sum = 0;
    scanf("%d %d", &a, &b);
    //scanf函数是输入函数
    //两个%d中间一个空格表示要求输入两个整型且两个整型之间用空格隔开
    //"&a, &b"表示第一个整型放到a中，第二个整型放到b中
    sum = a + b;
    printf("sum = %d\n", sum);
    return 0;
}