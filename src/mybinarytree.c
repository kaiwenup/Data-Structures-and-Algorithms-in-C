#include "../inc/mybinarytree.h"



void InitBiTree(BiTree *root){

    *root = NULL;
}



/* 初始条件: 二叉树T存在。操作结果: 销毁二叉树T */
void DestroyBitree(BiTree *root){

    if(*root){
        if((*root)->lchild)
            DestroyBitree(&(*root)->lchild);
        if((*root)->rchild)
            DestroyBitree(&(*root)->rchild);
        
    free(*root);

        // *root = NULL;         

    }
}

/* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
int BiTreeDepth(BiTree root){
    int i = 0, j = 0;
    if(!root)
        return 0;
    
    if(root->lchild)
        i = BiTreeDepth(root->lchild);
    else
        i = 0;
    
    if(root->rchild)
        j = BiTreeDepth(root->rchild);
    else
        j = 0;

    
    return i > j ? i+1 : j+1;

}


/* 初始条件: 二叉树T存在 */
/* 操作结果: 若T为空二叉树,则返回 1,否则 0 */
int BiTreeEmpty(BiTree root){

    if(root)
        return 0;
    else
        return 1;
}

void BiTreeInsert(BiTree *tree, int value)
{
	if( *tree == NULL )
	{
		if( ! ((*tree) = (BiTree)malloc(sizeof(BiTree))) )
		{
			printf("insert malloc error\n");
			exit(-1);
		}
		(*tree)->data = value;
		(*tree)->lchild = (*tree)->rchild = NULL;
	}
	else
	{
		if( value < (*tree)->data )
			BiTreeInsert(&((*tree)->lchild), value);
		else
			BiTreeInsert(&((*tree)->rchild), value);
	}
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 中序递归遍历T */
void InOrderTraverse(BiTree root){ 
	if(!root)
		return;
	InOrderTraverse(root->lchild); /* 中序遍历左子树 */
	printf("%d ",root->data);/* 显示结点数据，可以更改为其它对结点操作 */
	InOrderTraverse(root->rchild); /* 最后中序遍历右子树 */
}

/* 二叉树可视化 */
void visualization(BiTree tree, char* filename){
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


void write2dot(BiTree tree, FILE* fw){
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

void mybinarytree_demo(){
    
    int arr[4] = {5,4,6,2};
    int i;

    int arr1[Bi_ARRAY_SIZE];
    for(i = 0; i < Bi_ARRAY_SIZE; i++){
        arr1[i] = GenRandomNum(100);
    }

    BiTree root;
    InitBiTree(&root); // 很重要，一定要初始化，防止 段错误
    for(i = 0; i < Bi_ARRAY_SIZE; i++){
        BiTreeInsert(&root, arr1[i]);
    }
    
    visualization(root, "tree.dot");
    InOrderTraverse(root);
    printf("\n");

    DestroyBitree(&root);


}
