/**
 * @file stack.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 栈的实现代码
 * @version 1.0
 * @date 2023-11-17
 * 
 * @copyright Copyright (C) 2023 白忠建. All rights reserved.
 * 
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>

#include "stack.h"

// 内部函数定义 ----------------------------------------------------------------------------------

// 内部函数被冠以关键字static
// 它们的作用域被限制在本编译单元中
// 在其它编译单元中将这样的内部函数声明为extern将会导致链接错误
// 对于内部函数的命名，我的习惯是用_开头

/**
 * @brief 致命错误处理。此函数将退出程序，永不返回
 * 
 * @param format 错误信息格式
 * @param ... 变长参数包
 */
[[noreturn]] static void _error(const char *format, ...) {
    va_list val;

    va_start(val, format);
    vprintf(format, val);
    va_end(val);

    exit(EXIT_FAILURE);
}


// 接口函数实现 ----------------------------------------------------------------------------------

/**
 * @brief 栈初始化
 * 
 * @param S 栈指针
 */
void stack_init(stackptr S) {
    S->top = -1; // 将栈顶指针置为-1。这意味着，压栈时，先移动栈顶指针，再在该指针处存储数。弹栈时正好相反

// 如果未定义数组版符号
#ifndef _CONTENT_IS_ARRAY
    S->content = (elem_t *)malloc(sizeof(elem_t) * STACK_SIZE); // 为存储分配内容
#endif
}

/**
 * @brief 销毁栈。数组版：无需做任何事情；指针版：释放内存
 * 
 * @param S 栈指针
 */
void stack_destroy(stackptr S) {
// 如果未定义数组版符号
#ifndef _CONTENT_IS_ARRAY
    free(S->content);
#endif
}

/**
 * @brief 压栈。如果栈满，退出程序
 * 
 * @param S 栈指针
 * @param v 待压入的数据
 */
void stack_push(stackptr S, elem_t v) {
    if (stack_full(S)) { // 如果栈满，打印出错信息，退出程序
        _error("Stack overflow. The size of stack is %d\n", STACK_SIZE);
    }

    S->content[++S->top] = v; // 先上浮栈顶指针，再存储数据
}

/**
 * @brief 弹栈。如果栈空，退出程序
 * 
 * @param S 栈指针
 * @return elem_t 栈顶值
 */
elem_t stack_pop(stackptr S) {
    elem_t v = stack_top(S); // 先获取栈顶数据
    --S->top; // 再下浮栈顶指针

    return v;
}

/**
 * @brief 获取栈顶的值，但不弹栈。如果栈空，退出程序
 * 
 * @param S 栈指针
 * @return elem_t 栈顶值
 */
elem_t stack_top(stackptr S) {
    if (stack_empty(S)) { // 如果栈空，打印出错信息，退出程序
        _error("Stack underflow\n");
    }

    return S->content[S->top];
}

/**
 * @brief 判断栈空
 * 
 * @param S 栈指针
 * @return bool 栈空返回true，否则返回false
 */
[[nodiscard]] bool stack_empty(stackptr S) {
    return S->top < 0;
}

/**
 * @brief 判断栈满
 * 
 * @param S 栈指针
 * @return bool 栈满返回true，否则返回false
 */
[[nodiscard]] bool stack_full(stackptr S) {
    return S->top == STACK_SIZE;
}