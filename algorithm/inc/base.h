#ifndef BASE_H
#define BASE_H

#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"  
#include <unistd.h> 

#include "math.h"  
#include "time.h"

#include "../inc/mysorted.h"
#include "../../data_structure/inc/ComFun.h"

// 最大子序列和
int MaxSubsequenceSum(const int A[], int N );
static int MaxSubSum( const int A[], int Left, int Right );
static int Max3( int A, int B, int C );

// 对分查找
int BinarySearch(const int A[], int N, int X);

void base_demo();

#endif