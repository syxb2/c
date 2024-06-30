#include <stdio.h>
#include <stdlib.h>

#include "dsstring.h"


#define false   0
#define true    1


void del_block(Block **T) {
    Block *temp = *T;
    *T = (*T)->next;
    free(temp);

    return;
}

void move_to_next_block(int* pos, Block** block) {
    if (*pos < BLOCK_SIZE - 1) {
        (*pos)++;
    }
    else {
        *block = (*block)->next;
        *pos = 0;
    }
}

/**
* src为要查找的字符串
* pos为子串开始的下标
* len为子串的长度
* sub在函数调用运行前指向一个已经初始化好的空串，在函数返回时，sub指向串src从第pos个字符起长度为len的子串
* 函数查找成功返回true，参数不正确返回 false
*/
bool blstr_substr(BLString src, int pos, int len, BLString* sub) {
    // 检查参数的合法性。如果位置小于0，或者大于等于源字符串的长度，或者长度小于1，或者子字符串为空，则返回false。
    if (pos < 0 || pos >= src.len || len < 1 || sub == NULL) {
        return false;
    }

    // 为子字符串的头部分配内存。如果分配失败，则返回false。
    sub->head = (Block*) malloc(sizeof(Block));
    if (sub->head == NULL) {
        return false;
    }
    // 初始化子字符串和源字符串的块指针
    Block *sub_block = sub->head, *src_block = src.head;
    // 初始化前一个子字符串块的指针
    Block *prev_sub_block = NULL;

    // 初始化源字符串和子字符串的位置，以及字符计数器
    int src_pos = 0, sub_pos = 0, char_count = 0;

    // 初始化子字符串的下一个块，尾部，和长度
    sub_block->next = NULL;
    sub->tail = sub_block;
    sub->len = 0;

    // 遍历源字符串和子字符串，直到达到指定的位置和长度，或者源字符串结束
    while (char_count < pos + len && src_block != NULL && src_block->ch[src_pos] != BLS_BLANK) {
        if (char_count < pos) {
            // 如果还没有达到指定的位置，就移动到下一个块，并增加字符计数器
            move_to_next_block(&src_pos, &src_block);
            char_count++;
        }
        else {
            // 如果已经达到指定的位置，就将源字符串的字符复制到子字符串，并移动到下一个块
            sub_block->ch[sub_pos] = src_block->ch[src_pos];
            move_to_next_block(&src_pos, &src_block);

            // 如果子字符串的位置还没有达到块的大小，就增加子字符串的位置
            if (sub_pos < BLOCK_SIZE - 1) {
                sub_pos++;
            }
            else {
                // 如果子字符串的位置已经达到块的大小，就为子字符串分配新的块，并重置子字符串的位置
                prev_sub_block = sub_block;
                sub_block->next = (Block*) malloc(sizeof(Block));
                sub_block = sub_block->next;
                sub_block->next = NULL;
                sub_pos = 0;
            }
            // 增加字符计数器和子字符串的长度
            char_count++;
            sub->len++;
        }
    }

    // 处理子字符串的尾部和多余的空间
    if (sub_pos != 0) {
        // 如果子字符串的位置不为0，就将子字符串的尾部设置为当前的块，并将多余的空间填充为空白
        sub->tail = sub_block;
        while (sub_pos < BLOCK_SIZE) {
            sub_block->ch[sub_pos++] = BLS_BLANK;
        }
    }
    else {
        // 如果子字符串的位置为0，就将子字符串的尾部设置为前一个块，并释放当前的块
        if (prev_sub_block != NULL) {
            prev_sub_block->next = NULL;
        }
        sub->tail = prev_sub_block;
        free(sub_block);
    }

    // 返回true表示成功提取子字符串
    return true;
}

int main() {

    return 0;
}