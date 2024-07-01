/**
 * @file path.c
 * @author Bai Jiale (578767478@qq.com)
 * @brief 路径
 * 假设二叉树采用二叉链表方式存储， root指向根结点，node 指向二叉树中的一个结点，编写函数 path，计算root到 node 之间的路径，（该路径包括root结点和 node 结点）。path 函数声明如下：
 * bool path(BiTNode* root, BiTNode* node, Stack* s);
 * 其中，root指向二叉树的根结点，node指向二叉树中的另一结点，s 为已经初始化好的栈，该栈用来保存函数所计算的路径，如正确找出路径，则函数返回 true，此时root在栈底，node在栈顶；如未找到，则函数返回 false, 
 * @version 0.1
 * @date 2024-07-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include "bitree.h" //请不要删除，否则检查不通过


#define Stack_Size  50


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
