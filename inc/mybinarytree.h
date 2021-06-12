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

typedef int TElemType;
typedef int NodeType;

typedef struct Treenode{
    NodeType data;
    struct Treenode *lchild;
    struct Treenode *rchild;
    
} BiTNode, *SearchTree, *Position;


SearchTree SearchTreeMakeEmpty(SearchTree T);
Position SearchTreeFind(NodeType val, SearchTree T);
Position SearchTreeFinMin(SearchTree T);
Position SearchTreeFindMax(SearchTree T);
SearchTree SearchTreeInsert(NodeType val, SearchTree T);
SearchTree SearchTreeDelete(NodeType val, SearchTree T);
void DestroySearchTree(SearchTree T);
void InOrderTraverse(SearchTree root);

void visualization(SearchTree tree, char *filename);
void write2dot(SearchTree tree, FILE *fw);

void mybinarytree_demo();
void MySearchTreeDemo();

#endif