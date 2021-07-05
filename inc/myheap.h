#ifndef MYHEAP_H
#define MYHEAP_H

#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"  
#include <unistd.h> 
#include "math.h"  
#include "time.h"

#include "fatal.h"

#define MinPQSize (10)
#define MinData (-32767)
#define MaxSize (1000)
/**堆的相关算法**/

typedef int HeapElementType;


typedef struct HeapStruct
{
    int Capacity;
    int Size;
    HeapElementType *Element;
} HeapStruct, *PriorityQueue;

int PriorityQueueIsFull(PriorityQueue H);
int PriorityQueueIsEmpty(PriorityQueue H);
PriorityQueue PriorityQueueInitialize(int MaxElement);
void PriorityQueueInsert(HeapElementType num, PriorityQueue H);
HeapElementType PriorityQueueDeleteMin(PriorityQueue H);
HeapElementType PriorityQueueFindMin(PriorityQueue H);
void PriorityQueueDestroy(PriorityQueue H);
void PriorityQueueMakeEmpty(PriorityQueue H);


void PriorityQueueDemo();

#endif