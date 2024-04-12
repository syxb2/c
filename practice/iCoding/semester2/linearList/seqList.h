#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define MAXSIZE 100


struct _seqlist {
    ElemType elem[MAXSIZE];
    int last; // last 是数组最后一个元素的下标值
};
typedef struct _seqlist SeqList;


/**
 * @brief To init the seqlist
 *
 * @param L
 * @return true
 * @return false
 */
bool init_seqlist(SeqList* L) {
    if (L == NULL) return 0;
    L->last = -1;

    return 1;
}

/**
 * @brief To add a elem to the seqlist
 *
 * @param L
 * @param x
 * @return true
 * @return false
 */
bool add_seqlist(SeqList* L, ElemType x) {
    if (L == NULL) return 0;
    L->elem[++(L->last)] = x;

    return 1;
}
