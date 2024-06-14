/**
 * @file nearest_ancestor.c
 * @author Bai Jiale (578767478@qq.com)
 * @brief 假设二叉树采用二叉链表方式存储， root指向根结点，p所指结点和q所指结点为二叉树中的两个结点，编写一个计算它们的最近的共同祖先.提示：在完成本题时，可利用 path 函数获取p和q两个结点到根结点之间的路径，之后再计算两条公共路径得出最近的共同祖先。path函数及栈相关定义如下：
 * @version 0.1
 * @date 2024-06-13
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include "bitree.h" //请不要删除，否则检查不通过


#define Stack_Size 50


bool path(BiTNode* root, BiTNode* node, Stack* s);


typedef BiTNode* ElemType;
typedef struct {
    ElemType elem[Stack_Size];
    int top;
} Stack;


void init_stack(Stack *S); // 初始化栈
bool push(Stack* S, ElemType x); // x 入栈
bool pop(Stack* S, ElemType *px); // 出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack* S, ElemType *px); // 获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack* S);  // 栈为空时返回 true，否则返回 false


/**
 * @brief 其中 root 指向二叉树的根结点，p 和 q 分别指向二叉树中的两个结点。
 *
 * @param root
 * @param p
 * @param q
 * @return BiTNode*
 */
BiTNode *nearest_ancestor(BiTree root, BiTNode *p, BiTNode *q) {
    // Stack *s1 = NULL; // 不能这么些，是因为这么写的话没有为 s1 分配内存
    Stack s1;
    init_stack(&s1);
    Stack s2;
    init_stack(&s2);

    path(root, p, &s1); // 获取 p 到根结点的路径，保存在 s1 中
    path(root, q, &s2); // 获取 q 到根结点的路径，保存在 s2 中

    Stack *sp1 = &s1;
    Stack *sp2 = &s2;

    ElemType p1 = NULL, p2 = NULL;

    while (sp1->top != sp2->top) { // 两个路径长度不一样时，将较长的路径长度减一，直到两个路径长度一样
        if (sp1->top > sp2->top) --sp1->top;
        else --sp2->top;
    }
    while (!is_empty(sp1) && !is_empty(sp2)) {
        pop(sp1, &p1);
        pop(sp2, &p2);
        if (p1 == p2) return p1;
    } // 从根结点开始，比较两个路径，直到找到最近的共同祖先

    return NULL;
}
