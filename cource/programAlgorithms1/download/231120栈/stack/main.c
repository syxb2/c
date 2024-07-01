/**
 * @file main.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 演示栈的程序
 * @version 1.0
 * @date 2023-11-17
 * 
 * @copyright Copyright (C) 2023 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>

#include "stack.h"

stack s, *S = &s;

int main() {
#ifdef _CONTENT_IS_ARRAY
    printf("Array version\n");
#else
    printf("Pointer version\n");
#endif

    stack_init(S);

    printf("pushing...\t");
    const int n = 6;
    int i;
    for (i = 0; i < n; ++i) {
        printf("%4d", i);
        stack_push(S, i);
    }
    putchar('\n');

    printf("popping...\t");
    for (i = 0; i < n; ++i)
        printf("%4d", stack_pop(S));
    putchar('\n');

    // stack_pop(S); // cause error

    stack_destroy(S);

    return 0;
}