#include "../inc/myheap.h"


// 检查二叉堆元素个数是否到达最大值
int PriorityQueueIsFull(PriorityQueue H){
    
    return H->Size == H->Capacity;
}

// 检查二叉堆元素个数是否为空
int PriorityQueueIsEmpty(PriorityQueue H){
    return H->Size == 0;
}

// 初始化MaxElement个节点的二叉堆
PriorityQueue PriorityQueueInitialize(int MaxElement){

    PriorityQueue H;

    if(MaxElement < MinPQSize){
        printf("Priority queue size is too small");
    }

    H = (PriorityQueue)malloc(sizeof(HeapStruct));

    if(H == NULL){
        printf("Out of space!!!");
    }

    // H->Element = malloc( (MaxElement+1) * sizeof(HeapStruct) ); // 错误写法
    H->Element = malloc( (MaxElement+1) * sizeof(HeapElementType) );

    if(H->Element == NULL){
        printf("Out of space!!!");
    }

    H->Capacity = MaxElement;
    H->Size = 0;
    H->Element[0] = MinData;
    
    return H;
}

// 将一个元素插入到二叉堆
// 上滤(percolate up)
void PriorityQueueInsert(HeapElementType num, PriorityQueue H){

    int i;

    if(PriorityQueueIsFull(H)){
        printf("Priority queue is full");
        return;
    }

    for( i = ++H->Size; H->Element[i/2] > num; i /= 2){ 
        H->Element[i] = H->Element[i/2];
    }
        
    

    H->Element[i] = num;


}

// 删除最小元并返回其数值
// 下滤(percolate down)
HeapElementType PriorityQueueDeleteMin(PriorityQueue H){
    int i, Child;
    HeapElementType MinElement, LastElement;

    if(PriorityQueueIsEmpty(H)){
        printf("Priority queue is empty\n");
        return H->Element[0]; 
    }

    MinElement = H->Element[1];
    LastElement = H->Element[H->Size--];

    for(i = 1; i * 2 <= H->Size; i = Child){

        Child = i *2;
        if(Child != H->Size && H->Element[Child+1] <= H->Element[Child]){
            Child++;
        }

        // percolate one level
        if(LastElement > H->Element[Child]){
            H->Element[i] = H->Element[Child];
        }
        else
            break;

        
    }

    H->Element[i] = LastElement;
    return MinElement;
    
}

// 返回二叉堆最小值
HeapElementType PriorityQueueFindMin(PriorityQueue H){

    if(! PriorityQueueIsEmpty(H)){
        return H->Element[1];
    }

    Error( "Priority Queue is Empty" );
    return H->Element[0];
}

// 销毁整个二叉堆
void PriorityQueueDestroy(PriorityQueue H){

    free(H->Element);
    free(H);
}

// 二叉堆元素个数清零
void PriorityQueueMakeEmpty(PriorityQueue H){
    H->Size = 0;
}

// 二叉堆相关函数使用例程
void PriorityQueueDemo(){
    PriorityQueue H;
    int i, j;

    H = PriorityQueueInitialize(MaxSize);

    for( i=0, j=MaxSize/2; i<MaxSize; i++, j=( j+71)%MaxSize ){
        printf("input [%d] data is %d\n", i,  j);
        PriorityQueueInsert( j, H );
    }
        

    int mindata ;

    for(i = 0; i < MaxSize; i++){
        mindata = PriorityQueueDeleteMin(H);
        printf("[%d]is %d\n",i , mindata);
    }


    PriorityQueueDestroy(H);



}