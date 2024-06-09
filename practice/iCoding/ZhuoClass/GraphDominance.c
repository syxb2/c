/**
 * @file GraphDominance.c
 * @author Bai Jiale (578767478@qq.com)
 * @brief 其中 edges 指向图的邻接矩阵，矩阵元素为对应边上的权重(权重为自然数)。
 * 定义图中0结点为入口结点；
 * 定义dom关系为：如果从图的入口结点（即0结点）到结点 n 的每条路径都经过结点 d ，则称结点 d 支配(dominate) n ，记为 d dom n。
 * 根据该定义，每个结点支配它自己，且入口结点（即0结点）支配包括它自己在内的所有结点。
 * 请使用上述数据结构，从标准输入读入一个图(该图为联通图)，请找出除入口结点外所有结点间的支配关系，并按下面示例样式输出：
 * 输入数据示例如下：
 * 5,6
 * 0,1,95
 * 0,2,41
 * 1,3,99
 * 1,4,67
 * 2,4,95
 * 3,4,99
 * 其中第1行分别为图中结点的个数 5、图中边的个数 6；之后的6行分别是各边的信息，以第2行为例，其表示结点0到1之间有权重为95的有向边，方向为0至1。根据支配关系的定义，该图的支配关系有：
 * 0 dom 0
 * 0 dom 1
 * 0 dom 2
 * 0 dom 3
 * 0 dom 4
 * 1 dom 1
 * 1 dom 3
 * 2 dom 2
 * 3 dom 3
 * 4 dom 4
 * 因0结点支配所有结点，所以不输出该信息；将其它支配关系按结点编号从小到大的顺序输出如下：
 * (1#1)(1#3)(2#2)(3#3)(4#4)
 * 其中每一对括号表示一个支配关系，# 表示　dom。
 * @version 0.1
 * @date 2024-06-09
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_VERTEX_NUM  50
#define ZERO            0
#define true            1
#define false           0


typedef struct GraphStruct {
    int vertex_num;
    int edge_num;
    int **edges;
} GraphStruct;

typedef struct GraphStruct *Graph;
typedef unsigned int Vertex;

typedef struct {
    Vertex v;
    Vertex w;
    int weight;
} Edge;


int visited[MAX_VERTEX_NUM + 1] = { 0 };


/**
 * @brief Create a Graph object
 *
 * @param graph
 */
void CreateGraph(Graph graph, Edge **edge) {
    int n, m; // n: vertex number, m: edge number
    int v1, v2, weight; // v1, v2: vertex number, weight: edge weight

    scanf("%d,%d", &n, &m);
    graph->vertex_num = n;
    graph->edge_num = m;
    getchar(); // skip '\n'

    // allocate memory for the Adjacency matrix
    graph->edges = (int**) malloc(graph->vertex_num * sizeof(int*));
    for (int i = 0; i < graph->vertex_num; ++i) {
        graph->edges[i] = (int *) malloc(graph->vertex_num * sizeof(int));
    }
    // initialize the Adjacency matrix
    for (int i = 0; i < graph->vertex_num; ++i) {
        for (int j = 0; j < graph->vertex_num; ++j) {
            graph->edges[i][j] = ZERO;
        }
    }

    // allcate memory for the edge array
    edge = (Edge**) malloc(graph->edge_num * sizeof(Edge*));
    for (int i = 0; i < graph->edge_num; ++i) {
        edge[i] = (Edge *) malloc(sizeof(Edge));
    }

    // write the edge information
    for (int i = 0; i < graph->edge_num; ++i) {
        scanf("%d,%d,%d", &v1, &v2, &weight);
        edge[i]->v = v1;
        edge[i]->w = v2;
        edge[i]->weight = weight;
        if (weight != 0) weight = 1;
        graph->edges[v1][v2] = weight;
        // graph->edges[v2][v1] = weight;
    }

    return;
}

/**
 * @brief depth first search
 * 
 * @param graph 
 * @param tree 
 * @param Now 
 */
void DFS(Graph graph, int ***tree, int Now) {
    visited[Now] = true;
    for (int i = 0; i < graph->vertex_num; ++i) {
        if (graph->edges[Now][i] != ZERO && !visited[i]) {
            visited[i] = true;
            (*tree)[Now][i] = true;
            DFS(graph, tree, i);
        }
    }

    return;
}

/**
 * @brief build the DFS tree
 * 
 * @param graph 
 * @param vertex_num 
 * @return int** 
 */
int** DFSTree(Graph graph, int vertex_num) {
    // allocate memory for the tree
    int **tree = (int **) malloc(sizeof(int *) * vertex_num);
    for (int i = 0; i < vertex_num; ++i) {
        tree[i] = (int *) malloc(sizeof(int) * vertex_num);
    }

    // initialize the tree
    for (int i = 0; i < vertex_num; ++i) {
        for (int j = 0; j < vertex_num; ++j) {
            tree[i][j] = ZERO;
        }
    }

    // DFS
    DFS(graph->edges, &tree, 0);

    return tree;
}


int main() {

}