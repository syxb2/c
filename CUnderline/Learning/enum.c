#include <stdio.h>

enum traffic {
  RED, //默认为0
  AMBER = 3, // 默认为上（前）一项加1 - 这样GREEN的值为4
  GREEN
  // 这三个东西是常量，默认为0
}; // 定义枚举常量
// enum这个类型默认是匿名的
// traffic 是枚举标志名
// 枚举的项都等同于整形（它们是等价的）（c++的枚举不等于整形），可以用在整形可使用的任何地方 - 只是用特定的字母代替一些整形
// 枚举常量的作用域是全局的

int main() {
  enum traffic light;

  return 0;
}