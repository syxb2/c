#include <stdio.h>
#include <stdlib.h>

#define Stack_Size 50


typedef int DataType;

typedef struct Node {
    DataType data;
    struct Node* left;
    struct Node* right;
} BiTNode, *BiTree;
typedef BiTNode* ElemType;

typedef struct {
    ElemType elem[Stack_Size];
    int top;
} Stack;

void init_stack(Stack *S); // 初始化栈
bool push(Stack* S, ElemType x); //x 入栈
bool pop(Stack* S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack* S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack* S);  // 栈为空时返回 true，否则返回 fals
void visit_node(BiTNode *node);

bool post_order(BiTree root) { // 后序遍历二叉树
    Stack s, *S = &s; //! 不能直接写 Stack *S; init_stack(&S); 因为这样没有给S分配内存
    init_stack(S);

    BiTNode* p = root;
    BiTNode* q; // q is the front pointer
    while (p != NULL || !is_empty(S)) {
        if (p != NULL) {
            push(S, p);
            p = p->left;
        }
        else {
            top(S, &p);
            if (p->right == NULL || p->right == q) {
                pop(S, &p);
                visit_node(p);
                q = p;
                p == NULL;
            }
            else {
                p = p->right;
            }
        }
    }
}
