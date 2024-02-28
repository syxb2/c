// #include <stdio.h>

// int main() {

//     {
//         int a = 0;
//     }
//     printf("%d\n", a);

//     return 0;
// }

// #include <stdio.h>

// int a = 0; // 声明全局变量a

// // 执行性的代码必须写在主函数的里面

// int main() {

//     printf("%d\n", a);
//     return 0;
// }

#include <stdio.h>

int main() {
    {
        int a = 0;
        printf("%d\n", a);
    }

    return 0;
}