typedef struct node {
    int val;
    struct node *left;
    struct node *right;
    struct node *parent;
    int height; // height is refer to 从该节点到叶子节点的最长简单路径边的条数。
} node_t;