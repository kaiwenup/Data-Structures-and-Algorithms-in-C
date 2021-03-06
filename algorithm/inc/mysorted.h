#ifndef MYSORTED_H
#define MYSORTED_H

#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"  
#include <unistd.h> 

#include <math.h>
#include "time.h"

#include "../../data_structure/inc/ComFun.h"

#define ARRAY_SIZE 6 // 数组长度
#define SRAND_BUTTON 1

//桶排序
#define NBUCKET 10  // Number of buckets
#define INTERVAL 10  // Each bucket capacity

typedef struct BucketNode {
    int data;
    struct BucketNode *next;
} BucketNode, *PtrBucketNode;

void BubbleSort(int* array, int n);
void InsertSort(int* array, int n);
void SelectionSort(int* array, int n);
void ShellSort(int* array, int n);
void QuickSort(int* array, int n);
void MergeSortRecursive(int arr[], int reg[], int start, int end);
void MergeSortRe(int arr[],const int len);
int Paritition1(int *array, int start, int end);
void QuickSortRecursive(int* array, int start,int end);
void QuickSortRe(int array[], int len);
// 桶排序
void BucketSort(int array[], int len);
PtrBucketNode InsertSort_SinglyLinkedList(PtrBucketNode list);
void printBuckets(PtrBucketNode list);
int getBucketIndex(int value);

int partition(int array[], int left, int right);
int randomPartition(int* array, int l, int r);
int QuickSelect(int array[], int left, int right, int index);
int FindKthlargest(int array[], int len, int k);
int BsearchRecursive(int array[], int left, int right, int val);
int Bsearch(int array[], int len, int val);

void mysorted_demo();



#endif