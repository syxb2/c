/**
 * @file list-origin.c
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

#include "list.h"

void print(elem_t* v) {
  printf("%4d", *v);
}

void print_list(listptr L) {
  list_traverse(L, print);
  putchar('\n');
}

int main() {
#define N   10
  int a[N] = { 0, 9, 2, 7, 4, 5, 6, 3, 8, 1 };

  list l, *L = &l;

  list_init(L);
  list_create(L, a, N);
  print_list(L);

  list_push_front(L, -2);
  print_list(L);

  list_insert(L, 2, 11);
  print_list(L);

  // list_remove(L, list_length(L));
  // print_list(L);

  // list_insert(L, list_length(L) + 1, 1);
  // print_list(L);

  // list_remove(L, 100); // cause exception

  list_destroy(L);

  return 0;
}
