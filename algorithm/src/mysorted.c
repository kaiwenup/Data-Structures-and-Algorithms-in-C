#include "../inc/mysorted.h"

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
    int  reg[len]; //额外申请了空间，增加了内存消耗
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
// void QuickSortRecursive(int* array, int start,int end){
//     if(start >= end)
//         return;
    
//     int mid = array[end];
//     int left = start,
//         right = end-1;
    
//     while(left < right){
//         while(array[left] <= mid && left < right)  // 注意是<
//             left++;
//         while(array[right] >= mid && left < right)   // // 注意是>=
//             right--;
        
//         int tmp = array[left];
//         array[left] = array[right];
//         array[right] = tmp;

//     }

//     // if(array[left] > array[end]){
//     if(array[left] > array[end]){
//         int tmp = array[left];
//         array[left] = array[end];
//         array[end] = tmp;
//     }//else
//        // left++;

//     if(left)
//         QuickSortRecursive(array, start, left-1);

//     QuickSortRecursive(array, left+1, end);
    
// }

int Paritition1(int *array, int start, int end){
    int pivot = array[start];

    while(start < end){
        while(start < end && array[end] >= pivot)
            --end;

        array[start] = array[end];

        while(start < end && array[start] <= pivot)
            start++;

        array[end] = array[start];
        
    }

    array[start] = pivot;

    return start;
}

void QuickSortRecursive(int* array, int start,int end){

    if(start < end){
        int pivot = Paritition1(array, start, end);
        QuickSortRecursive(array, start, pivot-1);
        QuickSortRecursive(array, pivot+1, end);
    }
}


void QuickSortRe(int array[], int len){
    QuickSortRecursive(array, 0 , len-1);
}


/**桶排序
* 时间复杂度：O(n)
* 非原地排序算法？
* 稳定排序算法？
* https://www.programiz.com/dsa/bucket-sort
* Note:
* 1. 一共有10个桶(NBUCKET = 10)，每个桶的容量为10(INTERVAL = 10)，所以一共能对100个元素进行排序，范围为0~99
**/
int getBucketIndex(int value){

    return value / INTERVAL;
}

PtrBucketNode InsertSort_SinglyLinkedList(PtrBucketNode list){

    PtrBucketNode nodelist;
    PtrBucketNode index;

    if(list == NULL || list->next == NULL)
        return list;

    nodelist = list;
    index = list->next;
    nodelist->next = NULL; // !!! 这几个赋值语句顺序不能错

    while(index != NULL){
        PtrBucketNode ptr;
        if(nodelist->data > index->data){
            PtrBucketNode tmp;
            tmp = index;
            index = index->next;
            tmp->next = nodelist;
            nodelist = tmp;
            continue;
        }
        
        // 两种情况退出for循环。1. break 2. ptr == NULL
        for(ptr = nodelist; ptr->next != NULL; ptr = ptr->next){

            if(ptr->next->data > index->data)
                break;
        }

        if(ptr->next != NULL){
            PtrBucketNode tmp;
            tmp = index;
            index = index->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            continue;
        }
        else{
            ptr->next = index;
            index = index->next;
            ptr->next->next = NULL;
            continue;

        }


    }

    return nodelist;

    

}

void printBuckets(PtrBucketNode list){
    PtrBucketNode cur = list;

    while(cur){
        printf("%d ", cur->data);
        cur = cur->next;         
    }
}

void BucketSort(int array[], int len){

    int i, j;
    // 创建buckets
    PtrBucketNode* buckets = (PtrBucketNode*)malloc(sizeof(BucketNode*) * NBUCKET);

    // 初始化buckets
    for(i = 0; i < NBUCKET; i++){
        buckets[i] = NULL;
    }

    // 将数组中的各个元素放入桶中
    for(i = 0; i < len; i++){

        PtrBucketNode current;
        int pos = getBucketIndex(array[i]);
        current = (PtrBucketNode)malloc(sizeof(BucketNode));
        current->data = array[i];
        current->next = buckets[pos];
        buckets[pos] = current;

    }

    //打印各个桶中的元素
    for(i = 0; i < NBUCKET; i++){
        printf("Bucket[%d]: ", i);
        printBuckets(buckets[i]);
        printf("\n");
    }

    // 每个bucket分别用插入排序法进行排序
    for(i = 0; i < NBUCKET; i++){

        buckets[i] = InsertSort_SinglyLinkedList(buckets[i]);
    }

    printf("-------------\n");
    printf("Bucktets after sorting\n");
    for (i = 0; i < NBUCKET; i++) {
        printf("Bucket[%d]: ", i);
        printBuckets(buckets[i]);
        printf("\n");
    }
    

    // 将排序好的元素放入数组中
    for(j = 0, i = 0; i < NBUCKET; i++){
        PtrBucketNode node;
        node = buckets[i];
        while(node){
            array[j++] = node->data;
            node = node->next;
        }
    }

}   


