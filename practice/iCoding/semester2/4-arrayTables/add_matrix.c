#include <stdio.h>
#include <stdlib.h>
#include "tsmatrix.h"


/**
 * @brief pM, pN, pQ 分别指向三个矩阵，当 pM 和 pN 两个矩阵不可加时，函数返回 false，否则函数返回 true，且 pQ 指向两个矩阵的和。
 * @param pM
 * @param pN
 * @param pQ
 * @return true
 * @return false
 */
bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ) {
    if (pM->m != pN->m || pM->n != pN->n) {
        return false;
    }

    int p1 = 0, p2 = 0; // p1 和 p2 分别指向矩阵 M 和 N
    pQ->m = pM->m;
    pQ->n = pM->n;
    pQ->len = 0;

    // i 是 行，j 是 列
    while (p1 < pM->len && p2 < pN->len) {
        if (
            (pM->data[p1].j < pN->data[p2].j && pM->data[p1].i == pN->data[p2].i) ||
            pM->data[p1].i < pN->data[p2].i
            ) {
            pQ->data[pQ->len] = pM->data[p1];
            ++(pQ->len);
            ++p1;
        }
        else if (
            (pN->data[p2].j < pM->data[p1].j && pN->data[p2].i == pM->data[p1].i) ||
            pN->data[p2].i < pM->data[p1].i
            ) {
            pQ->data[pQ->len] = pN->data[p2];
            ++(pQ->len);
            ++p2;
        }
        else {
            if (pM->data[p1].e + pN->data[p2].e != 0) {
                pQ->data[pQ->len].i = pM->data[p1].i;
                pQ->data[pQ->len].j = pM->data[p1].j;
                pQ->data[pQ->len].e = pM->data[p1].e + pN->data[p2].e;
                ++(pQ->len);
            }
            ++p1, ++p2;
        }
    }

    while (p1 < pM->len) {
        pQ->data[pQ->len] = pM->data[p1];
        ++(pQ->len);
        ++p1;
    }
    while (p2 < pN->len) {
        pQ->data[pQ->len] = pN->data[p2];
        ++(pQ->len);
        ++p2;
    }

    return true;
}
