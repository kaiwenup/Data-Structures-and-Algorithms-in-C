#ifndef MYSORTED_H
#define MYSORTED_H

#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"  
#include <unistd.h> 

#include "math.h"  
#include "time.h"


#define ARRAY_SIZE 15 // 数组长度
#define SRAND_BUTTON 0

void BubbleSort(int* array, int n);
void InsertSort(int* array, int n);
void SelectionSort(int* array, int n);
void ShellSort(int* array, int n);
void QuickSort(int* array, int n);
void MergeSortRecursive(int arr[], int reg[], int start, int end);
void MergeSortRe(int arr[],const int len);
void QuickSortRecursive(int* array, int start,int end);
void QuickSortRe(int array[], int len);
int partition(int array[], int left, int right);
int randomPartition(int* array, int l, int r);
int QuickSelect(int array[], int left, int right, int index);
int FindKthlargest(int array[], int len, int k);

void mysorted_demo();



#endif