/**寻找第K个最大的元素，返回其值***********************************
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

    if(k > len)
        return -1;
    return QuickSelect(array, 0, len-1, len-k);
}

/**寻找数组第K大的元素，返回其值****************************/


int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b; //由小到大排序
    // return *(int *)b - *(int *)a; //由大到小排序
}

/**二分查找**/
int BsearchRecursive(int array[], int left, int right, int val){
    if(left > right)
        return -1;
    
    int mid = left + ((right - left)>>1);
    if(val == array[mid])
        return mid;
    else if(val > array[mid]){
        BsearchRecursive(array, mid+1, right, val);
    }else{
        BsearchRecursive(array, left, mid, val);
    }

}
int Bsearch(int array[], int len, int val){
    return BsearchRecursive(array, 0, len-1, val);
}




void mysorted_demo(){

    // if(SRAND_BUTTON)
    //     srand((unsigned)time(NULL));
    srand((unsigned)time(NULL));
    printf("生成元素个数为%d的一维数组：\n", ARRAY_SIZE);
    int array[ARRAY_SIZE];
    GenRandomArray(array, ARRAY_SIZE);
    ArrayTraverse(array,ARRAY_SIZE);
    // int arr1[6] = {4,3,6,7,4,4};
    int arr1[6] = {65,35,60,49,2,12};
    // 可以使用二维数组来批量生成多个一维数组
    // int array1[ARRAY_SIZE], array2[ARRAY_SIZE], array3[ARRAY_SIZE], array4[ARRAY_SIZE], array5[ARRAY_SIZE], array6[ARRAY_SIZE];
    // memcpy(array1,array,sizeof(int)*ARRAY_SIZE);
    // memcpy(array2,array,sizeof(int)*ARRAY_SIZE);
    // memcpy(array3,array,sizeof(int)*ARRAY_SIZE);
    // memcpy(array4,array,sizeof(int)*ARRAY_SIZE);
    // memcpy(array5,array,sizeof(int)*ARRAY_SIZE);

    int array_nums = 8;  // 用后续排序算法的一维数组的个数
    int arr[array_nums][ARRAY_SIZE];  //二维数组来批量生成多个一维数组

    int i;  
    for(i = 0; i < array_nums; i++){
        memcpy(arr[i],array,sizeof(int)*ARRAY_SIZE);
    }
    int size = 50;
    printf("生成一个%d以内的随机数：%d\n", size, GenRandomNum(size));

    printf("冒泡排序：\n");
    BubbleSort(arr[0], ARRAY_SIZE);
    ArrayTraverse(arr[0],ARRAY_SIZE);

    printf("插入排序：\n");
    InsertSort(arr[1], ARRAY_SIZE);
    ArrayTraverse(arr[1],ARRAY_SIZE);

    printf("选择排序：\n");
    InsertSort(arr[2], ARRAY_SIZE);
    ArrayTraverse(arr[2],ARRAY_SIZE);

    printf("归并排序(递归法)：\n");
    MergeSortRe(arr[3], ARRAY_SIZE);
    ArrayTraverse(arr[3],ARRAY_SIZE);

    printf("桶排序：\n");
    int arr2[ARRAY_SIZE] = {67, 32, 33, 36, 37, 47};
    for(i = 0; i < ARRAY_SIZE; i++){
        arr2[i] = GenRandomNum(99);
    }
     
    printf("Initial array: ");
    ArrayTraverse(arr2, ARRAY_SIZE);
    printf("-------------\n");
    BucketSort(arr2, ARRAY_SIZE);
    printf("-------------\n");
    printf("Sorted array: ");
    ArrayTraverse(arr2, ARRAY_SIZE);

    int k = 2; // 第k大的元素
    int kth = FindKthlargest(arr[3], ARRAY_SIZE, k);
    printf("第%d大的元素为(算法计算)%d：\n", k, kth);

    printf("快速排序(递归法)：\n");
    QuickSortRe(arr[4], ARRAY_SIZE);
    // QuickSortRe(arr1, ARRAY_SIZE);
    ArrayTraverse(arr[4],ARRAY_SIZE);
    // ArrayTraverse(arr1,ARRAY_SIZE);

    printf("数组寻找第K大的元素验证：\n");
    if(kth == arr[4][ARRAY_SIZE-k])
        printf("function find answer correct!\n");
    else
        printf("function find answer error!\n");

    qsort(arr[5], ARRAY_SIZE, sizeof(arr[5][0]), cmp);
    printf("快速排序(C语言库函数)：\n");
    ArrayTraverse(arr[5],ARRAY_SIZE);

    int find_val = arr[5][3];
    printf("二分法查找(递归法)元素为%d, 序号为：%d：\n", find_val, Bsearch(arr[5], ARRAY_SIZE,find_val));

    
}