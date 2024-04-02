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