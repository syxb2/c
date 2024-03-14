#include <stdio.h>

#define N 10

// void print_f(int a[N], int n) {
// void print_r(int *a, int n) {
void print_r(int a[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d ", a[i]);
  }
  putchar('\n');
}

void reverse(int *l, int *r) {
  // int *l = a, *r = a + N - 1;
  while (l <= r) {
    int t = *l;
    *l = *r;
    *r = t;
    ++l;
    --r;
  }
}
// 在数组/指针中形式参数就是实际参数

int main() {
  int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  // int temp[N] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  // for (int i = 0; i < n; ++i) {
  //   printf("%d ", a[i]);
  // }
  // putchar('\n');

  print_r(a, N);

  // todo：将数组a逆序
  // for (int i = 0; i < n; ++i)
  // {
  //     temp[i] = a[i];
  // }
  // for (int i = 0; i < N; ++i)
  // {
  //     a[i] = temp[9 - i];
  // }

  // int *l = a, *r = a + N - 1;  // ’*r = a + N‘ - 指向数组的‘哨兵’；‘*r = N +
  // a -
  //                              // 1' - r指向数组的最后一位
  // while (l <= r) {
  //   int t = *l;
  //   *l = *r;
  //   *r = t;
  //   ++l;
  //   --r;
  // }

  reverse(a, a + N - 1);

  // END OF TODO

  // for (int i = 0; i < n; ++i) {
  //   printf("%d ", a[i]);
  // }
  // putchar('\n');

  print_r(a, N);

  return 0;
}