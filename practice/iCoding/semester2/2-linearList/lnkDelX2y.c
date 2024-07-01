/*
 * 链表 删除范围内结点
 *
 * 已知线性表中的元素（整数）以值递增有序排列，并以单链表作存储结构。
 * 试写一高效算法，删除表中所有大于mink且小于maxk的元素（若表中存在这样的元素），
 * 分析你的算法的时间复杂度。
 *
 * 链表结点定义如下：
 * struct _lnklist{
 *     ElemType data;
 *     struct _lnklist *next;
 * };
 * typedef struct _lnklist Node;
 * typedef struct _lnklist *LinkList;
 *
 * 函数原型如下：
 * void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk)
 *
 * 其中L指向链表的头结点。
 */
#include <stdio.h>
#include <stdlib.h>
#include "lnkList.h"


/**
 * @brief Delete the node behind the pointer LQ
 *
 * @param LQ
 * @param x
 * @return true
 * @return false
 */
bool __del_list(LinkList LQ) {
    if (LQ == NULL) return 0;

    LinkList p = LQ;
    LinkList q = p->next; // 指向要删除的节点

    p->next = q->next;
    free(q);

    return 1;
}

/**
 * @brief delete the elements between mink and maxk
 * 
 * @param L 
 * @param mink 
 * @param maxk 
 */
void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk) {
    int minnum = 0, accordnum = 0; // minnum: the number of elements less than mink; accordnum: the number of elements between mink and maxk
    LinkList p = L->next; // p points to the first node

    for (; p->next != NULL; p = p->next) {
        if (p->data < mink) ++minnum;
        else if (p->data < maxk && p->data > mink) ++accordnum;
    }
    for (int i = 0; i < minnum; ++i) L = L->next;
    for (int i = 0; i < accordnum; ++i) {
        LinkList q = L;
        __del_list(q);
    }

    return;
}


int main() {
    Node N;
    LinkList L = &N;
    init_list(&L);
    enter_list(&L, 10);
    enter_list(&L, 9);
    enter_list(&L, 8);
    enter_list(&L, 7);
    enter_list(&L, 6);
    enter_list(&L, 5);
    enter_list(&L, 4);
    enter_list(&L, 3);
    enter_list(&L, 2);
    enter_list(&L, 1);

    lnk_del_x2y(L, 3, 7);

    return 0;
}
