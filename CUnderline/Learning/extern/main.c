// 这个文件叫做一个编译单元

#include <stdio.h>

/*
int f() {
  static int i = 0;
  // 关键字 static 修饰的变量叫做静态变量 - 拥有静态的存储周期(存储周期默认是运动
  // 的存储周期) - 生命周期被延长 - 静态的生命周期是整个程序（静态变量只会被初始化一次）
  return ++i;
}
*/

/*告知 f() 函数来自另一个编译单元*/

// extern int f(); // external - 外部的

#include "f.h" // 包含自己写的头文件
// <> 表示包含系统头文件；"" 表示包含自己写的头文件

int main() {
  for (int j = 0; j < 3; ++j) {
    printf("%d\n", f());
  }

  return 0;
}