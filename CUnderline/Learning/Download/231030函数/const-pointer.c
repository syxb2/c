//const-pointer.c

/*
    本程序演示了指针用const约束时的情况
*/

typedef int* INTP;

int main() {
    int i = 0;
    int j = 1;
    
    // --- case 1
    const int *p = &i; // 指向常量的变量指针：const修饰的是int
    *p = 1; // error：在p“眼里”，它指向的是个常量
    p = &j; // OK, p本身是变量，可以指向其它整数变量

    // --- case 2
    // const int 和 int const是等价的！
    const int a = 0;
    int const b = 0; // 等价于：const int b = 0;

    // case 2 涉及的内容，我在课堂上说，const修饰的是*。这是错误的！！！
    // 这里，我诚挚地向大家道歉，同时向指出这个问题的同学表示深深的感谢！
    int const *q = &i; // 等价于 const int *q，q是指向常量的变量指针。
    *q = 1; // error：在p“眼里”，它指向的是个常量
    q = &j; // OK, p本身是变量，可以指向其它整数变量

    // --- case 3
    // case 3 涉及的内容，我在课堂上讲的也有些模糊甚至错误。这里给出更清晰的解释。同样向大家道歉！
    int * const t = &i; // 指向了变量单元的常量指针：const修饰的是int *。
    // 这说明int *是个常量，即指针是常量；而该指针的基类型是int，没有const约束，因此是变量
    *t = 1; // OK，t是常量，但它指向的变量
    t = &j; // error，t是常量不能修改

    // --- case 4
    const INTP x = &i; // 等价于：int * const x;
    INTP const y = &j; // 等价于：int * const y;
    *x = 1; // OK
    *y = 2; // OK
    x = &j; // error
    y = &i; // error

    return 0;
}

// 以下展示指针作为参数的情况。
// 以下，f1和f2的参数列表等价
void f1(const int *x) { // case 1
    int i = -1;
    *x = i; // error
    x = &i; // OK
} 

void f2(int const *x) { // case 2
    int i = -1;
    *x = i; // error
    x = &i; // OK
}

// 以下，f3、f4和f5的参数列表等价
void f3(int * const x) { // case 3
    int i = -1;
    *x = i; // OK
    x = &i; // error
}

void f4(const INTP x) { // case 4
    int i = -1;
    *x = i; // OK
    x = &i; // error
} 

void f5(INTP const x) { // case 4
    int i = -1;
    *x = i; // OK
    x = &i; // error
}