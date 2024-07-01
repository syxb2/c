/*
 * 链表 倒数查找
 *
 * 已知一个带有表头结点的单链表, 假设链表只给出了头指针L。在不改变链表的前提下，请设计一个尽可能高效的算法，
 * 查找链表中倒数第k个位置上的结点（k为正整数）。
 * 函数原型为：int lnk_search(LinkList L, int k, ElemType* p_ele)
 * 若查找成功，函数通过指针参数 p_ele 返回该结点 data 域的值，此时函数返回 1；否则，函数返回 0。
 * 相关定义如下：
 *
 * struct _lnklist{
 *     ElemType data;
 *     struct _lnklist *next;
 * };
 *
 * typedef struct _lnklist Node;
 * typedef struct _lnklist *LinkList;
 */
#include <stdio.h>
#include <stdlib.h>
#include "lnkList.h"

extern bool init_list(LinkList *LQ);
extern bool enter_list(LinkList *LQ, ElemType x);


/**
 * @brief search the k-th element from the end of the list
 * 
 * @param L 
 * @param k 
 * @param p_ele 
 * @return int 
 */
int lnk_search(LinkList L, int k, ElemType* p_ele) {
    int node_num = 0;
    LinkList p = L;

    for (; p->next != NULL; p = p->next, ++node_num); // get the number of nodes

    if (node_num - k <= 0) return 0; // if k is larger than the number of nodes, return 0

    for (int i = 0; i <= node_num - k; ++i) L = L->next;

    *p_ele = L->data;

    return 1;
}

int main() {
    Node L;
    LinkList Q = &L;
    init_list(&Q);
    enter_list(&Q, 5);
    enter_list(&Q, 4);
    enter_list(&Q, 3);
    enter_list(&Q, 2);
    enter_list(&Q, 1);

    ElemType x = 0;
    lnk_search(Q, 1, &x);
    printf("%d\n", x);

    return 0;
}