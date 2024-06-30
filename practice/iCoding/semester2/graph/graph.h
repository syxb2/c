#pragma once

#define MAX_VERTEX_NUM  20
#define InfoPtr         int
#define true            1
#define false           0

/* ------------------------------------------------------------------------------ */

typedef int VertexType;

typedef enum {
    DG, UDG
} GraphType;

typedef struct {
    VertexType vertex[MAX_VERTEX_NUM]; //顶点向量
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵
    int vexnum, arcnum; //图的当前顶点数和弧数
    GraphType type; //图的种类标志
} MatrixGraph;

int matrix_locate_vertex(MatrixGraph *MG, VertexType vex); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool matrix_insert_vertex(MatrixGraph *G, VertexType v);
bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w);

/* ------------------------------------------------------------------------------ */

typedef int VertexType;

typedef struct ArcNode {
    int adjvex; // 表示这条边指向的顶点的索引
    InfoPtr *info; // 边的信息指针
    struct ArcNode *nextarc; // 指向下一个边的指针
} ArcNode; // 表示边的结构体。

typedef struct VNode {
    VertexType data; // 顶点的数据
    ArcNode *firstarc; // 指向这个顶点第一条边的指针
} VNode; // 表示图中的一个顶点

typedef struct {
    VNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphType type;
} ListGraph; // 表示整个图

int locate_vertex(ListGraph *G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool del_vertex(ListGraph *G, VertexType v); //删除顶点 v
bool insert_vertex(ListGraph *G, VertexType v);
bool insert_arc(ListGraph *G, VertexType v, VertexType w);

int locate_vertex(ListGraph *G, VertexType v) {
    for (int i = 0; i < G->vexnum; ++i) {
        if (G->vertex[i].data == v) {
            return i; // 返回顶点v在数组中的索引
        }
    }
    return -1; // 如果顶点v不存在，返回-1
}
