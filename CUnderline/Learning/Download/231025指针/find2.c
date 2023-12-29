/* <--------------折半查找法--------------> */

#include <stdbool.h>
#include <stdio.h>

#define N 10

int main() {
  int a[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int key;

  printf("please input a number: ");
  scanf("%d", &key);

  bool found = false;

  // TODO：在数组a中查找key是否存在。如果存在，将found置为true，并输出key的下标

  int *p = a;
  for (p = a; p != a + N; ++p) {
    if (key == *p) {
      // printf("%d\n", (int)(p - a)); // int (p - a) - 强制类型转换 -
      // 把？转换为？ // 业务逻辑中最好不要有输入和输出
      found = true;
      break;
    }
  }
  int *l = a, *r = a + N - 1, *m;
  while (l <= r) {
    /* code */
    m = l + (r - l) / 2;
    if (key == *m) {
      found = true;
      break;
    } else if (key > *m) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  // END OF TODO

  if (!found)
    printf("not found.\n");
  else {
    int temp = 0;
    temp = m - a;
    printf("%d\n", temp);
    // 等价于：printf("%d\n", (int)(m - a));
  }

  return 0;
}