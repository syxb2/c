#include <stdio.h>
#include <stdlib.h>

#include "lnkList.h"


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