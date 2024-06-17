#include <stdlib.h>
#include <stdio.h>
#include "bitree.h" //请不要删除，否则检查不通过


#define Stack_Size  50
#define false       0
#define true        1


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
bool push(Stack* S, ElemType x); // x 入栈
bool pop(Stack* S, ElemType *px); // 出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack* S, ElemType *px); // 获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack* S); // 栈为空时返回 true，否则返回 false


bool path(BiTNode* root, BiTNode* target, Stack* stack) {
    if (!root || !target) return false; // 检查根节点或目标节点是否为空，如果为空，返回false

    BiTNode* visited = NULL; // visited用来标记右子树是否已被遍历
    while (root != NULL || !is_empty(stack)) {
        if (root != NULL) {
            push(stack, root); // 将当前节点压入栈中
            if (root == target) return true; // 找到目标节点，返回true
            root = root->left; // 继续遍历左子树
        }
        else {
            top(stack, &root); // 栈顶元素赋给root
            if (root->right != NULL && root->right != visited) root = root->right; // 如果右子树存在且未被遍历，遍历右子树
            else { // 如果右子树为空或已被遍历，弹出栈顶元素
                pop(stack, &root);
                visited = root; // 标记右子树已被遍历
                root = NULL; // 重置root
            }
        }
    }

    return false; // 没有找到目标节点，返回false
}
