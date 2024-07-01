/**
 * @file planets3.c
 * @author 白忠建 ^_^ (baizj@uestc.edu.cn)
 * @brief 结构及结构数组
 * @version 1.0
 * @date 2023-11-14
 *
 * @copyright Copyright (C) 2023 白忠建. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

#define N 8

// 定义结构类型
struct planets_tag {
  char name[8];     // 行星名
  char symbol[4];   // 符号
  float mass;       // 质量（相对于地球）
  unsigned radius;  // 半径
  unsigned moons;   // 卫星数
};

// 定义结构类型的别名
typedef struct planets_tag planets_t;

// 定义结构数组并初始化
planets_t planets[N] = {
  {"Mercury", "☿", 0.05f, 2440, 0},
  {"Venus", "♀", 0.82f, 6052, 0},
  {"Earth", "⊕", 1.0f, 6378, 1},
  {"Mars", "♂", 0.11f, 3398, 2},
  {"Jupiter", "♃", 317.94f, 71492, 79},
  {"Saturn", "♄", 95.1f, 60268, 83},
  {"Uranus", "♅", 14.6f, 25559, 29},
  {"Neptune", "♆", 17.2f, 24718, 14}
};

/**
 * @brief 打印行星信息
 *
 * @param pl 行星信息数组
 * @param n 行星数
 */
void print_planets(planets_t pl[], int n) {
  // 打印表头
  printf("\033[92mName\tSymbol\t  Mass\tRadius\t  Moons\n");
  printf("----------------------------------------\033[0m\n");
  // TODO
  // for (int i = 0; i < N; ++i) {
  //     printf("%s\t  %s\t%6.2f\t%6u\t%5u\n",
  //         pl[i].name,
  //         pl[i].symbol,
  //         pl[i].mass,
  //         pl[i].radius,
  //         pl[i].moons
  //     ); // \t是制表符，用来对齐
  for (planets_t *p = pl; p != pl + n; ++p) {  // pl+n 是这个数组的哨兵
    printf("%s\t  %s\t%6.2f\t%6u\t%5u\n", p->name, p->symbol, p->mass, p->radius, p->moons);
  }

  putchar('\n');
}

typedef int cmp_fn(planets_t *, planets_t *);

int compare_mass(planets_t *a, planets_t *b) {
  return a->mass - b->mass;
}

int compare_moons(planets_t *a, planets_t *b) {
  return a->moons - b->moons;
}

/**
 * @brief 数组排序
 *
 * @param pl 行星信息数组
 * @param n 行星数
 */
void sort_planets(planets_t pl[], int n, cmp_fn compare) {
  int i, j;
  [[maybe_unused]] planets_t t;

  for (i = 0; i < n - 1; ++i) {
    for (j = 0; j < n - i - 1; ++j) {
      if (compare(&pl[j], &pl[j + 1]) > 0) {
        // TODO
        t = pl[j];
        pl[j] = pl[j + 1];
        pl[j + 1] = t;
      }
    }
  }
}

int main() {
  print_planets(planets, N);

  sort_planets(planets, N, compare_mass);
  print_planets(planets, N);

  sort_planets(planets, N, compare_moons);
  print_planets(planets, N);

  return 0;
}