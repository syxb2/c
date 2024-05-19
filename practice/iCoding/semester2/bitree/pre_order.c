#include <stdlib.h>
#include <stdio.h>
#include "bitree.h" //请不要删除，否则检查不通过


/*
void pre_order(BiTree root) {
    if (root == NULL) {
        return;
    }

    // Initialization
    Stack* S = (Stack*) malloc(sizeof(Stack));
    if (S == NULL) {
        return;
    }
    init_stack(S);
    BiTree p = root;

    // In while loop
    while (p != NULL || !is_empty(S)) {
        visit_node(p);
        if (p->left != NULL) {
            push(S, p);
            p = p->left;
        }
        else if (!is_empty(S)) {
            if (p->right != NULL) {
                p = p->right;
            }
            else {
                pop(S, &p);
                if (p->right != NULL) {
                    p = p->right;
                }
                else {
                    pop(S, &p);
                }
            }
        }
    }
    free(S);
}
不可以这样写，不能用 p->left 和 p->right 来判断是否有左右子树。这样可能导致重复访问和无限循环。
*/

void pre_order_answer(BiTree root) {
    if (root == NULL) {
        return;
    }

    Stack* S = (Stack*) malloc(sizeof(Stack));
    if (S == NULL) {
        return;
    }
    init_stack(S);
    BiTree p = root;

    while (p != NULL || !is_empty(S)) {
        while (p != NULL) {
            visit_node(p);
            push(S, p);
            p = p->left;
        }
        if (!is_empty(S)) {
            pop(S, &p);
            p = p->right;
        }
    }
    free(S);
}

int main() {

    return 0;
}