#include <stdio.h>

/*
int main() {
  int x, p; //x为十进制数，p为目标进制大小
  scanf("%d", &x);
  scanf("%d", &p);
  int a[256]; //存放余数
  int count = 0;
  do {
    a[count++] = x % p; // 这里count++这个式子的值为count自加前的值
    x = x / p;
  } while (x != 0); //当商不为0时进行循环

  for (int i = count - 1; i >= 0; i--) {
    printf("%d", a[i]);
  }
  printf("\n");

  return 0;
}
*/

#include <stdio.h>

int main() {
    int in, p;
    int arr[256] = { 0 };
    scanf("%d%d", &in, &p);
    int count = 0;
    do {
        arr[count++] = in % p;
        in /= p;
    } while (in != 0);

    for (int i = count - 1; i != -1; --i) {
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}

