#ifndef EXPTREE_H
#define EXPTREE_H

#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include <stdlib.h>
#include <stdbool.h> 
#include <unistd.h> 

#include "../../data_structure/inc/mystack.h"

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE 0
#define ExpSIZE 9 /* 存储空间初始分配量 */

typedef struct treenode{
    char data[4];  // 切记不要用指针定义：char *data
    struct treenode *lchild;
    struct treenode *rchild;
    
} ExpTNode,  *ExpTree;


typedef struct ExpStackNode{
    ExpTree TreeNode;
    struct ExpStackNode *next;
} ExpStackNode, *StackPtr;

typedef struct{
    StackPtr top;
    int count;
}ExpLinkStack, *ExpLinkStackPtr;

typedef int Status;
typedef ExpTree ExpElemType;


char *my_itoa(int num, char *str);
// 构造栈
Status InitExpStack(ExpLinkStackPtr S);
void CreateExpStack(ExpLinkStackPtr S, int val);
Status ClearExpStack(ExpLinkStackPtr S);
ExpElemType GetExpTop(ExpLinkStack S);
Status TraverseExpStack(ExpLinkStack S);
Status IsExpEmpty(ExpLinkStack S);
int GetExpLength(ExpLinkStack S);
Status ExpPush(ExpLinkStackPtr S, ExpElemType elem);
ExpElemType ExpPop(ExpLinkStackPtr S);
Status IsExpEmpty(ExpLinkStack S);

// 构造二叉树
void InitExpTree(ExpTree *root);
void ExpTreeInsert(ExpTree *tree, char* value);
void InOrderExpTreeTraverse(ExpTree *tree);


// 表达式数 (expression tree)
void ExpressionTree();
#endif