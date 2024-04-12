#include <stdio.h>
#include <stdlib.h>

#define ElemType int


struct _lnklist {
    ElemType data;
    struct _lnklist *next;
};
typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;


/**
 * @brief Initialize the linklist
 *
 * @param LQ
 * @return true
 * @return false
 */
bool init_list(LinkList *LQ) {
    *LQ = (LinkList) malloc(sizeof(Node));
    (*LQ)->next = NULL; // 避免野指针

    if (*LQ == NULL) return 0;
    else return 1;
}

/**
 * @brief Enter the node to the linklist
 *
 * @param LQ
 * @param x
 * @return true
 * @return false
 */
bool enter_list(LinkList *LQ, ElemType x) {
    if (*LQ == NULL) return 0;
    LinkList p = (LinkList) malloc(sizeof(Node));
    if (!p) return 0;
    p->data = x;
    p->next = (*LQ)->next;
    (*LQ)->next = p;

    return 1;
}

/**
 * @brief Delete the node behind the pointer
 *
 * @param LQ
 * @param x
 * @return true
 * @return false
 */
bool del_list(LinkList LQ, ElemType *x) {
    if (LQ == NULL) return 0;

    LinkList p = LQ;
    LinkList q = p->next; // 指向要删除的节点

    *x = q->data;
    p->next = q->next;
    free(q);

    return 1;
}
