#include "../inc/base.h"

/**求最大子序列的和
 * 分治算法
 * 时间复杂度：O(NlogN)**/
static int Max3( int A, int B, int C )
{
    return A > B ? A > C ? A : C : B > C ? B : C;
}

static int MaxSubSum( const int A[], int Left, int Right )
{
            int MaxLeftSum, MaxRightSum;
            int MaxLeftBorderSum, MaxRightBorderSum;
            int LeftBorderSum, RightBorderSum;
            int Center, i;

/* 1*/      if( Left == Right )  /* Base case */
            // 为什么作者一定要写成这种形式，而不是直接return A[Left]
/* 2*/      //    if( A[ Left ] > 0 )   
/* 3*/      //        return A[ Left ];
            //    else
/* 4*/      //        return 0;
                return A[Left];

/* 5*/      Center = ( Left + Right ) / 2;
/* 6*/      MaxLeftSum = MaxSubSum( A, Left, Center );
/* 7*/      MaxRightSum = MaxSubSum( A, Center + 1, Right );

/* 8*/      MaxLeftBorderSum = 0; LeftBorderSum = 0;
/* 9*/      for( i = Center; i >= Left; i-- )
            {
/*10*/          LeftBorderSum += A[ i ];
/*11*/          if( LeftBorderSum > MaxLeftBorderSum )
/*12*/              MaxLeftBorderSum = LeftBorderSum;
            }

/*13*/      MaxRightBorderSum = 0; RightBorderSum = 0;
/*14*/      for( i = Center + 1; i <= Right; i++ )
            {
/*15*/          RightBorderSum += A[ i ];
/*16*/          if( RightBorderSum > MaxRightBorderSum )
/*17*/              MaxRightBorderSum = RightBorderSum;
            }

/*18*/      return Max3( MaxLeftSum, MaxRightSum,
/*19*/                          MaxLeftBorderSum + MaxRightBorderSum );

}

int MaxSubsequenceSum(const int A[], int N )
{
    return MaxSubSum( A, 0, N - 1 );
}

/**对分查找
 * 时间复杂度：log(n)**/
int BinarySearch(const int A[], int N, int X){
    
    int left = 0, right = N-1, mid;

    while(left <= right){

        mid =(left+right)/2;
        if(A[mid] < X){
            left = mid + 1;
            
        }
        else if(A[mid] > X){
            right = mid - 1;
        }
        else
            return mid;
    }

    return -1;
}

void base_demo(){

    int arr[8] = {4, -3, 5, -2, -1, 2, 6, -2};

    int max = MaxSubsequenceSum(arr, 8);

    printf("max value is %d\n", max);

    QuickSortRe(arr, 8);
    // BubbleSort(arr, 8);
    ArrayTraverse(arr, 8);

    int find_val = BinarySearch(arr, 8, 6);
    printf("index of value is %d\n", find_val);



}

