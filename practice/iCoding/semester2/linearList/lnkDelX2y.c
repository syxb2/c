#include <stdio.h>
#include <stdlib.h>

#include "lnkList.h"


void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk) {
    int minnum = 0, accordnum = 0;
    LinkList p = L->next;

    for (; p->next != NULL; p = p->next) {
        if (p->data < mink) ++minnum;
        else if (p->data < maxk && p->data > mink) ++accordnum;
    }
    for (int i = 0; i < minnum; ++i) {
        L = L->next;
    }
    for (int i = 0; i < accordnum; ++i) {
        int x = 0;
        LinkList q = L;
        del_list(q, &x);
    }
    for (; L->next != NULL; ) {
        L = L->next;
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
