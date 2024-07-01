/**
 * 队列 循环链表表示队列
 * 假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点（注意不设头指针），请完成下列任务：
 * 1: 队列初始化，成功返回真，否则返回假： bool init_queue(LinkQueue *LQ);
 * 2: 入队列，成功返回真，否则返回假： bool enter_queue(LinkQueue *LQ, ElemType x);
 * 3: 出队列，成功返回真，且*x为出队的值，否则返回假 bool leave_queue(LinkQueue *LQ, ElemType *x);
 * 相关定义如下：
 * typedef struct _QueueNode {
 *     ElemType data;          // 数据域
 *     struct _QueueNode *next;      // 指针域
 * } LinkQueueNode, *LinkQueue;
 * 
 */
#include <stdio.h>
#include <stdlib.h>

#define ElemType    int


typedef struct _QueueNode {
    ElemType data;          // 数据域
    struct _QueueNode *next;      // 指针域
} LinkQueueNode, *LinkQueue;


bool init_queue(LinkQueue *LQ) {
    *LQ = (LinkQueue) malloc(sizeof(LinkQueueNode));
    (*LQ)->next = (*LQ);

    if (*LQ == NULL) return false;
    else return true;
}

bool enter_queue(LinkQueue *LQ, ElemType x) {
    if (*LQ == NULL) return false;

    LinkQueue p = (LinkQueue) malloc(sizeof(LinkQueueNode));
    if (p == NULL) return false;

    p->data = x;
    p->next = (*LQ)->next;
    (*LQ)->next = p;
    *LQ = p;

    return true;
}

bool leave_queue(LinkQueue *LQ, ElemType *x) {
    if ((*LQ)->next == *LQ) return false; // if queue is empty, in other words, only head node

    LinkQueue p = (*LQ);
    p = p->next; 
    LinkQueue t = p; // at the time, t is the head node
    p = p->next; // at the time, p is the first element node

    if ((*LQ)->next->next == *LQ) { // if only one element in the queue
        *LQ = (*LQ)->next; // at the time, *LQ is the head node
        (*LQ)->next = *LQ;
    }
    else
        t->next = p->next;

    *x = p->data;
    free(p);

    return true;
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
