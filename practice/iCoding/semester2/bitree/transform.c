#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"


BiTNode* transform(CSNode *root) {
    if (root == NULL) return NULL;

    // Initialization
    Queue* Q = create_queue();
    if (Q == NULL) return NULL;

    CSNode* CNode = root;

    BiTree BNode = (BiTree) malloc(sizeof(BiTNode));
    if (BNode == NULL) {
        free(Q->array);
        free(Q);
        return NULL;
    }
    BNode->left = NULL;
    BNode->right = NULL;

    BiTree out = BNode;

    BiTree new = NULL;
    BNode->data = CNode->data;
    BiTree last = NULL;

    add_queue(Q, CNode);
    add_queue(Q, BNode);

    // In while
    while (!is_empty_queue(Q)) {
        CNode = del_queue(Q); // CNode is the current node in the CSNode tree
        BNode = del_queue(Q); // BNode is the current node in the BiTree tree

        for (int i = 0; CNode->children[i] != NULL; ++i) {
            add_queue(Q, CNode->children[i]);

            new = (BiTree) malloc(sizeof(BiTNode));
            if (new == NULL) return NULL;
            new->left = NULL;
            new->right = NULL;
            add_queue(Q, new);

            new->data = CNode->children[i]->data;

            if (i == 0) {
                BNode->left = new;
            }
            else {
                last->right = new;
            }
            last = new;
        }
    }

    free(Q->array);
    free(Q);

    return out;
}

int main() {

    return 0;
}