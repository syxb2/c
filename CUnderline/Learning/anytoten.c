#include <stdio.h>

/*
int main() {
  int x, p;   //x输入数字  p该数的进制数
  scanf("%d", &x);
  scanf("%d", &p);
  int y = 0, product = 1;
  while (x != 0) {
    y = y + (x % 10) * product;
    x = x / 10;
    product = product * p;
  }
  printf("%d\n", y);

  return 0;
}
*/

int main() {
  int in, p;
  scanf("%d%d", &in, &p);
  int out = 0, product = 1;
  while (in != 0) {
    out = out + (in % 10) * product;
    in /= 10;
    product *= p;
  }
  printf("%d\n", out);

  return 0;
}