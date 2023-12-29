#include <stdio.h>
//引用头文件“stdio.h”
//.h - headfile

int main() {
//main是函数的名字
//()是函数的标志
//任何函数都是从main的第一行开始，执行到main的最后一行return结束
//int是返回值类型，表示返回值类型为整形

    int a, b;
    //使用int来定义变量
    a = 0;
    b = 0;

    scanf("%d%d", &a, &b);
    //scanf - scan format - 格式化输入
    //双引号扩起来的是字符串
    //”d“代表 decimal 即 十进制
    //”%d“是格式占位符，含义就是要将从键盘输入的这些合法的字符转化成一个十进制数字。（输出时%d会被一个十进制数替换）
    //”&“是一个取地址运算符，&后面加变量名表示“该变量的地址”，所以&a就表示变量 a 的地址。
    //”&a“称为“取地址a”，就相当于将数据存入以变量 a 的地址为地址的变量中。
    //scanf("%d%d", &a, &b);
        //”%d%d“中没有空格，系统默认的分隔符是一个空格
        //若改为”%d,%d“，则运行后输入时要输入”1,1“
    //“\n”是换行符

    printf("%d + %d = %d\n", a, b, a + b);
    //printf - 格式化输出

    return 0;
    //表示返回值为0
    //用来指示main函数执行是否出错，若返回值为0则没有出错，若不为0则可能出错
}