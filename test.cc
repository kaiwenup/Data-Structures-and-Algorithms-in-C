#include <iostream>
#include "inc/single_list.h"
#include "inc/mystack.h"
#include "inc/myLinkQueue.h"
#include "inc/ComFun.h"
#include "inc/mysorted.h"

using namespace std;


#define ARRAY_SIZE 6

int main() 
{
    /******单链表相关算法******/
    // single_list_demo();

    /******堆栈相关算法******/
    // mystack_demo();

    /******队列相关算法******/
    // myLinkQueue_demo();

    int array[ARRAY_SIZE];

    GenRandomArray(array, ARRAY_SIZE);
    ArrayTraverse(array,ARRAY_SIZE);
    // BubbleSort(array, 10);
    InsertSort(array, ARRAY_SIZE);
    ArrayTraverse(array,ARRAY_SIZE);
 
    return 0;
}
