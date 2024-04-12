#include <stdio.h>
#include <stdlib.h>

#include "seqList.h"


void odd_even(SeqList *L) {
    SeqList* p = (SeqList*) malloc(sizeof(SeqList));
    p->last = -1;
    int j = 0;
    for (int i = 0; i <= L->last; ++i) {
        if (L->elem[i] % 2 == 1) {
            p->elem[j] = L->elem[i];
            ++j, ++p->last;
        }
    }
    for (int i = 0; i <= L->last; ++i) {
        if (L->elem[i] % 2 == 0) {
            p->elem[j] = L->elem[i];
            ++j, ++p->last;
        }
    }
    for (int i = 0; i <= L->last; ++i) {
        L->elem[i] = p->elem[i];
    }

    return;
}


int main() {
    SeqList s, *p = &s;
    init_seqlist(p);
    add_seqlist(p, 1);
    add_seqlist(p, 2);
    add_seqlist(p, 3);
    add_seqlist(p, 4);
    add_seqlist(p, 6);
    add_seqlist(p, 7);
    add_seqlist(p, 8);
    add_seqlist(p, 9);

    odd_even(p);

    return 0;
}
