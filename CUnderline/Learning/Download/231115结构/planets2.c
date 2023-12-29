/**
 * @file planets2.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 字符串数组-指针数组表示
 * @version 1.0
 * @date 2023-11-14
 *
 * @copyright Copyright (C) 2023 白忠建. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

#define N   8

char* planets[10] = {
    "Mercury",
    "Venus",
    "Earth",
    "Mars",
    "Jupiter",
    "Saturn",
    "Uranus",
    "Neptune"
};

/**
 * @brief 打印行星数组
 *
 * @param pl 行星名
 * @param n 行星数
 */
void print_planets(char* pl[10], int n) {
  for (int i = 0; i < n; ++i)
    puts(pl[i]);
  putchar('\n');
}

/**
 * @brief 数组排序
 *
 * @param pl 行星名数组
 * @param n 行星数
 */
void sort_planets(char* pl[10], int n) {
  int i, j;
  char* t;

  for (i = 0; i < n - 1; ++i) {
    for (j = 0; j < n - i - 1; ++j) {
      if (strcmp(pl[j], pl[j + 1]) > 0) {
          // 行星名存储在指针数组中，每个指针指向了一个字面常量字符串，
          // 因此不能交换字符串本身的内容，但可以交换指针的值
        t = pl[j];
        pl[j] = pl[j + 1];
        pl[j + 1] = t;
      }
    }
  }
}

int main() {
  print_planets(planets, N);

  sort_planets(planets, N);

  print_planets(planets, N);

  return 0;
}