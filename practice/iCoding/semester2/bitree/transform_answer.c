#include <stdlib.h>
#include <stdio.h>
#include "bitree.h" //请不要删除，否则检查不通过


BiTNode* transform(CSNode* root) {
    // 如果根节点为空，则返回NULL
    if (root == NULL) {
        return NULL;
    }

    // 创建一棵二叉树，并将根节点的值赋值给二叉树的根节点
    BiTNode* H = (BiTNode*) malloc(sizeof(BiTNode));
    if (H == NULL) {
        exit(0);
    }
    H->data = root->data;
    H->left = NULL;
    H->right = NULL;

    // 创建一个队列，依次存放树广度优先遍历的节点的指针，和对应的二叉树节点中的指针
    Queue* Q = create_queue();
    add_queue(Q, root);
    add_queue(Q, H);

    // 广度优先遍历树，创建二叉树节点，并建立相应的连接关系
    while (!is_empty_queue(Q)) {
        // 从队列中依次取出树中的节点和二叉树中的节点
        CSNode* TreeNode = (CSNode*) del_queue(Q);
        BiTNode* BNode_H = (BiTNode*) del_queue(Q);
        BiTNode* pre = NULL;

        // 遍历树中当前节点的所有孩子节点
        for (int i = 0; TreeNode->children[i] != NULL; i++) {
            // 创建一个新的二叉树节点，并将孩子节点的值赋值给它
            BiTNode* New = (BiTNode*) malloc(sizeof(BiTNode));
            if (New == NULL) {
                exit(0);
            }
            New->data = TreeNode->children[i]->data;
            New->left = NULL;
            New->right = NULL;

            // 第一个孩子作为上一个层节点的左孩子
            if (i == 0) {
                BNode_H->left = New;
                pre = New;
            }
            // 后面的孩子作为前面结点的右孩子
            else {
                pre->right = New;
                pre = New;
            }

            // 将当前孩子节点指针和对应二叉树中节点指针依次加入到队列中
            add_queue(Q, TreeNode->children[i]);
            add_queue(Q, New);
        }
    }

    // 释放队列占用的空间
    free(Q->array);
    free(Q);
    // 返回转换后的二叉树
    return H;
}
