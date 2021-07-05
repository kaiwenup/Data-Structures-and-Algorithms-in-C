#include "../inc/myheap.h"



int PriorityQueueIsFull(PriorityQueue H){
    
    return H->Size == H->Capacity;
}

int PriorityQueueIsEmpty(PriorityQueue H){
    return H->Size == 0;
}
PriorityQueue PriorityQueueInitialize(int MaxElement){

    PriorityQueue H;

    if(MaxElement < MinPQSize){
        printf("Priority queue size is too small");
    }

    H = (PriorityQueue)malloc(sizeof(HeapStruct));

    if(H == NULL){
        printf("Out of space!!!");
    }

    H->Element = malloc( (MaxElement+1) * sizeof(HeapStruct) );

    if(H->Element == NULL){
        printf("Out of space!!!");
    }

    H->Capacity = MaxElement;
    H->Size = 0;
    H->Element[0] = MinData;
    
    return H;
}

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

HeapElementType PriorityQueueFindMin(PriorityQueue H){

    if(! PriorityQueueIsEmpty(H)){
        return H->Element[1];
    }

    Error( "Priority Queue is Empty" );
    return H->Element[0];
}

void PriorityQueueDestroy(PriorityQueue H){

    free(H->Element);
    free(H);
}

void PriorityQueueMakeEmpty(PriorityQueue H){
    H->Size = 0;
}

void PriorityQueueDemo(){
    PriorityQueue H;
    int i, j;

    H = PriorityQueueInitialize(MaxSize);

    int AddData[4] = {3,5,6,2};
    for( i=0, j=MaxSize/2; i<MaxSize; i++, j=( j+71)%MaxSize ){
        printf("input [%d] data is %d\n", i,  j);
        PriorityQueueInsert( j, H );
    }
    // for(i = 0; i < 4; i++)
        // PriorityQueueInsert( AddData[i], H );
        

    int mindata ;

    for(i = 0; i < MaxSize; i++){
        mindata = PriorityQueueDeleteMin(H);
        printf("[%d]is %d\n",i , mindata);
    }


    PriorityQueueDestroy(H);



}