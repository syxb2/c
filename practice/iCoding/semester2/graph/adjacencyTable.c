#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h" //请勿删除，否则检查不通过


/**
 * @brief insert vertex
 * @attention do not need to allocate memory to the vertex array
 *
 * @param G
 * @param v
 * @return true
 * @return false
 */
bool insert_vertex(ListGraph *G, VertexType v) {
    if (G == NULL) return false; // if the graph is empty
    if (locate_vertex(G, v) != -1) return false; // if v is already existing
    if (G->vexnum == MAX_VERTEX_NUM) return false; // if vexnum is already reach the max number

    ++(G->vexnum);
    G->vertex[G->vexnum - 1].data = v;
    G->vertex[G->vexnum - 1].firstarc = NULL;

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
bool insert_arc(ListGraph *G, VertexType v, VertexType w) {
    if (G == NULL) return false; // if the graph is empty
    int v1 = locate_vertex(G, v), v2 = locate_vertex(G, w);
    if (v2 == -1 || v2 == -1) return false; // if vertex v or w do not exist

    if (G->type == DG) { // if G is Directed Graph
        ArcNode *p = G->vertex[v1].firstarc;
        while (true) {
            if (p->adjvex == v2) return false; // if the arc is already existing
            p = p->nextarc;
            if (p->nextarc == NULL) break;
        } // at the time p is the last arc

        ArcNode* S = (ArcNode*) malloc(sizeof(ArcNode)); if (S == NULL) return false;
        S->adjvex = v2;
        S->nextarc = NULL;
        if (G->vertex[v1].firstarc == NULL) G->vertex[v1].firstarc = S;
        else p->nextarc = S;
    }
    else if (G->type == UDG) { // if G is UnDirected Graph
        ArcNode *p = G->vertex[v1].firstarc;
        while (p != NULL) {
            if (p->adjvex == v2) return false; // if the arc is already existing
            p = p->nextarc;
        }

        // insert the arc v to w
        ArcNode* S1 = (ArcNode*) malloc(sizeof(ArcNode)); if (S1 == NULL) return false;
        S1->adjvex = v2;
        S1->nextarc = NULL;
        ArcNode *q = G->vertex[v1].firstarc;
        if (q == NULL) G->vertex[v1].firstarc = S1;
        else {
            while (q->nextarc != NULL) q = q->nextarc;
            q->nextarc = S1;
        }

        // insert the arc w to v
        ArcNode* S2 = (ArcNode*) malloc(sizeof(ArcNode)); if (S2 == NULL) return false;
        S2->adjvex = v1;
        S2->nextarc = NULL;
        ArcNode *r = G->vertex[v2].firstarc;
        if (r == NULL) G->vertex[v2].firstarc = S2;
        else {
            while (r->nextarc != NULL) r = r->nextarc;
            r->nextarc = S2;
        }
    }
    ++(G->arcnum);

    return true;
}

/**
 * @brief delete vertex
 *
 * @param G
 * @param v
 * @return true
 * @return false
 */
bool del_vertex(ListGraph *G, VertexType v) {
    int v1 = locate_vertex(G, v);
    if (v1 == -1) return false; // if v do not exist
    ArcNode *p = NULL;

    // 释放 以顶点 v 为入度的边
    p = G->vertex[v1].firstarc;
    while (p != NULL) {
        ArcNode *t = p;
        p = p->nextarc;
        free(t);
        --(G->arcnum);
    }
    G->vertex[v1].firstarc = NULL;

    // 释放 顶点数组中 顶点v 的内存
    for (int i = v1; i < G->vexnum; ++i) {
        G->vertex[i] = G->vertex[i + 1];
    }
    --(G->vexnum);

    // 释放 其他顶点连接到 v 的边（以顶点 v 为出度的边）
    for (int i = 0; i < G->vexnum; ++i) {
        p = G->vertex[i].firstarc; // p 是 遍历指针
        while (p != NULL) {
            if (G->vertex[i].firstarc->adjvex == v1) {
                ArcNode *t = G->vertex[i].firstarc;
                G->vertex[i].firstarc = t->nextarc;
                free(t);
                --(G->arcnum);
            }

            if (p->adjvex > v1) {
                --(p->adjvex); // 更新顶点位置，减一
                p = p->nextarc;
            }
            else if (p->adjvex == v1) {
                ArcNode *t = p;
                p = G->vertex[i].firstarc;
                while (p->nextarc != t) p = p->nextarc;

                p->nextarc = t->nextarc;
                free(t);
                --(G->arcnum);
                p = p->nextarc;
            }
            else {
                p = p->nextarc;
            }
        }
    }

    return true;
}

// 测试 del_vertex 函数
void test_del_vertex() {
    ListGraph G;
    G.vexnum = 3;
    G.arcnum = 2;
    G.type = UDG;
    G.vertex[0].data = 1;
    G.vertex[1].data = 2;
    G.vertex[2].data = 3;

    // 构建边 1->2
    G.vertex[0].firstarc = (ArcNode*) malloc(sizeof(ArcNode));
    G.vertex[0].firstarc->adjvex = 1;
    G.vertex[0].firstarc->nextarc = NULL;

    // 构建边 2->3
    G.vertex[1].firstarc = (ArcNode*) malloc(sizeof(ArcNode));
    G.vertex[1].firstarc->adjvex = 2;
    G.vertex[1].firstarc->nextarc = NULL;

    // 顶点3没有出度
    G.vertex[2].firstarc = NULL;

    // 删除顶点2，期望结果是顶点2被删除，边1->2也被删除
    bool result = del_vertex(&G, 2);
    assert(result == true); // 确保删除成功
    assert(G.vexnum == 2); // 确保顶点数减少
    assert(G.arcnum == 1); // 确保边数减少
    assert(G.vertex[0].firstarc != NULL); // 确保顶点1的边未被删除
    assert(G.vertex[1].data == 3); // 确保顶点3向前移动
    assert(G.vertex[1].firstarc == NULL); // 确保顶点3的边正确

    printf("All tests passed.\n");
}

int main() {
    test_del_vertex();
    return 0;
}