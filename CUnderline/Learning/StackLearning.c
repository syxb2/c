#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//定义栈 
typedef struct {
    char data[100];
    int top;
    int bottom;
}stack;

//创建栈
stack *StackCreate() {
    stack *p = (stack*) malloc(sizeof(stack));//分配新空间 
    if (p == NULL)//分配失败 
        return 0;
    p->bottom = p->top = 0;//分配成功 
    return p;
}

//入栈
void StackInput(stack *p, char str) {
    p->data[p->top] = str;//存入栈中 
    p->top++;//栈顶指针加1 
}

//出栈 
char StackOutput(stack *p, char str) {
    if (p->top != p->bottom) {//栈非空 
        str = p->data[p->top - 1];//栈顶内容输出 
        p->top--;//栈顶减1 
        return str;
    }
}

//输出 
void StackPrint(stack *p) {
    while (p->top != p->bottom) {
        printf("%c", p->data[p->top - 1]);
        p->top--;
    }
}

//主函数 
int main() {
    int i;
    stack *p;//定义栈名 
    char a[10] = "asdfgh";
    p = StackCreate();//创建栈 	 
    for (i = 0; i < strlen(a); i++)//将字符串a的字符入栈 
        StackInput(p, a[i]);
    printf("输出栈中所有字符：\n");
    StackPrint(p);
}


