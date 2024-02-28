// #include <stdio.h>
// void swap(int x, int y) {
//   int t = x;
//   x = y;
//   y = t;
//   // return (x, y);
// }
// int main() {
//   int a = 0, b = 0;
//   scanf("%d%d", &a, &b);
//   swap(a, b);
//   printf("%d%d\n", a, b);

//   return 0;
// }
// 形式参数是实际参数的副本，形式参数的改变不会影响实际参数

// 所以要这么写

// 指针作为参数来进行实际参数与形式参数的传递
// #include <stdio.h>
// void swap(int* x, int* y) {
//   int t = *x;
//   *x = *y;
//   *y = t;
//   // return (x, y);
// }

// int main() {
//   int a = 0, b = 0;
//   scanf("%d%d", &a, &b);
//   swap(&a, &b);
//   printf("%d%d\n", a, b);

//   return 0;
// }

// 指针作为形式参数具有潜在的改变实际参数的“副”作用

/* ----------------const约束------------------*/

#include <stdio.h>

void print(const int* x) {
  // 这里x的基类型是 const int *
  // const约束的是int（因为int和*是两个独立的东西)
  // 会导致'*x'即x指向的整形不可被改变 x是一个指向常量整数的变量指针
    int z = 0;
    *x = 1;
    x = &z;
    z = 1;
    // *x = 1; // 错的
    printf("%d\n", *x);
}
// 不同的名字访问同一个单元，这个单元就要根据名字进行重解释

// 如果是(int const *x)

int main() {
    return 0;
}