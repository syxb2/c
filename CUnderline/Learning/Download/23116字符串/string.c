/**
 * @file string.c
 * @author 白忠建 (baizj@uestc.edu.cn)
 * @brief 模仿C的字符串处理函数的实现
 * @version 0.1
 * @date 2023-11-06
 *
 * @copyright Copyright (C) 2023 白忠建. All rights reserved.
 *
 */

#include <stdio.h>

/**
 * @brief 求字符串的长度。不计结尾'\0'
 *
 * @param s 字符串（指针）
 * @return int 字符串长度
 */
int Strlen(const char *s) {
    //TODO
    // int c;
    // for (c = 0; s[c] != "\0"; ++c) {
    //     /* code */
    // }
    // return c;

    const char *p = s;
    while (*p != '\0') { // *p != '\0' <==> *p (c语言把任何不等于 0 的表达式都当做 真)
        ++p;
    }
    return p - s;
}

/**
 * @brief 将源字符串s复制到目的字符串t中
 *
 * @param t 目的字符串
 * @param s 源字符串。注意：是指向常量的指针
 * @return char* 目的字符串
 */
char * Strcpy(char *t, const char *s) { // 目的字符串放在左边，原字符串放在右边
    //TODO
    // int i;
    // for (i = 0;s[i] != '\0'; ++i) {
    //     t[i] = s[i];
    // }
    // t[i] = '\0'; // 一定要给字符串分尾。

    // for (i = 0; (t[i] = s[i]) != '\0'; ++i);

    char *p = t;
    // while ((*p = *s) != '\0') ++p, ++s; // 逗号运算符 - 优先级最低 - 从左到右执行 - 整个表达式的结果是最右边表达式的结果
    // 典型的双指针操作
    // (*p = *s) != '\0' <===> (*p = *s)
    while ((*p = *s)) ++p, ++s; // 先判断再自加
    while ((*p++ = *s++)); // 先自加再判断
    // *p++ - 整个表达式指向的是前面一个单位，p指针自加，指向后一个单位
    return t;
}

/**
 * @brief 比较两个字符串s和t的大小。字符串的比较定义为串的字典序的比较
 *
 * @param s 字符串1
 * @param t 字符串2
 * @return int 比较结果。如果s大于、等于、小于t，分别返回正值、0、负值。注：有些实现中，大于返回1，小于返回-1
 */
int Strcmp(const char *s, const char *t) { // 这里的const使 *s 和 *t 不能被改变（*s = 1 是错的）
    //TODO
    while (*s || *t) {
        // if (*s > *t) {
        //     return 1;
        // } else if (*s < *t) {
        //     return -1;
        // }

        if (*s != *t) {
            return *s - *t; // 这里会使用*s/t指向字符的ascii码来加减
        }

        ++s;
        ++t;
    }
    return 0; // 相同时的返回值
}

/**
 * @brief 字符串拼接：将源字符串s拼接到目的字符串t的尾部（注：要覆盖其封尾0）
 *
 * @param t 目的字符串
 * @param s 源字符串
 * @return char* 目的字符串
 */
char * Strcat(char *t, const char *s) {
    //TODO
    char *p = t; // p是工作指针
    while (*p) ++p;
    Strcpy(p, s);
    return NULL;
}

/**
 * @brief 判断字符ch是否在字符串s中
 *
 * @param s 字符串
 * @param ch 待查找的字符
 * @return char* 如果ch在s中，返回指向ch的指针；否则返回NULL
 */
char * Strchr(const char *s, char ch) {
    //TODO
    return NULL;
}

// 请自行实现如下函数：

/**
 * @brief 将源字符串s的前n个字符依次复制到目的字符串t中，自动封尾。不妨称s的前n个字符组成了一个“子串”
 *
 * @param t 目的字符串
 * @param s 源字符串
 * @param n 子串长度
 * @return char* 目的字符串
 */
char * Strncpy(char *t, const char *s, int n) {
    return NULL;
}

/**
 * @brief 比较字符串s和t的前n个字符。不妨称这前n个字符组成了一个“子串”
 *
 * @param s 字符串1
 * @param t 字符串2
 * @param n 子串长度
 * @return int 比较结果。如果s的子串大于、等于、小于t的，分别返回正值、0、负值。注：有些实现中，大于返回1，小于返回-1
 */
int Strncmp(const char *s, const char *t, int n) {
    return 0;
}

/**
 * @brief 测试函数
 *
 * @return int
 */
int main() {
    char buf[128], buf2[128];
    char *str = buf; // 不能不写 = buf ，否则会成为野指针

    // 输入源字符串
    scanf("%s", str);
    // gets(str);

    // 测试字符串长度
    printf("strlen: %d\n", Strlen(str));

    // // 测试字符串复制
    Strcpy(buf2, str);
    printf("strcpy: %s\n", buf2);

    // // 测试字符串比较
    buf2[0] = buf2[1];
    int k = Strcmp(buf, buf2);
    if (k == 0) {
        printf("strcmp: euqal\n");
    } else if (k > 0) {
        printf("strcmp: greater\n");
    } else {
        printf("strcmp: lesser\n");
    }

    // // 测试字符串拼接
    // printf("strcat: %s\n", Strcat(buf2, "xyz"));

    // // 测试字符查找
    // char ch = '&';
    // char *p = Strchr(buf2, ch);
    // printf("strchr: '%c':%s\n", ch, p ? "found" : "not found");

    return 0;
}