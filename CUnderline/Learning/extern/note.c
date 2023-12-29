#include <stdio.h>

int i = -1; // 这里的 i 不属于任何函数，而属于这个编译单元(这个文件)。它的作用域叫做文件作用域，叫做全局作用域。

int main() {
  int i = 0; // i 叫局部变量 - 作用域是所在的函数
  // 局部变量会 掩盖 全局变量(局部变量的优先级更高)

  printf("%d\n", ++i); // 这里的 i 使用的是局部变量

  // 这种情况下就很难使用 i 这个全局变量了。除非把 int i = 0; 放到 printf 下边。

  return 0;
}

// 自动变量在栈中分配


#include <stdio.h>

int i = -1;

int main() {
  int i = 0;

  {
    int i = 1;
    printf("%d\n", ++i);
  }
  // 一个 {} 就是一个作用域
  // 这里的 {} 就是 i 的生命周期

  return 0;
}

int i = 2; // 这里只有36行之后的程序才对 i 可见