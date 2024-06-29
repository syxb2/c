#pragma once

#include <stdio.h>
#include <stdlib.h>


#define BLOCK_SIZE 4    // 可由用户定义的块大小
#define BLS_BLANK '#'   // 用于空白处的补齐字符


typedef struct _block {
    char ch[BLOCK_SIZE];    //块的数据域
    struct _block *next;    //块的指针域
} Block;

typedef struct {
    Block *head;        // 串的头指针
    Block *tail;        // 串的尾指针
    int len;            // 串的当前长度
} BLString;


//字符串初始化函数：
void blstr_init(BLString *T) {
    T->len = 0;
    T->head = NULL;
    T->tail = NULL;
}

void blstr_append(BLString *T, char *s, int len) {
    T->len = len;
    Block *t = (Block*) malloc(sizeof(Block));
    T->head = t;
    T->tail = t;

    for (int i = 0, j = 0; i < len; ++i) {
        T->tail->ch[j] = *s;
        ++s;
        ++j;
        if (j / 4) {
            j -= 4;
            Block * temp = (Block*) malloc(sizeof(Block));
            T->tail->next = temp;
            T->tail = T->tail->next;
        }
    }
}



