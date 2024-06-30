#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

int get_height(node_t* n) {
    if (n == NULL)
        return 0;
    return n->height;
}

int get_balance_factor(node_t* n) {
    if (n == NULL)
        return 0;
    return get_height(n->left) - get_height(n->right);
}

void update_height(node_t* n) {
    int left_height = get_height(n->left);
    int right_height = get_height(n->right);
    n->height = (left_height > right_height ? left_height : right_height) + 1;
}

node_t* create_node(int value) {
    node_t* new_n = (node_t*)malloc(sizeof(node_t));
    new_n->val = value;
    new_n->left = NULL;
    new_n->right = NULL;
    new_n->parent = NULL;
    new_n->height = 1;
    return new_n;
}

node_t* left_rotate(node_t* root) {
    node_t* pivot = root->right;
    node_t* temp = pivot->left;

    pivot->left = root;
    root->right = temp;

    update_height(root);
    update_height(pivot);

    return pivot;
}

node_t* right_rotate(node_t* root) {
    node_t* pivot = root->left;
    node_t* temp = pivot->right;

    pivot->right = root;
    root->left = temp;

    update_height(root);
    update_height(pivot);

    return pivot;
}

node_t* avl_insert(node_t* root, int val) {
    if (root == NULL)
        return create_node(val);

    if (val < root->val) {
        root->left = avl_insert(root->left, val);
        root->left->parent = root;
    } else if (val > root->val) {
        root->right = avl_insert(root->right, val);
        root->right->parent = root;
    } else
        return root;

    update_height(root);

    int balance = get_balance_factor(root);

    if (balance > 1 && val < root->left->val)
        return right_rotate(root);

    if (balance < -1 && val > root->right->val)
        return left_rotate(root);

    if (balance > 1 && val > root->left->val) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    if (balance < -1 && val < root->right->val) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}