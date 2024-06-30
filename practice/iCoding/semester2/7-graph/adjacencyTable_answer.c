#include <stdio.h>
#include<stdlib.h>
#include "graph.h" //请勿删除，否则检查不通过


bool insert_arc(ListGraph* G, VertexType v, VertexType w) {
    // 查找顶点v和w在图中的位置
    int v1 = locate_vertex(G, v);
    if (v1 == -1) {
        return false; // 顶点v不存在，无法插入边
    }
    int v2 = locate_vertex(G, w);
    if (v2 == -1) {
        return false; // 顶点w不存在，无法插入边
    }

    // 检查边(v1, v2)是否已存在 顺便用pre找到vertex[v1]中的最后一个节点方便后续插入
    ArcNode* pre = G->vertex[v1].firstarc;
    ArcNode* p = G->vertex[v1].firstarc;
    while (p != NULL) {
        pre = p;
        if (p->adjvex == v2) {
            return false; // 边已存在，无法重复插入
        }
        p = p->nextarc;
    }

    // 创建新的边节点
    ArcNode* New = (ArcNode*) malloc(sizeof(ArcNode));
    if (New == NULL) {
        return false; // 内存分配失败
    }
    New->adjvex = v2;
    New->nextarc = NULL;

    // 将新节点插入到链表中
    if (pre == NULL) {
        G->vertex[v1].firstarc = New; // 若链表为空，则新节点为头节点
    }
    else {
        pre->nextarc = New; // 否则，在pre节点之后插入新节点
    }

    // 如果图是无向图，还需要插入边(v2, v1)
    if (G->type == UDG) {
        ArcNode* pre1 = G->vertex[v2].firstarc;
        ArcNode* p1 = G->vertex[v2].firstarc;
        while (p1 != NULL) {
            pre1 = p1;
            if (p1->adjvex == v1) {
                return false; // 边已存在，无法重复插入
            }
            p1 = p1->nextarc;
        }

        ArcNode* New1 = (ArcNode*) malloc(sizeof(ArcNode));
        if (New1 == NULL) {
            return false; // 内存分配失败
        }
        New1->adjvex = v1;
        New1->nextarc = NULL;

        if (pre1 == NULL) {
            G->vertex[v2].firstarc = New1; // 若链表为空，则新节点为头节点
        }
        else {
            pre1->nextarc = New1; // 否则，在pre1节点之后插入新节点
        }
    }

    G->arcnum++; // 增加边数
    return true; // 插入成功
}

bool del_vertex(ListGraph* G, VertexType v) {
    // 找到顶点在图中的位置
    int v1 = locate_vertex(G, v);
    if (v1 == -1) {
        return false; // 顶点不存在，返回false
    }

    // 删除与该顶点相关的边
    ArcNode* p1 = G->vertex[v1].firstarc; // 指向顶点的第一条边
    while (p1 != NULL) {
        ArcNode* temp = p1; // 保存当前边的指针
        G->vertex[v1].firstarc = p1->nextarc; // 修改顶点的第一条边指针
        p1 = p1->nextarc; // 指向下一条边
        free(temp); // 释放当前边的内存
        G->arcnum--; // 边数减一
    }

    // 删除顶点数组中该顶点
    for (int i = v1; i < G->vexnum; i++) {
        G->vertex[i] = G->vertex[i + 1];
    }
    G->vexnum--; // 顶点数减一

    // 更新其他顶点的邻接表
    ArcNode* p = NULL;
    for (int i = 0; i < G->vexnum; i++) {
        p = G->vertex[i].firstarc;
        while (p != NULL) {
            if (p->adjvex > v1) { // 由于之前删除顶点数组中该顶点时移动了顶点数组中的元素，所以要更新链表中所有>v1的编号
                p->adjvex--; // 更新顶点位置，减一
                p = p->nextarc;
            }
            else if (p->adjvex == v1) {
             // 找到与顶点v相关的边
                if (G->vertex[i].firstarc == p) {
                    // 删除顶点v是第一条边的情况
                    ArcNode* temp = p;
                    G->vertex[i].firstarc = p->nextarc; // 修改顶点的第一条边指针
                    p = p->nextarc; // 指向下一条边
                    free(temp); // 释放当前边的内存
                }
                else {
                 // 删除顶点v不是第一条边的情况
                    ArcNode* pre = G->vertex[i].firstarc;
                    while (pre->nextarc != p) {
                        pre = pre->nextarc;
                    }
                    ArcNode* temp = p;
                    pre->nextarc = p->nextarc; // 修改前一条边的指针
                    p = p->nextarc; // 指向下一条边
                    free(temp); // 释放当前边的内存
                }
                G->arcnum--; // 边数减一
            }
            else {
                p = p->nextarc;
            }
        }
    }
    return true; // 删除成功，返回true
}
