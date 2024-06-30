#include <stdio.h>
#include <stdlib.h>
#include "tsmatrix.h"


/**
 * @brief 矩阵加法
 * @param A 
 * @param B 
 * @param C 
 * @return true
 * @return false
 */
bool addSparseMatrix(TSMatrix A, TSMatrix B, TSMatrix *C) {
    if (A.m != B.m || A.n != B.n) {
        return false;  // 矩阵维度不匹配，不能相加
    }

    C->m = A.m;
    C->n = A.n;
    C->len = 0;

    int aPos = 0, bPos = 0;

    while (aPos < A.len && bPos < B.len) {
        if (A.data[aPos].i < B.data[bPos].i ||
            (A.data[aPos].i == B.data[bPos].i && A.data[aPos].j < B.data[bPos].j)) {
            C->data[C->len++] = A.data[aPos++];
        }
        else if (A.data[aPos].i > B.data[bPos].i ||
            (A.data[aPos].i == B.data[bPos].i && A.data[aPos].j > B.data[bPos].j)) {
            C->data[C->len++] = B.data[bPos++];
        }
        else {
            int sum = A.data[aPos].e + B.data[bPos].e;
            if (sum != 0) {
                C->data[C->len].i = A.data[aPos].i;
                C->data[C->len].j = A.data[aPos].j;
                C->data[C->len++].e = sum;
            }
            aPos++;
            bPos++;
        }
    }

    while (aPos < A.len) {
        C->data[C->len++] = A.data[aPos++];
    }

    while (bPos < B.len) {
        C->data[C->len++] = B.data[bPos++];
    }

    return true;
}

// 打印矩阵
void printMatrix(TSMatrix M) {
    for (int k = 0; k < M.len; k++) {
        printf("(%d, %d) -> %d\n", M.data[k].i, M.data[k].j, M.data[k].e);
    }
}

int main() {
    TSMatrix A = { { { 1, 1, 1 }, { 2, 2, 2 }, { 3, 3, 3 } }, 3, 3, 3 };
    TSMatrix B = { { { 1, 1, 4 }, { 2, 3, 5 }, { 3, 3, 6 } }, 3, 3, 3 };
    TSMatrix C;

    if (addSparseMatrix(A, B, &C)) {
        printMatrix(C);
    }
    else {
        printf("The matrices cannot be added.\n");
    }

    return 0;
}
