#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct _QueueNode {
    ElemType data;          // 数据域
    struct _QueueNode *next;      // 指针域
} LinkQueueNode, *LinkQueue;

bool init_queue(LinkQueue *LQ) {
    *LQ = (LinkQueue) malloc(sizeof(LinkQueueNode));
    (*LQ)->next = (*LQ);

    return 1;
}

bool enter_queue(LinkQueue *LQ, ElemType x) {
    if (*LQ == NULL) return 0;
    LinkQueue p = (LinkQueue) malloc(sizeof(LinkQueueNode));
    p->data = x;
    p->next = (*LQ)->next;
    (*LQ)->next = p;
    *LQ = p;

    return 1;
}

bool leave_queue(LinkQueue *LQ, ElemType *x) {
    if ((*LQ)->next == *LQ) return 0;
    LinkQueue p = (*LQ);
    p = p->next;
    LinkQueue t = p;
    p = p->next;
    t->next = p->next;
    *x = p->data;

    free(p);

    return 1;
}

int main() {
    LinkQueueNode list, *L = &list;
    init_queue(&L);
    ElemType a, b, c, t = 0;
    scanf("%d %d %d", &a, &b, &c);
    enter_queue(&L, a);
    enter_queue(&L, b);
    enter_queue(&L, c);
    leave_queue(&L, &t);
    printf("%d\n", t);
    leave_queue(&L, &t);
    printf("%d\n", t);
    leave_queue(&L, &t);
    printf("%d\n", t);

    return 0;
}
