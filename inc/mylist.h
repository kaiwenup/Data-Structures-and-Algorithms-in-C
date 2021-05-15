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
}List_Node;

typedef struct List_Node *Linklist;



Status visit(ElemType c);
Status InitList(Linklist *L);
Status ListEmpty(Linklist L);
Status ClearList(Linklist *L);
Status ListLength(Linklist L);
Status GetElem(Linklist L, int i, ElemType *e);
Status LocateElem(Linklist L, ElemType e);
Status ListInsert(Linklist *L, int i, ElemType e);
Status ListDelete(Linklist *L, int i, ElemType *e);
Status ListTraverse(Linklist L);
void CreateListHead(Linklist *L, int n);
void CreateListTail(Linklist *L, int n);
void CreateCircularListTail(Linklist *L, int n, int k);
void CreateSortedListTail(Linklist *L, int n);
Linklist* mergeTwoLists(Linklist* head1, Linklist* head2);
Linklist* mergeTwoLists_Iteration(Linklist* head1, Linklist* head2);
Linklist* mergeTwoLists_It(Linklist* head1, Linklist* head2);
Linklist* detectCycle(Linklist* head);
Linklist* reverseList(Linklist* L);
Linklist* reverseList_Iteration(Linklist* head);
Linklist* reverseList_It(Linklist* head);
Linklist* removeNthFromEnd(Linklist* head, int n);
Linklist* middleNode(Linklist* head);
void single_list_demo();



#endif