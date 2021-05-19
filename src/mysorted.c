#include "../inc/mysorted.h"
#include "../inc/ComFun.h"

/**
 * 常见的排序算法：
 * 参考教程：
 * （1）极客时间-数据结构与算法之美
 * （2）菜鸟教程-C排序算法 https://www.runoob.com/cprogramming/c-sort-algorithm.html
 * （3）Wikipedia
 * **/

/**常用排序算法：快速排序**/

/**冒泡排序
 * 最好情况时间复杂度：O(n)
 * 最坏情况时间复杂度：O(n^2)
 * 平均时间复杂度：O(n^2)
 * 原地排序法
 * 稳定的排序算法
 * **/
void BubbleSort(int* array, int n){

    if(n <= 1) return;
    int flag = 0;
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n-1-i; j++){
            if(array[j] > array[j+1]){
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
                flag = 1;
            }
        }

        if(!flag) return;
    }
}

/**插入排序
* 最好情况时间复杂度：O(n)
* 最坏情况时间复杂度：O(n^2)
* 平均情况时间复杂度：O(n^2)
* 原地排序算法
* 稳定排序算法
* **/
void InsertSort(int* array, int n){

    if(n <= 1) return;
    int i;
    for(i = 1; i < n; ++i){
        int val = array[i];
        int j = i-1;
        for(; j >= 0; --j){
            if(array[j] > val){
                array[j+1] = array[j];  //移动数据
            }else
                break;
        }

        array[j+1] = val;  //插入数据  
    }
}

/**选择排序
* 最好情况时间复杂度：O(n^2)
* 最坏情况时间复杂度：O(n^2)
* 平均情况时间复杂度：O(n^2)
* 原地排序算法
* 不稳定排序算法
* **/
void SelectionSort(int* array, int n){

    if(n <= 1) return;
    int i;
    for(i = 0; i < n-1; i++){
        int min = i;
        int j = i+1;
        for(;j < n; j++){
            if(array[i] > array[j]){
                min = j;
            }
        }

        if(min != i){
            int temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }

    }


}

/**希尔排序
 * **/
void ShellSort(int* array, int n){

}

