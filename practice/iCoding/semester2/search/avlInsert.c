#include <stdlib.h>
#include <stdio.h>
#include "avl.h"


/**
 * @brief Get the height object
 *
 * @param node
 * @return int
 */
int balence_factor(node_t *node) {
    if (node == NULL) return 0;
    else if (node->left == NULL && node->right == NULL) return 0;
    else if (node->left == NULL && node->right != NULL) return -1;
    else if (node->left != NULL && node->right == NULL) return 1;
    else return node->left->height - node->right->height;
}

/**
 * @brief update AVLTree's every node's height
 * 
 * @param node 
 */
void update_height(node_t *node) {
    while (node != NULL) {
        if (node->left == NULL && node->right == NULL) node->height = 0;
        else if (node->left == NULL && node->right != NULL) node->height = node->right->height + 1;
        else if (node->left != NULL && node->right == NULL) node->height = node->left->height + 1;
        else node->height = (node->left->height > node->right->height ? node->left->height : node->right->height) + 1;

        node = node->parent;
    }
}

/**
 * @brief 向根为 root 的平衡二叉树插入新元素 val，成功后返回新平衡二叉树根结点
 *
 * @param root
 * @param val
 * @return node_t*
 */
node_t* avl_insert(node_t *root, int val) {
    node_t *S, *A, *B, *C, *p, *fp;

    // create the new node S
    S = (node_t*) malloc(sizeof(node_t));
    S->val = val;
    S->left = S->right = S->parent = NULL;
    S->height = 0;

    // if root is null, exit the program
    if (root == NULL) {
        return NULL;
    }

    // search the place of inserting & record the node A which is probably losing balence
    A = root;
    p = root; // the pointer being used to traverse
    while (p != NULL) {
        if (p->val == val) {
            free(S);
            return NULL;
        }

        // record the last node which is not balence
        if (p->left == NULL && p->right == NULL);
        else if (balence_factor(p) != balence_factor(p)) {
            A = p;
        }

        // do traversing
        fp = p;
        if (val < p->val) p = p->left;
        else p = p->right;
    } // while over : at the time p is null

    // insert S in the correct place
    if (val < fp->val) fp->left = S;
    else fp->right = S;
    S->height = 0;
    S->parent = fp;

    // update height
    update_height(S);

    // make sure B node
    if (val < A->val) {
        B = A->left;
    }
    else B = A->right;

    // according to the height of the nodes, judge the balencelost type and adjust it
    if (balence_factor(A) == 2 && balence_factor(B) == 1) { // LL
        // init
        B = A->left;

        // right rotate
        B->parent = A->parent;
        A->left = B->right;
        B->right = A;
        A->parent = B;

        // update the height
        A->height -= 2;
    }
    else if (balence_factor(A) == 2 && balence_factor(B) == -1) { // LR
        // init
        B = A->left;
        C = B->right;

        // LR rotate
        C->parent = A->parent;
        B->right = C->left;
        C->left = B;
        B->parent = C;
        A->left = C->right;
        C->right = A;
        A->parent = C;

        // update height
        ++(C->height);
        --(B->height);
        A->height -= 3;
    }
    else if (balence_factor(A) == -2 && balence_factor(B) == 1) { // RL
        // init
        B = A->right;
        C = B->left;

        // RL rotate
        C->parent = A->parent;
        B->left = C->right;
        C->right = B;
        B->parent = C;
        A->right = C->left;
        C->left = A;
        A->parent = C;

        // update height
        ++(C->height);
        --(B->height);
        A->height -= 3;
    }
    else if (balence_factor(A) == -2 && balence_factor(B) == -1) { // RR
        // init
        B = A->right;

        // left rotate
        B->parent = A->parent;
        A->right = B->left;
        B->left = A;
        A->parent = B;

        // update height
        A->height -= 2;
    }

    return root;
}

// 辅助函数，用于打印树的结构，简化为只打印每个节点的值和高度
void print_tree(node_t *root, int level) {
    if (root == NULL) return;
    print_tree(root->right, level + 1);
    for (int i = 0; i < level; i++) printf("   ");
    printf("%d(h=%d)\n", root->val, root->height);
    print_tree(root->left, level + 1);
}


int main() {
    node_t *root = NULL;

    // 直接创建并初始化根节点
    root = (node_t *) malloc(sizeof(node_t));
    if (root == NULL) {
        printf("分配内存失败。\n");
        return 1;
    }
    root->parent = NULL;
    root->val = 10; // 假设10是初始值
    root->height = 0; // 或者根据您的 AVL 树实现，这里可能是 0 或 1
    root->left = NULL;
    root->right = NULL;

    // 插入其他节点
    int values[ ] = { 5, 15, 3, 7, 13, 18, 2, 4, 6, 8 }; // 10已经是根节点，所以不再包含
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++) {
        root = avl_insert(root, values[i]);
        if (root == NULL) {
            printf("插入 %d 时出错。\n", values[i]);
            return 1;
        }
    }

    // 打印树结构
    printf("AVL树结构：\n");
    print_tree(root, 0);

    return 0;
}
