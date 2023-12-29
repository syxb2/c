#include <stdio.h>

#define ROW 3
#define COL 4

// 遍历二维数组：
int main() {
  int a[ROW][COL] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  int(*p)[COL], *q;

  for (p = a; p != a + ROW; ++p) {
    for (q = *p; q != *p + COL; ++q) printf("%4d", *q);
    putchar('\n');
  }

  return 0;
}