/**
 * 串替换
 * 函数返回成功替换的次数，即有多少个子串被成功替换
 * 在替换过程中，任何情况下所得字符串（及结束符）不应该超过 outlen，如果某次替换所得字符串的长度超过 outlen，则不进行这次替换操作，整个替换操作结束。如：
 * 原始串为 "aaabbbccc"，outlen 为14, oldstr 为 "c"，newstr 为 "333" 时，两次替换后得 "aaabbb333333c"，此时字符串占用空间为14字节。
 * 如果再进行替换，则会超出 out 所占用的空间，所以停止替换操作。此时函数应该返回 2, out指向的串为 "aaabbb333333c"
 * 再如：原始串为 "aaabbbccc"，outlen 为10, oldstr 为 "b"，newstr 为 "123456"，进行替换后所得的串长度为14，与结束符一共占 15 个字节，超过outlen的10字节，此时不进行替换，函数应该返回 0
 */
#include <stdio.h>
#include <stdlib.h>
#include "dsstring.h"


/**
 * @brief 计算字符串长度
 *
 * @param s
 * @return int
 */
int len(const char *s) {
    int i = 0;
    const char *p = s;
    while (*p != '\0') {
        ++p;
        ++i;
    }

    return i;
}

/**
 * in, 原始字符串，保持不变
 * out, 存放替换结果的字符串
 * outlen, out 空间的大小
 * oldstr, 要替换的旧字符串
 * newstr, 替换成的新字符串
 * 函数返回成功替换的次数，即有多少个子串被成功替换
 */
int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr) {
    int replace_count = 0; // 替换次数
    int now_len = len(in); // 当前 out 输出时的长度
    int oldstr_len = len(oldstr); // oldstr 的长度
    int newstr_len = len(newstr);
    const char *p_oldstr = oldstr;
    const char *p_newstr = newstr;
    const char *p_in = in; // p - 前驱指针
    const char *q_in = NULL; // q - 后驱指针

    // 初始化输出字符串为全零
    for (int i = 0; i < outlen; i++) {
        out[i] = '\0';
    }

    while (*p_in != '\0') {
        if (*p_in != *p_oldstr) { // 如果没有查找到子串的倾向
            *out = *p_in;
            ++out, ++p_in;
        }
        else { // 如果有查找到子串的倾向，即第一个字符相等
            // int temp_len = 1;
            q_in = p_in + 1;
            ++p_oldstr;

            while (*q_in == *p_oldstr && *p_oldstr != '\0') ++q_in, ++p_oldstr; // 看是否存在整个子串 
            if (*p_oldstr == '\0') { // 查找到子串
                if (now_len + newstr_len - oldstr_len >= outlen) {
                    while (*p_in != '\0') {
                        *out = *p_in;
                        ++out, ++p_in;
                    }
                    return replace_count; // 如果超出长度，则返回
                }
                // 首先输入子串到 out
                while (*p_newstr != '\0') {
                    *out = *p_newstr;
                    ++out, ++p_newstr;
                }
                ++replace_count;
                now_len = now_len + newstr_len - oldstr_len;
                p_in += oldstr_len;
            }
            else {
                *out = *p_in;
                ++p_in, ++out;
            }
            p_oldstr = oldstr;
            p_newstr = newstr;
        }
    }

    return replace_count;
}

int main() {
    const char *input = "aaabbbccc";
    char output[50]; // 分配足够大的空间以存储替换后的字符串
    const char *oldString = "cc";
    const char *newString = "1234567";
    int outlen = 14; // 定义输出字符串的最大长度

    int replaceCount = str_replace(input, output, outlen, oldString, newString);

    printf("Original string: %s\n", input);
    printf("Modified string: %s\n", output);
    printf("Total replacements: %d\n", replaceCount);

    return 0;
}
