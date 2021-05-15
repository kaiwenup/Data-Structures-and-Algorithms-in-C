#include "../inc/mysorted.h"
#include "../inc/ComFun.h"

/**
 * 常见的排序算法：
 * 参考教程：
 * （1）极客时间-数据结构与算法之美
 * （2）菜鸟教程-C排序算法 https://www.runoob.com/cprogramming/c-sort-algorithm.html
 * **/

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

void mysorted_demo(){

    int array1[ARRAY_SIZE], array2[ARRAY_SIZE], array3[ARRAY_SIZE];

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
}