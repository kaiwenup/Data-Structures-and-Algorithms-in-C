#include "../inc/mygragh.h"
#include "../inc/ComFun.h"
#include "../inc/myLinkQueue.h"
// 邻接矩阵初始化图
// 创建无向完全图
void CreateAdjMT(PriorityAdjMTGragh G){

    int i, j, k, w;
    int NumNodes = 8, NumEdges = 28;
    G->NumNodes = NumNodes; // 顶点数
    G->NumEdges = NumEdges; // 边数

    char vexs[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

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

// 创建非完全无向图
void CreateAdjMT_2(PriorityAdjMTGragh G){
    
    int i, j;
    G->NumEdges = 15;
    G->NumNodes = 8;

    // 读入顶点信息,建立顶点表
    G->vexs[0]='A';
	G->vexs[1]='B';
	G->vexs[2]='C';
	G->vexs[3]='D';
	G->vexs[4]='E';
	G->vexs[5]='F';
	G->vexs[6]='G';
	G->vexs[7]='H';
	G->vexs[8]='I';

    for (i = 0; i < G->NumNodes; i++)/* 初始化图 */
	{
		for ( j = 0; j < G->NumNodes; j++)
		{
			G->arc[i][j]=0;
		}
	}

    G->arc[0][1]=1;
	G->arc[0][5]=1;

	G->arc[1][2]=1; 
	G->arc[1][8]=1; 
	G->arc[1][6]=1; 
	
	G->arc[2][3]=1; 
	G->arc[2][8]=1; 
	
	G->arc[3][4]=1;
	G->arc[3][7]=1;
	G->arc[3][6]=1;
	G->arc[3][8]=1;

	G->arc[4][5]=1;
	G->arc[4][7]=1;

	G->arc[5][6]=1; 
	
	G->arc[6][7]=1; 

    for(i = 0; i < G->NumNodes; i++)
	{
		for(j = i; j < G->NumNodes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
		}
	}
}

// 带权重的非完全无向图
void CreateAdjMT_Weight(PriorityAdjMTGragh G){

    int i, j;

	/* printf("请输入边数和顶点数:"); */
	G->NumEdges=15;
	G->NumNodes=9;

    G->vexs[0]='A';
	G->vexs[1]='B';
	G->vexs[2]='C';
	G->vexs[3]='D';
	G->vexs[4]='E';
	G->vexs[5]='F';
	G->vexs[6]='G';
	G->vexs[7]='H';
	G->vexs[8]='I';

	for (i = 0; i < G->NumNodes; i++)/* 初始化图 */
	{
		for ( j = 0; j < G->NumNodes; j++)
		{
			if (i==j)
				G->arc[i][j]=0;
			else
				G->arc[i][j] = G->arc[j][i] = GRAPH_INFINITY;
		}
	}

	G->arc[0][1]=10;
	G->arc[0][5]=11; 
	G->arc[1][2]=18; 
	G->arc[1][8]=12; 
	G->arc[1][6]=16; 
	G->arc[2][8]=8; 
	G->arc[2][3]=22; 
	G->arc[3][8]=21; 
	G->arc[3][6]=24; 
	G->arc[3][7]=16;
	G->arc[3][4]=20;
	G->arc[4][7]=7; 
	G->arc[4][5]=26; 
	G->arc[5][6]=17; 
	G->arc[6][7]=19; 

	for(i = 0; i < G->NumNodes; i++)
	{
		for(j = i; j < G->NumNodes; j++)
		{
			G->arc[j][i] =G->arc[i][j];
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

/* 利用邻接矩阵构建邻接表 */
void CreateALGraph(AdjMTGraghGragh G, PriorityAdjListGragh GL){

    int i, j;
    PriorityAdjListEdgeNode e;
    // GL = (PriorityAdjListGragh)malloc(sizeof(AdjListGragh)); // ！！！ 错误语句

    GL->numNodes = G.NumNodes;
    GL->numEdges = G.NumEdges;

    // 读入顶点信息，建立顶点表
    for(i = 0; i < GL->numNodes; i++){

        GL->adjList[i].data = G.vexs[i];
        GL->adjList[i].firstedge = NULL;
    }

    // 建立边表
    for(i = 0; i< GL->numNodes; i++){

        for(j = 0; j < GL->numNodes; j++){
            
            if(G.arc[i][j] == 1){

                e = (PriorityAdjListEdgeNode)malloc(sizeof(AdjListEdgeNode));
                e->adjvex = j;  // 邻接序号为j
                e->next = GL->adjList[i].firstedge;  // 将当前顶点上的指向的结点指针赋值给e
                GL->adjList[i].firstedge = e;  // 将当前顶点的指针指向e

            }
        }
    }

}


/** 邻接矩阵实现深度优先遍历算法 **/
// 深度优先遍历 Depth First Search(DFS)
// 邻接矩阵的深度优先递归算法
void AdjMTDFS(AdjMTGraghGragh G, int i){

    int j;
    visited[i] = 1;

    printf("%c ", G.vexs[i]);

    for(j = 0; j < G.NumNodes; j++){
        if(G.arc[i][j] == 1 && !visited[i] )
           AdjMTDFS(G, j); 
    }
}

// 邻接矩阵的深度遍历操作
void AdjMTDFSTraverse(AdjMTGraghGragh G){
    int i;
    for(i = 0; i < G.NumNodes; i++){
        visited[i] = 0;
    }

    for(i = 0; i < G.NumNodes; i++){
        if(!visited[i])
            AdjMTDFS(G, i);
    }
}

/** 邻接表实现深度优先遍历算法 **/
void AdjListDFS(AdjListGragh GL, int i){

    PriorityAdjListEdgeNode p = NULL;
    visited[i] = 1;

    printf("%c ", GL.adjList[i].data); // 打印顶点,也可以其它操作
    
    p = GL.adjList[i].firstedge;

    while(p){

        if(!visited[p->adjvex])
            AdjListDFS(GL, p->adjvex);

        p = p->next;
        
    }
}

void AdjListDFSTraverse(AdjListGragh GL){
    int i;
    for(i = 0; i < GL.numNodes; i++){
        visited[i] = 0;
    }

    for(i = 0; i < GL.numNodes; i++){
        if(!visited[i]){
            AdjListDFS(GL, i);
        }
    }

}

/**邻接矩阵的广度遍历算法**/
// 广度优先遍历 Breadth Frist Search(BFS)
void AdjMTBFSTraverse(AdjMTGraghGragh G){

    int i, j;
    LinkQueue Q;
    i=InitQueue(&Q);
    if(!i)
		printf("创建空队列失败\n");
    
    for(i = 0; i < G.NumNodes; i++){
        visited[i] = 0;
    }

    for(i = 0; i < G.NumNodes; i++){

        if(!visited[i]){
            visited[i] = 1;
            printf("%c ", G.vexs[i]);

            EnQueue(&Q, i);

            while(!QueueEmpty(Q)){

                i = DeQueue(&Q);

                for(j = 0; j < G.NumNodes; j++){

                    if(G.arc[i][j] == 1 && !visited[i]){
                        
                        visited[j] = 1;
                        printf("%c ", G.vexs[j]);
                        EnQueue(&Q, j);

                    }
                }
            }
        }
    }
}

/**邻接表的广度遍历算法**/
void AdjListBFSTraverse(AdjListGragh GL){
    int i;

    LinkQueue Q;
    PriorityAdjListEdgeNode p = NULL;

    i=InitQueue(&Q);
    if(!i)
		printf("创建空队列失败!\n");
    
    for(i = 0; i < GL.numNodes; i++){
        visited[i] = 0;
    }

    for(i = 0; i < GL.numNodes; i++){

        if(!visited[i]){

            visited[i] = 1;
            printf("%c ", GL.adjList[i].data);
        

            EnQueue(&Q, i);

            while(!QueueEmpty(Q)){

                i = DeQueue(&Q); 
                p = GL.adjList[i].firstedge;

                while(p){
                    
                    if(!visited[p->adjvex]){

                        visited[p->adjvex] = 1;
                        printf("%c ", GL.adjList[p->adjvex].data);
                        EnQueue(&Q, p->adjvex);
                    }

                    p = p->next;
                }
            }


            

        }
    }

}

/*普里姆(Prim)算法生成最小生成树 - 邻接矩阵实现*/
int AdjMT_MibuSpanTree_Prim(AdjMTGraghGragh G){

    int min; // 暂存最小值 
    int k;   // 暂存对应的节点
    int i, j ; 

    int adjvex[MAXVEX]; // 保存相关顶点坐标
    int lowcost[MAXVEX]; // 保存相关顶点间边的权值

    int TotalWeight = 0;

    adjvex[0] = 0;
    lowcost[0] = 0;

    for(i = 1; i < G.NumNodes; i++){
        
        lowcost[i] = G.arc[0][i];
        adjvex[i] = 0;

    }

    for(i = 1; i < G.NumNodes; i++){

        min = GRAPH_INFINITY;
        j = 1; k = 0;

        while(j < G.NumNodes){

            if(lowcost[j] != 0 && lowcost[j] < min){

                min = lowcost[j];
                k = j;

            }

            j++;
        }


        TotalWeight += min;
        printf("(%d, %d | weight: %2d) -> ", adjvex[k], k, min);

        lowcost[k] = 0;

        for(j = 1; j < G.NumNodes; j++){

            if(lowcost[j] != 0 && G.arc[k][j] < lowcost[j]){

                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }


        
    }


    return TotalWeight;

}


/*克鲁斯卡尔(Kruskal)算法生成最小生成树 - 邻接矩阵实现*/
void EdgeArraySwapn(PtrEdgeArray edges, int i, int j){
    int temp;

	temp = edges[i].begin;
	edges[i].begin = edges[j].begin;
	edges[j].begin = temp;
	temp = edges[i].end;
	edges[i].end = edges[j].end;
	edges[j].end = temp;
	temp = edges[i].weight;
	edges[i].weight = edges[j].weight;
	edges[j].weight = temp;


}

void EdgeArraySort(PtrEdgeArray edges , int k){

    int i, j;

    for(i = 0; i < k; i++){
        for(j = i+1; j < k; j++){
            if(edges[i].weight > edges[j].weight){
                EdgeArraySwapn(edges, i, j);
            }
        }
    }

    // printf("权排序之后的为:\n");
	for (i = 0; i < k; i++)
	{
		// printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
	}

}

// 查找连线顶点的尾部下标
int ParentFind(int *parent, int f){

    while(parent[f] > 0)
        f = parent[f];

    return f;
        

}

// Kruskal算法生成最小生成树
int AdjMT_MiniSpanTree_Kruskal(AdjMTGraghGragh G){

    int i, j , n , m;
    int k = 0;
    int TotalWeight = 0;
    int parent[MAXVEX]; // 定义一数组用来判断边与边是否形成环路
    EdgeArray edges[MAXEDGE]; //定义边集数组,edge的结构为begin,end,weight,均为整型
    
    // 构建边集数组
    for(i = 0; i < G.NumNodes; i++){
        for(j = i+1; j < G.NumNodes; j++){
            if(G.arc[i][j] < GRAPH_INFINITY){
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = G.arc[i][j];
                k++;
            }
        }
    }

    // 根据权重给边集数组排序
    EdgeArraySort(edges, k);


    // 初始化parent数组
    for(i = 0; i < k; i++){
        parent[i] = 0;
    }


    for(i = 0; i < k; i++){
        n = ParentFind(parent, edges[i].begin);
        m = ParentFind(parent, edges[i].end);

        if(m != n){  // 假如n与m不等，说明此边没有与现有的生成树形成环路
            parent[n] = m; // 将此边的结尾顶点放入下标为起点的parent中, 表示此顶点已经在生成树集合中
            printf("(%d, %d | weight: %2d) -> ", edges[i].begin, edges[i].end, edges[i].weight);
            TotalWeight += edges[i].weight;
        }
    }

    return TotalWeight;
}

int GraghDemo(){

    // 邻接矩阵初始化图
    AdjMTGraghGragh AdjMTG;
    CreateAdjMT_2(&AdjMTG);

    // 邻接矩阵深度优先遍历
    printf("邻接矩阵深度优先遍历\n");
    AdjMTDFSTraverse(AdjMTG);
    printf("\n");

    // 邻接表初始化图
    // AdjListGragh AdjList;
    // CreateAdjList(&AdjList);

    // 利用邻接矩阵构建邻接表
    AdjListGragh AdjList;
    CreateALGraph(AdjMTG, &AdjList);

    printf("邻接表深度优先遍历\n");
    AdjListDFSTraverse(AdjList);
    printf("\n");

    // 邻接矩阵广度优先遍历
    printf("邻接矩阵广度优先遍历\n");
    AdjMTBFSTraverse(AdjMTG);
    printf("\n");

    // 邻接表广度优先遍历
    printf("邻接表广度优先遍历\n");
    AdjListBFSTraverse(AdjList);
    printf("\n");


    /*Prim算法生成最小生成树 - 邻接矩阵实现*/
    printf("Prim算法生成最小生成树 - 邻接矩阵实现\n");
    AdjMTGraghGragh AdjMTG2;
    CreateAdjMT_Weight(&AdjMTG2);

    // AdjMTDFSTraverse(AdjMTG2);
    int TotalWeight = 0;
    TotalWeight = AdjMT_MibuSpanTree_Prim(AdjMTG2);
    printf("end\n");
    printf("Prim Algorithm Total weight is %d", TotalWeight);
    printf("\n");

    /*Kruskal算法生成最小生成树 - 邻接矩阵实现*/
    printf("Kruskal算法生成最小生成树 - 邻接矩阵实现\n");
    TotalWeight = AdjMT_MiniSpanTree_Kruskal(AdjMTG2);
    printf("end\n");
    printf("Kruskal Algorithm Total weight is %d", TotalWeight);
    printf("\n");


    return 0;
}