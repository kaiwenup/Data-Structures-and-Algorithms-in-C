#ifndef MYLIST_H
#define MTLIST_H

#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"  
#include <unistd.h> 

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20          /* 存储空间初始分配量 */

typedef int Status;
typedef int ElemType;

typedef struct List_Node{
    ElemType data;
    struct List_Node *next;
}List_Node, *Linklist;




Status visit(ElemType c);
Linklist InitList();
Status ListEmpty(Linklist L);
Status ClearList(Linklist L);
Status ListLength(Linklist L);
Linklist ListFindX(Linklist L, ElemType X);
Status GetElem(Linklist L, int i, ElemType *e);
Status LocateElem(Linklist L, ElemType e);
Status ListInsert(Linklist L, int i, ElemType e);
Status ListDelete(Linklist L, int i, ElemType *e);
Linklist FindPrevious(Linklist L, ElemType X);
Status ListDeleteX(Linklist L, ElemType X);
Status ListTraverse(Linklist L);
Linklist CreateListHead(int n);
Linklist CreateListTail(int n);
Linklist CreateCircularListTail(int n, int k);
Linklist CreateSortedListTail(int n);
Linklist mergeTwoLists(Linklist head1, Linklist head2);
Linklist mergeTwoLists_Iteration(Linklist head1, Linklist head2);
Linklist mergeTwoLists_It(Linklist head1, Linklist head2);
Linklist detectCycle(Linklist head);
Linklist reverseList(Linklist L);
Linklist reverseList_Iteration(Linklist head);
Linklist reverseList_It(Linklist head);
Linklist removeNthFromEnd(Linklist head, int n);
Linklist middleNode(Linklist head);
void single_list_demo();



#endif