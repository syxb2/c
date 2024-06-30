#include <stdio.h>
#include "graph.h" // 请不要删除，否则检查不通过


/**
 * @brief insert vertex : 当成功插入顶点或边时，函数返回true，否则（如顶点或边已存在、插入边时顶点v或w不存在）返回false。
 * 
 * @param G 
 * @param v 
 * @return true 
 * @return false 
 */
bool matrix_insert_vertex(MatrixGraph *G, VertexType v){
    if (G == NULL) return false; // 如果图为空
    if (G->vexnum == MAX_VERTEX_NUM) return false; // 如果顶点数量已经达到最大值
    if (matrix_locate_vertex(G, v) != -1) return false; // 顶点已经存在

    // 增加顶点
    ++(G->vexnum);
    G->vertex[G->vexnum - 1] = v;

    // 增加边
    for (int i = 0; i < G->vexnum; ++i) {
        G->arcs[i][G->vexnum - 1] = 0;
        G->arcs[G->vexnum - 1][i] = 0;
    }

    return true;
}


/**
 * @brief insert arc
 * 
 * @param G 
 * @param v 
 * @param w 
 * @return true 
 * @return false 
 */
bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w){
    if (G == NULL) return false; // 如果图为空，返回false
    if (matrix_locate_vertex(G, v) == -1 || matrix_locate_vertex(G, w) == -1) return false; // 如果顶点不存在，返回 false

    if (G->type == DG) { // 如果 G 是 有向图
        if (G->arcs[matrix_locate_vertex(G, v)][matrix_locate_vertex(G, w)] == 1) return false; // 如果 边 已经存在

        G->arcs[matrix_locate_vertex(G, v)][matrix_locate_vertex(G, w)] = 1;
        ++(G->arcnum);
    }
    else if (G->type == UDG) { // 如果 G 是 无向
        if (G->arcs[matrix_locate_vertex(G, v)][matrix_locate_vertex(G, w)] == 1) return false; // 如果 边 已经存在

        G->arcs[matrix_locate_vertex(G, v)][matrix_locate_vertex(G, w)] = 1;
        G->arcs[matrix_locate_vertex(G, w)][matrix_locate_vertex(G, v)] = 1;
        ++(G->arcnum);
    }

    return true;
}
