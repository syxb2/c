/**
 * @file stack.h
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 栈：头文件
 * @version 1.0
 * @date 2023-11-17
 * 
 * @copyright Copyright (C) 2023 白忠建. All rights reserved.
 * 
 */

#pragma once

#include <stdbool.h>

// 自定义头文件包含 ------------------------------------------------------------------------------

#if __has_include("elem-type.h") 
// 如果存在自定义头文件，则包含它
#include "elem-type.h"
#else
// 否则，显示定义
typedef elem_t int;
#endif


// 宏定义 ------------------------------------------------------------------------------

// 定义数组版符号。注释掉下面这行，将会启用指针版代码
#define _CONTENT_IS_ARRAY

// 定义栈的大小
#define STACK_SIZE  1024


// 类型定义 ------------------------------------------------------------------------------

// 定义栈和指向栈的指针类型
typedef struct {
// 条件编译
#ifdef _CONTENT_IS_ARRAY
    elem_t content[STACK_SIZE]; // 栈的存储空间。使用数组
#else
    elem_t *content; // 另一种实现：使用指针内存
#endif
    int top;  // 栈顶指针
} stack, *stackptr;


// 接口函数签名 ------------------------------------------------------------------------------

// 栈初始化
extern void stack_init(stackptr S);

// 销毁栈
extern void stack_destroy(stackptr S);

// 压栈
extern void stack_push(stackptr S, elem_t v);

// 弹栈
extern elem_t stack_pop(stackptr S);

// 获取栈顶的值，但不弹栈
extern elem_t stack_top(stackptr S);

// 判断栈空
extern bool stack_empty(stackptr S);

// 判断栈满
extern bool stack_full(stackptr S);
