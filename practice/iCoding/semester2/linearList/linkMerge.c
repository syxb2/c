#include <stdio.h>
#include <stdlib.h>

#define ElemType int


struct _lnklist {
    ElemType data;
    struct _lnklist *next;
};
typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;


void lnk_merge(LinkList A, LinkList B, LinkList C) {
    A = A->next; B = B->next;
    while (A != NULL || B != NULL) {
        if (A != NULL && B == NULL) {
            C->next = A;
            C = C->next;
            A = A->next;
        }
        else if (A == NULL && B != NULL) {
            C->next = B;
            C = C->next;
            B = B->next;
        }
        else {
            C->next = A;
            C = C->next;
            A = A->next;
            C->next = B;
            C = C->next;
            B = B->next;
        }
    }
}

int main() {

    return 0;
}