// swap-by-pointer.c

#include <stdio.h>

/*
    1. 通过形参指针，间接修改实参
    2. 指针参数具有潜在的将（多个）计算结果携带出函数的能力
*/
void swap(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}

int main() {
  int a, b;

  scanf("%d%d", &a, &b);
  printf("a=%d, b=%d\n", a, b);
  swap(&a, &b);
  printf("a=%d, b=%d\n", a, b);

  return 0;
}