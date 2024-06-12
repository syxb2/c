/**
 * @file isThereRing.c
 * @author Bai Jiale (578767478@qq.com)
 * @brief * 其中 edges 指向图的邻接矩阵，矩阵元素为对应边上的权重(权重为自然数)，请使用该数据结构，从标准输入读入一个图，并判断该图是否有环，如果有环，则输出yes，否则输出no。 * * 输入数据示例如下： * * 15,7 * 0,7,69 * 1,10,68 * 3,9,71 * 3,12,92 * 4,6,71 * 4,8,6 * 5,10,83 * * 其中第１行分别为图中结点的个数 15、图中边的个数 7；之后的7行分别是各边的信息，以第2行为例，其表示结点0和7之间有权重为69的无向边。
 * @version 0.1
 * @date 2024-06-09
 * 
 * @copyright Copyright (c) 2024
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
        graph->edges[v2][v1] = weight;
    }

    return;
}

/**
 * @brief Matrix multiply
 * 
 * @param A 
 * @param B 
 * @param n 
 * @return int** 
 */
int** Matrix_multiply(int **A, int **B, int n) {
    int **C = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        C[i] = (int *) malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int main_oldversion() {
    Graph G = (Graph) malloc(sizeof(GraphStruct)); // here sizeof(GraphStruct) is int + int + int**
    CreateGraph(G, NULL);

    // create a 3D array to store the result of A^1, A^2, ..., A^n
    int ***A = (int ***) malloc(G->vertex_num * sizeof(int **));
    A[0] = G->edges;
    for (int i = 1; i < G->vertex_num; ++i) {
        A[i] = Matrix_multiply(A[i-1], G->edges, G->vertex_num);
    }

    // create a 2D array to store the sum of A^1, A^2, ..., A^n
    int **B = (int **) malloc(G->vertex_num * sizeof(int *));
    for (int i = 0; i < G->vertex_num; ++i) {
        B[i] = (int *) malloc(G->vertex_num * sizeof(int));
    }
    for (int i = 0; i < G->vertex_num; ++i) {
        for (int j = 0; j < G->vertex_num; ++j) {
            B[i][j] = 0;
            for (int k = 0; k < G->vertex_num; ++k) {
                B[i][j] += A[k][i][j];
            }
        }
    }

    // check if there is a ring in the graph
    int flag = 0;
    for (int i = 0; i < G->vertex_num; ++i) {
        flag += B[i][i];
    }
    flag -= G->vertex_num;

    if (flag > 0) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}

/**
 * @brief depth first search for the graph
 * @explain: 图 G 的每个连通分支都会被遍历。对于各个联通分支，循环中总有一种情况是可以把所有结点全部遍历的。若某个结点被访问过，且此结点所在的联通分支中有环的话，那么这个联通分支中的所有结点都会被访问到，且 visited[for in 联通分支] == 1。
 * 
 * @param Now 
 * @param Pre 
 * @param G 
 * @return true 
 * @return false 
 */
bool DFS(int Now, int Pre, Graph G) {
    visited[Now] = 1;

    for (int i = 0; i < G->vertex_num; ++i) {
        if (G->edges[Now][i] == 1 && i != Pre) {
            // 首先判断结束条件
            if (visited[i] == 1) return true;
            // 若不结束 则递归遍历下个结点
            else if (DFS(i, Now, G)) return true;
        }
    }

    return false;
}

/**
 * @brief check if there is a ring in the graph
 * 
 * @param G 
 * @return true 
 * @return false 
 */
bool IsThereRing(Graph G) {
    for (int i = 0; i < G->vertex_num; ++i) {
        if (visited[i] == 0) {
            if (DFS(i, -1, G)) return true;
        }
    }

    return false;
}


int main() {
    Edge* E = NULL;

    Graph G = (Graph) malloc(sizeof(GraphStruct)); // here sizeof(GraphStruct) is int + int + int**
    CreateGraph(G, &E);

    if (IsThereRing(G)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
