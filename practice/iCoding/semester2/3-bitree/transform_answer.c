#include <stdlib.h>
#include <stdio.h>
#include "bitree.h" //请不要删除，否则检查不通过


BiTNode* transform(CSNode* root) {
    // 如果根节点为空，则返回NULL
    if (root == NULL) {
        return NULL;
    }

    // 创建一棵二叉树，并将根节点的值赋值给二叉树的根节点
    BiTNode* bt_root = (BiTNode*) malloc(sizeof(BiTNode));
    if (bt_root == NULL) return NULL;
    bt_root->data = root->data;
    bt_root->left = NULL;
    bt_root->right = NULL;

    // 创建一个队列，依次存放树广度优先遍历的节点的指针，和对应的二叉树节点中的指针
    Queue* Q = create_queue();
    add_queue(Q, root);
    add_queue(Q, bt_root);
    //* 规定 入队时，先入树节点，再入二叉树节点

    // 广度优先遍历树，创建二叉树节点，并建立相应的连接关系
    while (!is_empty_queue(Q)) {
        // 从队列中依次取出树中的节点和二叉树中的节点
        CSNode* tree_node = (CSNode*) del_queue(Q); //* 先取出树中的节点
        BiTNode* btree_node = (BiTNode*) del_queue(Q); //* 再取出对应的二叉树中的节点
        //* 队列中 树结点 和 二叉树结点 总是一一对应的
        BiTNode* pre_btree_node = NULL;

        // 遍历树中当前节点的所有孩子节点
        for (int i = 0; tree_node->children[i] != NULL; i++) { //! 广度优先遍历 - 1
            // 创建一个新的二叉树节点，并将孩子节点的值赋值给它
            BiTNode* new_btree_node = (BiTNode*) malloc(sizeof(BiTNode));
            if (new_btree_node == NULL) return NULL;
            new_btree_node->data = tree_node->children[i]->data;
            new_btree_node->left = NULL;
            new_btree_node->right = NULL;

            // 第一个孩子作为上一个层节点的左孩子
            if (i == 0) {
                btree_node->left = new_btree_node;
                pre_btree_node = new_btree_node;
            }
            // 后面的孩子作为前面结点的右孩子
            else {
                pre_btree_node->right = new_btree_node;
                pre_btree_node = new_btree_node;
            }

            // 将当前孩子节点指针和对应二叉树中节点指针依次加入到队列中
            add_queue(Q, tree_node->children[i]); //! 广度优先遍历 - 2
            add_queue(Q, new_btree_node);
        }
    }

    // 释放队列占用的空间
    free(Q->array);
    free(Q);

    // 返回转换后的二叉树
    return bt_root;
}
