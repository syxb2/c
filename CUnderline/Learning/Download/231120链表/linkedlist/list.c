/**
 * @file list.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 单链表演示程序
 * @version 1.0
 * @date 2023-11-16
 *
 * @copyright Copyright (C) 2023 白忠建. All rights reserved.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "list.h"

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

/**
 * @brief 生成新结点并填充
 *
 * @param L 链表指针
 * @param v 新结点的数据值
 * @return nodeptr 新结点指针。返回值不能被丢弃
 */
[[nodiscard]] static nodeptr _make_node(listptr L, elem_t v) {
  nodeptr p = (nodeptr) malloc(sizeof(node)); // 为节点动态分配内存
  p->data = v; // 填充数据域
  p->next = L->sentinel; // 填充指针域
  // *p = (node){v, L->sentinel}; // 另一种填充方法
  return p;
}

/**
 * @brief 生成新节点p，然后在当前结点cur后插入结点p。
 *
 * @param L 链表指针
 * @param cur 当前结点
 * @param v 新节点的数据值
 */
static void _link_after(listptr L, nodeptr cur, const elem_t v) {
/*
 * 如图所示，节点X插入到A之后、B之前
 * 插入前：
 * ---> A ---> B ---> C ---> ...
 *      ↑
 *     cur     p ---> X ---> NULL
 *
 * 插入后：
 * ---> A      B ---> C ---> ...
 *      ↑\      ↖_______
 *      | \__________    \
 *      |            ↘   |
 *     cur     p ---> X -
 */
  // TODO：4条语句
  // nodeptr p = (nodeptr) malloc(sizeof(node));
  // p->data = v;
  // p->next = cur->next;
  // cur->next = p;
  nodeptr p = _make_node(L, v);
  p->next = cur->next;
  cur->next = p;
  ++L->length;
}

/**
 * @brief 指针从当前位置p向前移动n步
 *
 * @param L 链表指针
 * @param p 指向结点的指针
 * @param n 步数
 * @return nodeptr 移动后的结点指针。返回值不能被丢弃
 */
[[nodiscard]] static nodeptr _advance(listptr L, nodeptr p, int n) {
  // TODO：3条语句
  if (n < 0 || n > L->length + 1) {
    _error("invalid advance step %d\n", n);
  }
  for (int i = 1; i < n; ++i) { // i 从 1 开始，因为要移动 n-1 步
    p = p->next;
  }
  return p;
}

/**
 * @brief 在当前结点cur之后删除结点。
 *
 * @param L 链表指针
 * @param cur 当前结点
 */
static void _remove_after(listptr L, nodeptr cur) {
/*
 * 删除前：
 * ---> A ---> B ---> C ---> ...
 *      ↑      ↑
 *     cur     p
 *
 * 删除后：
 *             X
 * ---> A      B      C ---> ...
 *      ↑\___________↗
 *      |
 *     cur
 */
  // TODO：4条语句
  nodeptr p = cur->next;
  cur->next = p->next;
  free(p);
  --L->length;
}


// 接口函数实现 ----------------------------------------------------------------------------------

/**
 * @brief 链表初始化。生成链表的头结点
 *
 * @param L 链表指针
 */
void list_init(listptr L) {
  L->head = _make_node(L, (elem_t) {
    0
  }); // (elem_t){}：产生一个空初始化后的对象。请思考：为什么用空初始化？
  L->sentinel = NULL; // 单链表的哨兵一般都是NULL
  L->length = 0;
}

/**
 * @brief 销毁链表
 *
 * @param L 链表指针
 */
void list_destroy(listptr L) {
  // TODO
  list_clear(L);
  free(L->head);
}

/**
 * @brief 根据数组创建链表
 *
 * @param L 链表指针
 * @param a 保存数据的数组
 * @param n 数组长度
 */
void list_create(listptr L, elem_t *a, size_t n) {
  nodeptr p = L->head;
  for (size_t i = 0; i < n; ++i) {
    _link_after(L, p, a[i]);
    p = p->next;
  }
  p->next = L->sentinel;
}

/**
 * @brief 在链表头部插入结点
 *
 * @param L 链表指针
 * @param v 数据值
 */
void list_push_front(listptr L, const elem_t v) {
  // TODO：1条语句
  _link_after(L, L->head, v);
}

/**
 * @brief 在指定位置插入结点
 *
 * @param L 链表指针
 * @param pos 位置。从1开始
 * @param v 数据值
 */
void list_insert(listptr L, int pos, const elem_t v) { // pos的取值为 1 到 length+1 ,若为 1 则在第一个结点之前插入一个结点
  // TODO：1条语句
  _link_after(L, _advance(L, L->head, pos), v);
}

// 在链表指定位置删除结点
void list_remove(listptr L, int pos) {
   // TODO：1条语句
}

/**
 * @brief 获取链表的长度
 *
 * @param L 链表指针
 * @return size_t 链表长度
 */
size_t list_length(listptr L) {
  return L->length;
}

/**
 * @brief 判断链表是否为空
 *
 * @param L 链表指针
 * @return bool 为空返回true，否则返回false
 */
bool list_empty(listptr L) {
  return L->length == 0; // 条件表达式的返回值类型就是布尔类型（true or false）
}

/**
 * @brief 清空链表
 *
 * @param L 链表指针
 */
void list_clear(listptr L) {
  // TODO：2条语句
  while (!list_empty(L)) {
    _remove_after(L, L->head);
  }
  L->head->next = L->sentinel;
}

/**
 * @brief 遍历链表
 *
 * @param L 链表指针
 * @param visit 访问结点的回调函数
 */
void list_traverse(listptr L, callback visit) {
  for (nodeptr p = L->head->next; p != L->sentinel; p = p->next) {
    visit(&p->data);
  }
}