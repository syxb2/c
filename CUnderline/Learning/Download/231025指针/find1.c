// 用指针遍历数组

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

  int* p = a;
  // while (*p != key)
  // {
  //     // printf("%d", *p);
  //     if (*p )
  //     ++p;
  // }

  for (p = a; p != a + N; ++p) {
    if (key == *p) {
      // printf("%d\n", (int) (p - a)); // (int) (p - a) - 强制类型转换 -
      // 把？转换为？ // 业务逻辑中最好不要有输入和输出
      found = true;
      break;
    }
  }
  // printf("%d\n", *p);
  // found = true;

  // END OF TODO

  if (!found) {
    printf("not found.\n");
  } else
    printf("%d\n", (int)(p - a));

  return 0;
}
