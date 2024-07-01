#include <stdio.h>

struct X {
    int i;
    float d;
};

union Y {
    int i;
    float d;
};
// 联合是一种特殊的结构
// 联合所有的成员都从相同的地址开始 => 联合的大小等于最大的项的大小
// 改变一项其余的项都会随之改变（其余项不一定合法）
// 常用于高级编程中的内存重解释



int main() {
    return 0;
}