#include"../inc/exptree.h"


// itoa不是标准函数，有些编译器可能没有，自定义itoa函数
// 或者使用这个函数，将整型转化为字符串snprintf (aa, sizeof(aa), "%d",10);(aa 的定义 char[5],切记不要定义成char* aa)
char *my_itoa(int num, char *str)
{
        if(str == NULL)
        {
                return NULL;
        }
        sprintf(str, "%d", num);
        return str;
}

// 表达树(expression tree)
void InitExpTree(ExpTree *root){

    *root = NULL;

}


void ExpTreeInsert(ExpTree *tree, char* value){

	if( *tree == NULL )
	{
		if( ! ((*tree) = (ExpTree)malloc(sizeof(ExpTNode))) )
		{
			printf("insert malloc error\n");
			exit(-1);
		}
		// (*tree)->data = value;  // 错误写法
        strcpy((*tree)->data,value);
		(*tree)->lchild = (*tree)->rchild = NULL;
	}
}


Status InitExpStack(ExpLinkStack *S){
    S->top = (StackPtr)malloc(sizeof(ExpStackNode));

    if(!S->top)
        return ERROR;

    S->top = NULL;
    S->count = 0;

    return OK;
}



Status ExpPush(ExpLinkStack *S, ExpElemType elem){
    StackPtr newNode = (StackPtr)malloc(sizeof(ExpStackNode));

    newNode->TreeNode = elem;
    newNode->next = S->top;
    S->top = newNode;
    S->count++;

    return OK;


}

ExpElemType ExpPop(ExpLinkStack *S){
    StackPtr delNode;
    if(IsExpEmpty(*S))
        return NULL;
    
    ExpElemType elem = S->top->TreeNode;
    delNode = S->top;
    S->top = S->top->next;
    free(delNode);

    S->count--;

    return elem;
}


Status IsExpEmpty(ExpLinkStack S){
    if(S.count == 0)  // 注意此处的写法和链表写法的区别
        return TRUE;
    else
        return FALSE;
}
void InOrderExpTreeTraverse(ExpTree *tree){
    if(!(*tree))
		return;
    int tmp;
    char str[4] = "0"; // 不能用指针来代替,切记***
	InOrderExpTreeTraverse(&(*tree)->lchild); /* 中序遍历左子树 */
	// printf("%d ",atoi((*tree)->data));/* 显示结点数据，可以更改为其它对结点操作 */
    InOrderExpTreeTraverse(&(*tree)->rchild); /* 最后中序遍历右子树 */

    switch (*((*tree)->data))
    {
    case '+':
        tmp = atoi((*tree)->lchild->data) + atoi((*tree)->rchild->data); // 字符串转成整型计算
        // my_itoa(tmp, str);  // 整型转成字符串
        snprintf (str, sizeof(str), "%d",tmp);
        // (*tree)->data = str;  // 错误写法
        strcpy((*tree)->data,str);
        break;
    case '-':
        tmp = atoi((*tree)->lchild->data) - atoi((*tree)->rchild->data); // 字符串转成整型计算
        // my_itoa(tmp, str);  // 整型转成字符串
        snprintf (str, sizeof(str), "%d",tmp);
        strcpy((*tree)->data,str);
        break;
    case '*':
        tmp = atoi((*tree)->lchild->data) * atoi((*tree)->rchild->data); // 字符串转成整型计算
        // my_itoa(tmp, str);  // 整型转成字符串
        snprintf (str, sizeof(str), "%d",tmp);
        strcpy((*tree)->data,str);
        break;
    case '/':
        tmp = atoi((*tree)->lchild->data) / atoi((*tree)->rchild->data); // 字符串转成整型计算
        // my_itoa(tmp, str);  // 整型转成字符串
        snprintf (str, sizeof(str), "%d",tmp);
        strcpy((*tree)->data,str);
        break;
    }

    
}

// 《数据结构与算法分析-C语言描述》4.2.2
void ExpressionTree(){

    int i;
    char* leaves[] = {"1", "2", "+", "3", "4", "5", "+", "*", "*"};
    // 构造二叉树
    ExpTree exptree[ExpSIZE];
    ExpTree exp_tree_final;

    // 构造堆栈
    ExpLinkStack expstack;
    InitExpStack(&expstack); // 初始化堆栈

    for(i = 0; i < ExpSIZE; i++){
        InitExpTree(&exptree[i]);  
        /** 在这里用到了二级指针，被一级指针指向的实体是ExpTNode，然后*ExpTree指向ExpTNode这个实体
         *  
        */
        ExpTreeInsert(&exptree[i], leaves[i]);

        if(isNumber(exptree[i]->data)){
            ExpPush(&expstack, exptree[i]);
        }
        else{
            exptree[i]->rchild = ExpPop(&expstack);
            exptree[i]->lchild = ExpPop(&expstack);
            ExpPush(&expstack, exptree[i]);
        }
        
    }
    
    
    exp_tree_final = ExpPop(&expstack);
    InOrderExpTreeTraverse(&exp_tree_final);
    
    printf("%d\n", atoi(exp_tree_final->data));

}