#include <stdlib.h>
#include <stdio.h>
#include"dsstring.h" // 请不要删除，否则检查不通过


/**
* src为要查找的字符串
* pos为子串开始的下标
* len为子串的长度
* sub在函数调用运行前指向一个已经初始化好的空串，在函数返回时，sub指向串src从第pos个字符起长度为len的子串
* 函数查找成功返回true，参数不正确返回 false
*/
bool blstr_substr(BLString src, int pos, int len, BLString* sub) {
    // 检查参数合法性
    if (pos < 0 || pos >= src.len || len < 1 || sub == NULL) return false;

    // 初始化子字符串的头指针和源字符串的指针
    sub->head = (Block*) malloc(sizeof(Block));
    if (sub->head == NULL) return false;
    Block *sub_block = sub->head, *src_block = src.head;

    // 初始化尾指针和长度
    sub_block->next = NULL;
    sub->tail = sub_block;
    sub->len = 0;

    // src_pos指示在原字符串中要提取子字符串的位置
    // char_count指示已经遍历过的字符数
    int src_pos = 0, char_count = 0;
    // 跳过前 pos 个字符，到 pos 的位置
    while (char_count < pos) {
        if (src_pos < BLOCK_SIZE - 1) { // 如果当前块未满，继续读取该块的下一个字符
            src_pos++, char_count++;
        }
        else { // 否则，移动到下一个块
            src_block = src_block->next;
            src_pos = 0;
            ++char_count;
        }
    }

    // 循环遍历源字符串和子字符串
    // sub_pos指示在子字符串中要复制字符的位置
    int sub_pos = 0;
    while (char_count < pos + len && src_block != NULL && src_block->ch[src_pos] != BLS_BLANK) {
        //* 复制字符
        sub_block->ch[sub_pos] = src_block->ch[src_pos]; // 复制当前字符
        sub->len++, char_count++;

        //* 移动指针
        if (src_pos < BLOCK_SIZE - 1) src_pos++; // 原字符串块：如果当前块未满，继续读取该块的下一个字符
        else { // 否则，移动到下一个块
            src_block = src_block->next;
            src_pos = 0;
        }
        if (sub_pos < BLOCK_SIZE - 1) sub_pos++; // 子字符串块：如果当前块未满，继续复制到当前块
        else { // 否则，分配新块
            sub_block->next = (Block*) malloc(sizeof(Block));
            sub_block = sub_block->next;
            sub_block->next = NULL;
            sub_pos = 0;
        }
    }

    // 处理尾指针和多余的空间
    if (sub_pos != 0) { // 如果最后一个块未满，用 BLS_BLANK 填充
        sub->tail = sub_block;
        while (sub_pos < BLOCK_SIZE) {
            sub_block->ch[sub_pos] = BLS_BLANK;
            ++sub_pos;
        }
    }
    else { // 如果最后一个块是空的，删除该块
        // 遍历找到最后一个块的前一个块
        sub->tail = sub->head;

        while (sub->tail->next != sub_block)
            sub->tail = sub->tail->next;
        sub->tail->next = NULL;

        free(sub_block);
    }

    return true;
}
