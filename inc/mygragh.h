#ifndef MYGRAGH_H
#define MYGRAGH_H

#define MAXVEX 100 /* 最大顶点数，应由用户定义 */
#define GRAPH_INFINITY 65535 /* 用65535来代表∞ */

/** 邻接矩阵(Adjacency Matrix 缩写: AdjMT) **/

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char VertexType; /* 顶点类型应由用户定义  */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */

typedef struct AdjMTGraghStruct{
    VertexType vexs[MAXVEX];  //顶点表
    EdgeType arc[MAXVEX][MAXVEX]; // 邻接矩阵，可看作边表
    int NumNodes, NumEdges; // 图中当前的顶点数和边数
} AdjMTGraghGragh, *PriorityAdjMTGragh;



/** 邻接表(Adjacency List 缩写: AdjList) **/
typedef struct AdjListEdgeNode{  // 边表节点
    int adjvex; // 邻接点域,存储该顶点对应的下标
    EdgeType weight; // 用于存储权值,对于非网图可以不需要
    struct AdjListEdgeNode* next; // 错误定义方式 PriorityAdjListEdgeNode next
} AdjListEdgeNode, *PriorityAdjListEdgeNode;

typedef struct AdjListVertexNode{
    VertexType data; // 顶点域,存储顶点信息
    PriorityAdjListEdgeNode firstedge; // 边表头指针
}AdjListVertexNode, 
    *PriorityAdjListVertexNode, AdjList[MAXVEX];

typedef struct AdjListGragh{
    AdjList adjList;
    int numNodes, numEdges; // 图中当前顶点数和边数
} AdjListGragh, *PriorityAdjListGragh;

void CreateAdjMT(PriorityAdjMTGragh G);
void CreateAdjList(PriorityAdjListGragh G);


int GraghDemo();

#endif