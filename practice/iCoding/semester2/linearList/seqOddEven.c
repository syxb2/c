/*顺序表 数据调整

已知顺序表L中的数据元素类型为int。设计算法将其调整为左右两部分，左边的元素（即排在前面的）均为奇数，右边所有元素（即排在后面的）均为偶数，并要求算法的时间复杂度为O(n),空间复杂度为O（1）。

函数原型如下：
void odd_even(SeqList *L);

相关定义如下：
struct _seqlist{
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;*/

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
