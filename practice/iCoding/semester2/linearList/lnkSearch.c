#include <stdio.h>
#include <stdlib.h>

#include "lnkList.h"

extern bool init_list(LinkList *LQ);
extern bool enter_list(LinkList *LQ, ElemType x);


int lnk_search(LinkList L, int k, ElemType* p_ele) {
    int num = 0;
    LinkList p = L;

    for (; p->next != NULL; p = p->next, ++num);
    if (num - k <= 0) return 0;
    for (int i = 0; i <= num - k; ++i) L = L->next;
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