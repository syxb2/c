/**
 * 串比较
 * 不调用库函数，自己实现字符串的比较操作：该操作当比较的两个字符是都是字母，且两个字符互为大小写（如a和A、e和E）时认为两个字符相同，否则不同，其比较结果按这两个字符的原值确定。函数的返回值规定如下：
 * 返回值 < 0：第一个不匹配的字符在 ptr1 中的值低于 ptr2 中的值
 * 返回值 == 0：两个字符串的内容相等
 * 返回值 > 0：第一个不匹配的字符在 ptr1 中的值大于在 ptr2 中的值
 */
#include <stdio.h>
#include <stdlib.h>
#include "dsstring.h" //请不要删除，否则检查不通过

/**
 * @brief 
 * 
 * @param a 
 * @return char 
 */
char EXC(char a) {
    if (a >= 'A' && a <= 'Z') {
        return a - 'A' + 'a';
    }
    else return a;
}

/**
 * @brief 比较字符串
 * 
 * @param ptr1 
 * @param ptr2 
 * @return int 
 */
int str_compare(const char* ptr1, const char* ptr2){
    int i = 0;
    for (i = 0; ptr1[i] != '\0' && ptr2[i] != '\0'; ++i) {
        if (EXC(ptr1[i]) == EXC(ptr2[i])) 
            continue;
        else if (ptr1[i] < ptr2[i])
            return -1;
        else return 1;
    }
    if (ptr1[i] == '\0' && ptr2[i] != '\0') return -1;
    else if (ptr1[i] != '\0' && ptr2[i] == '\0') return 1;

    return 0;
}

int main() {
    const char *str1 = "HelloWorld";
    const char *str2 = "helloworld";
    const char *str3 = "HelloUniverse";
    const char *str4 = "hello";

    printf("Comparing '%s' and '%s': %d\n", str1, str2, str_compare(str1, str2)); // 应该返回 0，因为忽略大小写后相等
    printf("Comparing '%s' and '%s': %d\n", str1, str3, str_compare(str1, str3)); // 应该返回 < 0 或 > 0，取决于不匹配字符的值
    printf("Comparing '%s' and '%s': %d\n", str1, str4, str_compare(str1, str4)); // 应该返回 > 0 或 < 0，因为 str1 比 str4 长

    return 0;
}
