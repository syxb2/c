/*
栈 后缀表达式计算

请使用已定义好的栈完成后缀表达式计算：
(1)如果是操作数，直接入栈
(2)如果是操作符op，连续出栈两次，得到操作数x 和 y,计算 x op y，并将结果入栈。

后缀表达式示例如下：
9  3  1  -  3  *  +  10  2  /  +
13  445  +  51  /  6  -
操作数、操作符之间由空格隔开，操作符有 +，-，*, /, %共 5 种符号，所有操作数都为整型。

栈的定义如下：

#define Stack_Size 50
typedef struct{
    ElemType elem[Stack_Size];
    int top;
}Stack;

bool push(Stack* S, ElemType x);
bool pop(Stack* S, ElemType *x);
void init_stack(Stack *S);
其中，栈初始化的实现为：

void init_stack(Stack *S){
    S->top = -1;
}
需要完成的函数定义为：int compute_reverse_polish_notation(char *str);

函数接收一个字符指针，该指针指向一个字符串形式的后缀表达式，函数返回该表达式的计算结果。
*/

#include <stdio.h>
#include <stdlib.h>

#define Stack_Size 50
#define ElemType int

typedef struct {
    ElemType elem[Stack_Size];
    int top;
} Stack;

Stack s;

bool push(Stack* S, ElemType x) {
    S->elem[++S->top] = x;

    return 1;
}

bool pop(Stack* S, ElemType *x) {
    *x = S->elem[S->top];
    --S->top;

    return 1;
}

void init_stack(Stack *S) {
    S->top = -1;
}

int compute_reverse_polish_notation(char *str) {
    int res = 0;
    for (; *str != '\0';) {
        if (*str == ' ') ++str;
        for (; *str != ' ' && *str != '\0';) {
            int temp_res = 0;
            int a, b;
            switch (*str) {
                case '+':
                    pop(&s, &a);
                    pop(&s, &b);
                    push(&s, b + a);
                    ++str;
                    break;
                case '-':
                    pop(&s, &a);
                    pop(&s, &b);
                    push(&s, b - a);
                    ++str;
                    break;
                case '*':
                    pop(&s, &a);
                    pop(&s, &b);
                    push(&s, b * a);
                    ++str;
                    break;
                case '/':
                    pop(&s, &a);
                    pop(&s, &b);
                    push(&s, b / a);
                    ++str;
                    break;
                case '%':
                    pop(&s, &a);
                    pop(&s, &b);
                    push(&s, b % a);
                    ++str;
                    break;
                default:
                    for (; *str != ' ' && *str != '\0';) {
                        int temp = *str - '0';
                        temp_res += temp;
                        ++str;
                        if (*str != ' ' && *str != '\0') {
                            temp_res *= 10;
                        }
                    }
                    push(&s, temp_res);

            }
        }
    }
    pop(&s, &res);

    return res;
}

int main() {
    char arr[Stack_Size];
    gets(arr);
    init_stack(&s);
    printf("%d\n", compute_reverse_polish_notation(arr));

    return 0;
}