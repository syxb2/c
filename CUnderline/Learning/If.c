#include <stdio.h>

int main()
{
    int score;
    char level;

    scanf("%d", &score);

    switch (score / 10) // switch（匹配），看score这个变量和哪个case匹配 // 用switch case时必须要把一个区间映射到一个单点上时
    {
    case 10:
    case 9: // case后必须跟整型常量
        level = 'A';
        break;
    case 8:
        level = 'B';
        break;
    case 7:
        level = 'C';
        break;
    case 6:
        level = 'D';
        break;
    default:
        level = 'F';

        // switch case的一个特点：下落(fallthrough)（会一直判断所有的case，直到结束）（如果不加break的话会进行到default从而将level赋值为F）
        // case标号和default标号只能出现在switch语句下
        // 能用switch case的尽量用switch case
    }

    printf("%c\n", level);

    // if (score >= 90)
    //     level = 'A'; // if语句下面的函数叫做if的子分支。
    // // 只要if语句从上到下开始判断，遇到真条件即执行，执行后下面的条件不再判断，直接跳过。
    // else if (score >= 80)
    //     level = 'B';
    // else if (score >= 70)
    //     level = 'C';
    // else if (score >= 60)
    //     level = 'D';
    // else // 多分支的if语句中，else语句可以省略
    //     level = 'F';

    // printf("%c\n", level);

    // {
    //     if (score >= 80)
    //         printf("B\n");
    //     else
    //         ;
    // }
    // printf("failed\n");
    // if是主语句。else不是语句，而是从句（else不能单独成为一条语句）

    // // c语言中存在替代if else双分支的运算符`?`和`:` - 叫做条件运算符
    // printf(score >= 60 ? "pass\n" : "failed\\n"); // 意思是如果表达式为真，结果就是`?`后面的值；如果表达式为假，结果就是`:`后面的值。 // 等价于上面的if else
    // // 但是最好还是写if else，更加易读

    return 0;
}