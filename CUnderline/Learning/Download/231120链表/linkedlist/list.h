/**
 * @file list.h
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 单链表演示程序：头文件
 * @version 1.0
 * @date 2023-11-16
 *
 * @copyright Copyright (C) 2023 白忠建. All rights reserved.
 *
 */

#pragma once

#include <stdio.h>
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


// 类型定义 ------------------------------------------------------------------------------

struct node; // 结点类型的超前声明
// 定义指向结点的指针类型
typedef struct node* nodeptr;

// 定义链表结点类型。与超前声明的类型名应该完全一致
typedef struct node {
  elem_t data;    // 结点的数据域
  nodeptr next;   // 结点的指针域，指向下一个结点
} node;

// 定义单向链表类型，以及指向链表的指针类型
typedef struct {
  nodeptr head;       // 指向头结点的指针
  nodeptr sentinel;   // 链表的哨兵(sentinel)。单链表的哨兵一般都是NULL
  size_t length;      // 链表长度。尺寸相关的数据，类型一般都是size_t
} list, *listptr;

// 定义回调函数类型。回调函数将作为另一个函数的参数
// callback是个函数**类型**。这类函数是这样的：带有一个elem_t*参数，无返回值
// 例如：void print(elem_t *v); 就是这种类型的函数
typedef void callback(elem_t*);


// 接口函数签名 ------------------------------------------------------------------------------(告诉编译器这几个函数是外部函数，包含在别的.c文件中)

// 链表初始化
extern void list_init(listptr L);

// 销毁链表
extern void list_destroy(listptr L);

// 根据数组创建链表
extern void list_create(listptr L, elem_t *a, size_t n);

// 在链表头部插入结点
extern void list_push_front(listptr L, const elem_t v);

// 在链表尾部插入结点
// extern void list_push_back(listptr L, const elem_t v);

// 在链表指定位置插入结点
extern void list_insert(listptr L, int pos, const elem_t v);

// 在链表指定位置删除结点
extern void list_remove(listptr L, int pos);

// 获取链表的长度
extern size_t list_length(listptr L);

// 判断链表是否为空
extern bool list_empty(listptr L);

// 清空链表
extern void list_clear(listptr L);

// 遍历链表
extern void list_traverse(listptr L, callback visit);