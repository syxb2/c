//计算三角形面积

# include <stdio.h>

int main() {
    float width, height, area;

    scanf("%f%f", &width, &height);
    //scanf函数后边括号中是`格式字符串`
    //如果格式字符串中有不属于格式占位符的符号，输入时要原样输入。
    area = width * height / 2.0f;
    //"="是赋值符号
        //右值：只能出现在赋值号右边（所有的字面值`literal`都是右值，都是常量`constent`）
            //如“2”
        //左值：既可以出现在赋值号左边也可以出现在赋值号右边
    //"2.0f"可以把2.0这个float型的数据转变为float类型
    printf("area = %.2f\n", area);
    //"%.2f"表示float类型保留两位小数

//不同类型的数据之间的运算
    //原则：范围小的向范围大的类型转换

    return 0;
}
//标志符：程序中出现的词。
//关键字：如include，int，main等。标志符不能是关键字