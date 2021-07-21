#ifndef MYGRAGH_H
#define MYGRAGH_H

#define MAXVEX 100 /* 最大顶点数，应由用户定义 */
#define GRAPH_INFINITY 65535 /* 用65535来代表∞ */
#define MAXEDGE 100 /* 边集数组大小，应由用户定义 */


/** 邻接矩阵(Adjacency Matrix 缩写: AdjMT) **/

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char VertexType; /* 顶点类型应由用户定义  */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */

int visited[MAXVEX];

typedef struct AdjMTGraghStruct{
    VertexType vexs[MAXVEX];  //顶点表
    EdgeType arc[MAXVEX][MAXVEX]; // 邻接矩阵，可看作边表
    int NumNodes, NumEdges; // 图中当前的顶点数和边数
} AdjMTGraghGragh, *PriorityAdjMTGragh;



/** 邻接表(Adjacency List 缩写: AdjList) **/

// 边表节点
typedef struct AdjListEdgeNode{  
    int adjvex; // 邻接点域,存储该顶点对应的下标
    EdgeType weight; // 用于存储权值,对于非网图可以不需要
    struct AdjListEdgeNode* next; // 错误定义方式 PriorityAdjListEdgeNode next
} AdjListEdgeNode, *PriorityAdjListEdgeNode;

// 顶点表节点
typedef struct AdjListVertexNode{
    VertexType data; // 顶点域,存储顶点信息
    PriorityAdjListEdgeNode firstedge; // 边表头指针
}AdjListVertexNode, 
    *PriorityAdjListVertexNode, AdjList[MAXVEX];

typedef struct AdjListGragh{
    AdjList adjList;
    int numNodes, numEdges; // 图中当前顶点数和边数
} AdjListGragh, *PriorityAdjListGragh;


// 对边集数组Edge结构的定义
typedef struct {
    int begin;
    int end;
    int weight;
} EdgeArray,  *PtrEdgeArray;


void CreateAdjMT(PriorityAdjMTGragh G);
void CreateAdjMT_2(PriorityAdjMTGragh G);
void CreateAdjMT_Weight(PriorityAdjMTGragh G);
void CreateAdjList(PriorityAdjListGragh G);
void CreateALGraph(AdjMTGraghGragh G, PriorityAdjListGragh GL);

/* 邻接矩阵的深度优先递归算法 */
void AdjMTDFS(AdjMTGraghGragh G, int i);
void AdjMTDFSTraverse(AdjMTGraghGragh G);

/* 邻接表的深度优先递归算法 */
void AdjListDFS(AdjListGragh GL, int i);
void AdjListDFSTraverse(AdjListGragh GL);

/*Prim算法生成最小生成树*/
int AdjMT_MibuSpanTree_Prim(AdjMTGraghGragh G);

int AdjMT_MiniSpanTree_Kruskal(AdjMTGraghGragh G);

int GraghDemo();

#endif