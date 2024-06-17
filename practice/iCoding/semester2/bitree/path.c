#include <stdlib.h>
#include <stdio.h>
#include "bitree.h" //请不要删除，否则检查不通过


#define Stack_Size  50
#define false       0
#define true        1


typedef int DataType;

typedef struct Node{
    DataType data;
    struct Node* left;
    struct Node* right;
} BiTNode, *BiTree;
typedef BiTNode* ElemType;

typedef struct{
    ElemType elem[Stack_Size];
    int top;
} Stack;


void init_stack(Stack *S); // 初始化栈
bool push(Stack* S, ElemType x); // x 入栈
bool pop(Stack* S, ElemType *px); // 出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack* S, ElemType *px); // 获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack* S); // 栈为空时返回 true，否则返回 false


bool path(BiTNode* root, BiTNode* node, Stack* s){
    if (root == NULL) return false;

    ElemType readed;
    while (!is_empty(s) || root != NULL) {
        if (root != NULL && root != readed) {
            push(s, root);
            readed = root;
            if (root == node) return true;
            root = root->left;
        }
        else {
            top(s, &root);
            if (root->right != readed) root = root->right;
            if (root == NULL) {
                pop(s, &root);
                top(s, &root);
                readed = root;
            }
        }
    }

    return false;
}