/**归并排序 递归法
* 最好情况时间复杂度：O(nlog(n))
* 最坏情况时间复杂度：O(nlog(n))
* 平均情况时间复杂度：O(nlog(n))
* 非原地排序算法
* 稳定排序算法
* **/
void MergeSortRecursive(int arr[], int reg[], int start, int end){
    if(start >= end)
        return;
    
    int len = end - start,
        mid = (len>>1) + start; // len>>1 = len/2
    int start1 = start, end1 = mid;
    int start2 = mid+1, end2 = end;

    MergeSortRecursive(arr, reg, start1, end1);
    MergeSortRecursive(arr, reg, start2, end2);

    int k = start;

    while(start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while(start1 <= end1)
        reg[k++] = arr[start1++];
    while(start2 <= end2)
        reg[k++] = arr[start2++];

    for(k = start; k <= end; k++)
        arr[k] = reg[k];



}

void MergeSortRe(int arr[],const int len){
    int  reg[len];
    MergeSortRecursive(arr, reg, 0, len-1);
}

/**快速排序
 * **/
void QuickSort(int* array, int n){

}

/**快速排序 迭代法
* 最好情况时间复杂度：O(nlog(n))
* 最坏情况时间复杂度：O(n^2)
* 平均情况时间复杂度：O(nlog(n))
* 原地排序算法
* 非稳定排序算法
* **/
void QuickSortRecursive(int* array, int start,int end){
    if(start >= end)
        return;
    
    int mid = array[end];
    int left = start,
        right = end-1;
    
    while(left < right){
        while(array[left] < mid && left < right)  // 注意是<
            left++;
        while(array[right] >= mid && left < right)   // // 注意是>=
            right--;
        
        int tmp = array[left];
        array[left] = array[right];
        array[right] = tmp;

    }

    if(array[left] > array[end]){
        int tmp = array[left];
        array[left] = array[end];
        array[end] = tmp;
    }else
        left++;

    if(left)
        QuickSortRecursive(array, start, left-1);

    QuickSortRecursive(array, left+1, end);
    
}

void QuickSortRe(int array[], int len){
    QuickSortRecursive(array, 0 , len-1);
}

/**寻找第K个最大的元素
* 时间复杂度：O(n)
* 空间复杂度：O(log(n))
* **/
int partition(int array[], int left, int right){
    int x = array[right], i = left-1;
    int j;
    for(j = left; j < right; ++j){
        if(array[j] <= x){
            int t = array[++i];
            array[i] = array[j];array[j] = t;
        }
        
    }

    int t = array[i+1];
    array[i+1] = array[right];array[right] = t;

    return i+1; 
}

int randomPartition(int* array, int l, int r) {
    int i = rand() % (r - l + 1) + l;
    int t = array[i];
    array[i] = array[r];array[r] = t;
    return partition(array, l, r);
}


int QuickSelect(int array[], int left, int right, int index){
    int q = randomPartition(array, left, right);
    if (q == index) {
        return array[q];
    } else {
        return q < index ? QuickSelect(array, q + 1, right, index)
                         : QuickSelect(array, left, q - 1, index);
    }

}

int FindKthlargest(int array[], int len, int k){
    srand(time(0));
    return QuickSelect(array, 0, len-1, len-k);
}

void mysorted_demo(){

    if(SRAND_BUTTON)
        srand((unsigned)time(NULL));

    int array1[ARRAY_SIZE], array2[ARRAY_SIZE], array3[ARRAY_SIZE], array4[ARRAY_SIZE], array5[ARRAY_SIZE], array6[ARRAY_SIZE];

    int size = 100;
    printf("生成一个%d以内的随机数：%d\n", size, GenRandomNum(size));

    printf("创建了一个长度为：%d的数列\n", ARRAY_SIZE);
    GenRandomArray(array1, ARRAY_SIZE);
    ArrayTraverse(array1,ARRAY_SIZE);
    printf("冒泡排序：\n", ARRAY_SIZE);
    BubbleSort(array1, ARRAY_SIZE);
    ArrayTraverse(array1,ARRAY_SIZE);

    printf("创建了一个长度为：%d的数列\n", ARRAY_SIZE);
    GenRandomArray(array2, ARRAY_SIZE);
    ArrayTraverse(array2,ARRAY_SIZE);
    printf("插入排序：\n", ARRAY_SIZE);
    InsertSort(array2, ARRAY_SIZE);
    ArrayTraverse(array2,ARRAY_SIZE);

    printf("创建了一个长度为：%d的数列\n", ARRAY_SIZE);
    GenRandomArray(array3, ARRAY_SIZE);
    ArrayTraverse(array3,ARRAY_SIZE);
    printf("选择排序：\n", ARRAY_SIZE);
    InsertSort(array3, ARRAY_SIZE);
    ArrayTraverse(array3,ARRAY_SIZE);

    printf("创建了一个长度为：%d的数列\n", ARRAY_SIZE);
    GenRandomArray(array4, ARRAY_SIZE);
    ArrayTraverse(array4,ARRAY_SIZE);
    printf("归并排序(递归法)：\n", ARRAY_SIZE);
    MergeSortRe(array4, ARRAY_SIZE);
    ArrayTraverse(array4,ARRAY_SIZE);

    printf("创建了一个长度为：%d的数列\n", ARRAY_SIZE);
    GenRandomArray(array5, ARRAY_SIZE);
    ArrayTraverse(array5,ARRAY_SIZE);
    int k = 3;
    int kth = FindKthlargest(array5, ARRAY_SIZE, k);
    printf("第%d大的元素为(算法计算)%d：\n", k, kth);

    printf("快速排序(递归法)：\n", ARRAY_SIZE);
    QuickSortRe(array5, ARRAY_SIZE);
    ArrayTraverse(array5,ARRAY_SIZE);

    if(kth == array5[ARRAY_SIZE-k])
        printf("function find answer correct!\n");
    else
        printf("function find answer error!\n");

    

    
}