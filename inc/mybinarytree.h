#ifndef MYBINARYTREE_H
#define MYBINARYTREE_H

#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"  
#include <unistd.h> 

#include "math.h"  
#include "time.h"

#include "../inc/ComFun.h"

#define MAX_TREE_NODES (1 << 8)
#define Bi_ARRAY_SIZE 10

typedef struct _treenode{
    int data;
    struct _treenode *lchild;
    struct _treenode *rchild;
    
} BiTNode,  *BiTree;

typedef int TElemType;

void InitBiTree(BiTree *root);
void BiTreeInsert(BiTree *tree, int value);
void DestroyBitree(BiTree *root);
int BiTreeEmpty(BiTree root);
void InOrderTraverse(BiTree root);
void mybinarytree_demo();

void visualization(BiTree tree, char *filename);
void write2dot(BiTree tree, FILE *fw);


#endif