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
    if (A.m != B.m || A.n != B.n) return false; // 判断矩阵是否可加 

    C->m = A.m;
    C->n = A.n;
    C->len = 0;

    int aPos = 0, bPos = 0; // aPos 和 bPos 是 data 数组中指向 A 和 B 的当前元素的指针

    while (aPos < A.len && bPos < B.len) {
        if (A.data[aPos].i < B.data[bPos].i ||
            (A.data[aPos].i == B.data[bPos].i && A.data[aPos].j < B.data[bPos].j)
            ) { //* 即 A 的当前非0元素在 B 的当前非0元素之前
            C->data[C->len] = A.data[aPos];

            ++C->len, ++aPos;
        }
        else if (A.data[aPos].i > B.data[bPos].i ||
            (A.data[aPos].i == B.data[bPos].i && A.data[aPos].j > B.data[bPos].j)
            ) { //* 即 B 的当前非0元素在 A 的当前非0元素之前
            C->data[C->len] = B.data[bPos];

            ++C->len, ++bPos;
        }
        else {
            int sum = A.data[aPos].e + B.data[bPos].e;

            if (sum == 0) ++aPos, ++bPos;
            else if (sum != 0) {
                C->data[C->len].i = A.data[aPos].i;
                C->data[C->len].j = A.data[aPos].j;
                C->data[C->len].e = sum;

                ++C->len, ++aPos, ++bPos;
            }
        }
    }

    while (aPos < A.len) {
        C->data[C->len] = A.data[aPos];

        ++C->len, ++aPos;
    }

    while (bPos < B.len) {
        C->data[C->len] = B.data[bPos];

        ++C->len, ++bPos;
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
