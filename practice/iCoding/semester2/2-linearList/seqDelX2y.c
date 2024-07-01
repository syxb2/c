/*
 * 顺序表 删除指定范围
 *
 * 设计一个高效的算法，从顺序表L中删除所有值介于x和y之间(包括x和y)的所有元素（假设y>=x），
 * 要求时间复杂度为O(n)，空间复杂度为O(1)。
 *
 * 函数原型如下：
 * void del_x2y(SeqList *L, ElemType x, ElemType y);
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
#include "seqList.h" // 请不要删除，否则检查不通过


/**
 * @brief delete the element at the sub-th position
 * 
 * @param L 
 * @param sub 
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
 * @brief delete the elements between x and y
 * 
 * @param L 
 * @param x 
 * @param y 
 */
void del_x2y(SeqList  *L, ElemType x, ElemType y) {
    for (int i = 0; 1;) {
        if (L->elem[i] >= x && L->elem[i] <= y) __del_seqlist(L, i);

        ++i;
        if (i > L->last) break;
    }

    return;
}


int main() {
    SeqList l, *p = &l;
    init_seqlist(p);
    add_seqlist(p, 870);
    add_seqlist(p, 863);
    add_seqlist(p, 230);
    add_seqlist(p, 989);
    add_seqlist(p, 77);
    add_seqlist(p, 691);
    add_seqlist(p, 654);
    add_seqlist(p, 810);
    add_seqlist(p, 293);
    add_seqlist(p, 603);
    add_seqlist(p, 916);
    add_seqlist(p, 15);
    add_seqlist(p, 290);

    del_x2y(p, 230, 654);

    return 0;
}