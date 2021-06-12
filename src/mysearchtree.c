#include "../inc/mysearchtree.h"


SearchTree SearchTreeMakeEmpty(SearchTree T){
	if(T != NULL){
		SearchTreeMakeEmpty(T->lchild);
		SearchTreeMakeEmpty(T->rchild);
		free(T);
	}

	return NULL;
}

// 二叉查找树 Find操作
Position SearchTreeFind(NodeType val, SearchTree T){

	if(T == NULL)
		return NULL;
	else if(val < T->data)
		return SearchTreeFind(val, T->lchild);
	else if(val > T->data)
		return SearchTreeFind(val, T->rchild);
	else
		return T;
}

// 二叉查找树 FindMin的递归实现
Position SearchTreeFinMin(SearchTree T){
	if(T == NULL)
		return NULL;
	else if(T->lchild == NULL)
		return T;
	else
		return SearchTreeFinMin(T->lchild);
}

// 二叉查找树 FindMax的递归实现
Position SearchTreeFindMax(SearchTree T){
	if(T == NULL)
		return NULL;
	else if(T->rchild == NULL)
		return T;
	else 
		return SearchTreeFindMax(T->rchild);
}

// // 二叉查找树 FindMax的非递归实现
// Position FindMax(SearchTree T){
// 	while(T->rchild != NULL)
// 		T = T->rchild;
	
// 	return T;
// }

SearchTree SearchTreeInsert(NodeType val, SearchTree T){
	if(T == NULL){
		T = malloc(sizeof(BiTNode));
		if(T == NULL){
			printf("Out of space!!!");  // 出错处理
			exit(-1);
		}
		T->data = val;
		T->lchild = T->rchild = NULL;
	}
	else if(val < T->data){
		T->lchild = SearchTreeInsert(val, T->lchild);
	}
	else if(val > T->data){
		T->rchild = SearchTreeInsert(val, T->rchild);
	}


	return T;
	
}



// 注意两种插入写法上的区别
// void BiTreeInsert(BiTree *tree, int value)
// {
// 	if( *tree == NULL )
// 	{
// 		if( ! ((*tree) = (BiTree)malloc(sizeof(BiTree))) )
// 		{
// 			printf("insert malloc error\n");
// 			exit(-1);
// 		}
// 		(*tree)->data = value;
// 		(*tree)->lchild = (*tree)->rchild = NULL;
// 	}
// 	else
// 	{
// 		if( value < (*tree)->data )
// 			BiTreeInsert(&((*tree)->lchild), value);
// 		else
// 			BiTreeInsert(&((*tree)->rchild), value);
// 	}
// }


SearchTree SearchTreeDelete(NodeType val, SearchTree T){
	
	Position TmpCell;
	
	if(T == NULL)
		printf("Elment not found!!!\n");
	else if(val < T->data)
		T->lchild = SearchTreeDelete(val, T->lchild);
	else if(val > T->data)
		T->rchild = SearchTreeDelete(val, T->rchild);
	else{
		
		// 当要删除的节点有两个子节点时
		if(T->lchild && T->rchild){
			TmpCell = SearchTreeFinMin(T->rchild);
			T->data = TmpCell->data;
			T->rchild = SearchTreeDelete(TmpCell->data, T->rchild);
			// free(TmpCell);

		}
		// 当要删除的节点有只有一个子节点时
		else{
			TmpCell = T;
			if(T->lchild == NULL){
				T = T->rchild;
			}
			else if(T->rchild == NULL){
				T = T->lchild;
			}

			free(TmpCell);
		}


	}

	return T;
}



/* 初始条件: 二叉树T存在 */
/* 操作结果: 中序递归遍历T */
void InOrderTraverse(SearchTree T){ 
	if(!T)
		return;
	InOrderTraverse(T->lchild); /* 中序遍历左子树 */
	printf("%d ",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	InOrderTraverse(T->rchild); /* 最后中序遍历右子树 */
}


void DestroySearchTree(SearchTree T){
	
	if(T == NULL)
		return;

	if(T){
		if(T->lchild)
			DestroySearchTree(T->lchild);
		if(T->rchild)
			DestroySearchTree(T->rchild);
	}

	free(T);
}

/* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
int SearchTreeDepth(SearchTree T){
	int i = 0, j = 0;
	
	if(T == 0)
		return 0;

	if(T->lchild)
		i = SearchTreeDepth(T->lchild);
	else	
		i = 0;

	if(T->rchild)
		j = SearchTreeDepth(T->rchild);
	else
		j = 0;
	
	return i > j ? i+1 : j+1;
}

/* 二叉树可视化 
   需要在VScode上安装插件-Graphviz (dot) language support for Visual Studio Code*/
void visualization(SearchTree tree, char* filename){
	FILE *fw;
	if( NULL == (fw = fopen(filename, "w")) )
	{
		printf("open file error");
		exit(0);
	}
	fprintf(fw, "digraph\n{\nnode [shape = Mrecord, style = filled, color = black, fontcolor = white];\n");
	write2dot(tree, fw);
	fprintf(fw, "}");
	fclose(fw);
}


void write2dot(SearchTree tree, FILE* fw){
	if(tree == NULL)
		return ;
	else
	{
		fprintf(fw, "%d [label = \"<f0> | <f1> %d | <f2> \", color = black, fontcolor = white, style = filled];\n", tree->data, tree->data);
	}
	if(tree->lchild)
	{
		fprintf(fw, "%d [label = \"<f0> | <f1> %d | <f2> \", color = black, fontcolor = white, style = filled];\n", tree->lchild->data, tree->lchild->data);
		fprintf(fw, "%d:f0:sw -> %d:f1;\n", tree->data, tree->lchild->data);
	}
	if(tree->rchild)
	{
		fprintf(fw, "%d [label = \"<f0> | <f1> %d | <f2> \", color = black, fontcolor = white, style = filled];\n", tree->rchild->data, tree->rchild->data);
		fprintf(fw, "%d:f2:se -> %d:f1;\n", tree->data, tree->rchild->data);
	}
	write2dot(tree->lchild, fw);
	write2dot(tree->rchild, fw);
}


void MySearchTreeDemo(){
	int i;
	int arr[] = {5, 4, 67, 66, 68};
	// SearchTree stree ; // 这么定义会导致段错误
	SearchTree stree = NULL;
	SearchTree tmpstree = NULL;
	int nums = sizeof(arr)/sizeof(arr[0]);

	// // 插入节点
	// for(i = 0; i < nums; i++){
	// 	stree = SearchTreeInsert(arr[i], stree);
	// 	SearchTreeInsert(arr[i], stree);  // 会导致段错误
	// }
	int arr1[5];
	int arr1_size = sizeof(arr1)/sizeof(arr1[0]);
    for(i = 0; i < arr1_size; i++){
        arr1[i] = GenRandomNum(10000);
		stree = SearchTreeInsert(arr1[i], stree);
    }

	int depth = 0;
	depth = SearchTreeDepth(stree);
	printf("search tree depth is %d\n", depth);
	// 删除节点
	SearchTreeDelete(67, stree);

	// 二叉树可视化
	visualization(stree, "searchtree.dot");

	// 寻找二叉树最大值
	tmpstree = SearchTreeFindMax(stree);
	printf("max value is: %d\n", tmpstree->data);
	
	// 中序遍历二叉树
	InOrderTraverse(stree);
	printf("\n");

	// 销毁二叉树
	DestroySearchTree(stree);
	visualization(stree, "searchtree1.dot");
}