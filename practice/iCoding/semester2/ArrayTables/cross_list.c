#include <stdio.h>
#include <stdlib.h>
#include "crosslist.h"


/*
* L 指向 CrossList 结构，且各成员已被初始化为0；
* A 为 ElemType 类型数组中第一个元素的地址，元素的个数为 m×n 个，按行优先存储（即A[0] 为十字链表第1行第1列的元素；A[1] 为第1行第2列的元素，A[n] 为第2行第1列的元素，A[n+1] 为第2行第2个元素）；
* m 表示十字链表的行数，n 表示十字链表的列数。
* init_cross_list 函数将 ElemType 数组中非0元素保存到十字链表中，函数返回非 0 元素的个数。
*/
int init_cross_list(PCrossList L, const ElemType *A, int m, int n) {
    // 初始化行、列
    L->rows = m;
    L->cols = n;
    L->nums = 0;

    // 初始化定位指针
    OLink p = NULL;
    OLink q = NULL;

    // 初始化行头数组和列头数组
    L->rowhead = (OLink*) malloc(m * sizeof(OLink));
    if (L->rowhead == NULL) exit(0);
    for (int i = 0; i < m; ++i) {
        L->rowhead[i] = NULL;
    }
    L->colhead = (OLink*) malloc(n * sizeof(OLink));
    if (L->colhead == NULL) exit(0);
    for (int i = 0; i < n; ++i) {
        L->colhead[i] = NULL;
    }

    // 遍历数组，将非0元素插入十字链表
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i * n + j] != 0) {
                ++(L->nums);

                // 创建新结点
                OLink New = (OLink) malloc(sizeof(OLNode));
                if (New == NULL) {
                    free(L->rowhead);
                    free(L->colhead);
                    exit(0);
                }
                New->right = NULL;
                New->down = NULL;

                // 写入行数、列数、值
                New->row = i + 1; // 行列从1开始
                New->col = j + 1;
                New->value = A[i * n + j];

                // 插入节点到正确位置
                if (L->rowhead[i] == NULL) { // 如果行头为空, 则直接插入
                    L->rowhead[i] = New;
                }
                else {
                    p = L->rowhead[i];
                    while (p->right != NULL) {
                        p = p->right;
                    }
                    p->right = New;
                }

                if (L->colhead[j] == NULL) {
                    L->colhead[j] = New;
                }
                else {
                    q = L->colhead[j];
                    while (q->down != NULL) {
                        q = q->down;
                    }
                    q->down = New;
                }
            }
        }
    }

    return L->nums;
}

/*
* L 指向 要处理的 CrossList 结构，k 为要删除的元素；
* del_cross_list 函数删除十字链表中所有值为 k 的结点，并返回删除结点的个数。
*/
int del_cross_list(PCrossList L, ElemType k) {
    // 初始化计数器
    int count = 0;

    // 初化定位指针 前驱指针 和 当前指针
    OLink l = NULL;
    OLink h = NULL;
    OLink Now = NULL;

    for (int i = 0; i < L->rows; ++i) {
        l = L->rowhead[i];
        if (l == NULL) continue;

        while (l->right != NULL) {
            if (l->right->value == k) {
                // 定位 Now 指针
                Now = l->right;
                l->right = Now->right;

                // 定位 h 指针
                h = L->colhead[Now->col - 1];
                while (h->down != Now) {
                    h = h->down;
                }
                h->down = Now->down;

                ++count;
                free(Now);
            }
            else {
                l = l->right;
            }
        }
    }

    return count;
}


int main() {

    return 0;
}