typedef int ElemType;

// 非零元素结点结构
typedef struct OLNode {
    int row, col;
    ElemType value;
    struct OLNode *right, *down;
} OLNode, *OLink;

// 十字链表结构
typedef struct {
    OLink *rowhead, *colhead;
    int rows, cols, nums; // nums 为非零元素个数
} CrossList, *PCrossList;
