/*
 * 顺序表 删除重复元素
 *
 * 编写算法，在一非递减的顺序表L中，删除所有值相等的多余元素。要求时间复杂度为O(n)，空间复杂度为O(1)。
 *
 * 函数原型如下：
 * void del_dupnum(SeqList *L)
 *
 * 相关定义如下：
 * struct _seqlist{
 *     ElemType elem[MAXSIZE];
 *     int last;
 * };
 * typedef struct _seqlist SeqList;
 */
#include <stdio.h>
#include <stdlib.h>
#include "seqList.h"


/**
 * @brief delete the element at the sub-th position
 * 
 * @param L 
 * @param sub 
 * @param x 
 * @return true 
 * @return false 
 */
bool __del_seqlist(SeqList* L, int sub) {
    if (L == NULL) return 0;
    for (int i = sub; i < L->last; ++i) {
        L->elem[i] = L->elem[i + 1];
    }
    L->elem[L->last] = 0;
    --(L->last);

    return 1;
}

/**
 * @brief delete the duplicate elements
 * 
 * @param L 
 */
void del_dupnum(SeqList *L) {
    int i = 0, j = i + 1; // i is the front pointer, j is the back pointer

    for (; j <= L->last;) { // L->last is the last index of the array
        if (L->elem[i] == L->elem[j]) {
            __del_seqlist(L, j);
            continue;
        }
        ++i, ++j;
    }

    return;
}


int main() {
    SeqList l, *p = &l;
    init_seqlist(p);
    add_seqlist(p, 1);
    add_seqlist(p, 2);
    add_seqlist(p, 3);
    add_seqlist(p, 3);
    add_seqlist(p, 4);
    add_seqlist(p, 5);
    add_seqlist(p, 5);
    add_seqlist(p, 6);
    add_seqlist(p, 7);

    del_dupnum(p);

    return 0;
}
