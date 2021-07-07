#include "../inc/mygragh.h"
#include "../inc/ComFun.h"

// 邻接矩阵初始化图
void CreateAdjMT(PriorityAdjMTGragh G){

    int i, j, k, w;
    int NumNodes = 3, NumEdges = 3;
    G->NumNodes = NumNodes; // 顶点数
    G->NumEdges = NumEdges; // 边数

    char vexs[3] = {'a', 'b', 'c'};

    // 邻接矩阵初始化
    for(i = 0; i < G->NumNodes; i++)
        for(j = 0; j < G->NumNodes; j++){
            G->arc[i][j] = GRAPH_INFINITY; 
        }

    // 初始化顶点值
    for(i = 0; i < G->NumNodes; i++){
        G->vexs[i] = vexs[i];
    }

    // 读入numEdges条边，建立邻接矩阵
    for(k = 0; k < G->NumEdges; k++){
        for(i = 0; i < G->NumNodes; i++)
            for(j = i+1; j < G->NumNodes; j++){
                G->arc[i][j] = GenRandomNum(10);
                G->arc[j][i] = G->arc[i][j]; // 因为是无向图，矩阵对称
            }
    }
}

// 邻接表初始化图
void CreateAdjList(PriorityAdjListGragh G){
    int i, j, k;
    int vi, vj;
    PriorityAdjListEdgeNode edgenode;
    int NumNodes = 3, NumEdges = 3;
    G->numNodes = NumNodes;
    G->numEdges = NumEdges;

    // 建立顶点域信息
    for(i = 0; i < G->numNodes; i++){
        G->adjList[i].data = i;
        G->adjList[i].firstedge = NULL;
    }

    // 建立边表
    for(j = 0; j < G->numEdges; j++){
		printf("输入边(vi,vj)上的顶点序号:\n");
        scanf("%d, %d", &vi, &vj);  // 输入边(vi,vj)上的顶点序号
        printf("(vi,vj):(%d, %d)\n", vi, vj);
        edgenode = (PriorityAdjListEdgeNode)malloc(sizeof(AdjListEdgeNode)); 
        edgenode->adjvex = vj;
        edgenode->weight = GenRandomNum(10); // 权重随机赋值
        edgenode->next = G->adjList[vi].firstedge; // 将e的指针指向当前顶点上指向的结点
        G->adjList[vi].firstedge = edgenode; // 将当前顶点的指针指向e

        edgenode = (PriorityAdjListEdgeNode)malloc(sizeof(AdjListEdgeNode)); 
        edgenode->adjvex = vi;
        edgenode->weight = GenRandomNum(10); // 权重随机赋值
        edgenode->next = G->adjList[j].firstedge; // 将e的指针指向当前顶点上指向的结点
        G->adjList[vj].firstedge = edgenode; // 将当前顶点的指针指向e

    }


}


int GraghDemo(){

    // 邻接矩阵初始化图
    AdjMTGraghGragh AdjMTG;
    CreateAdjMT(&AdjMTG);

    // 邻接表初始化图
    AdjListGragh AdjList;
    CreateAdjList(&AdjList);

    return 0;
}