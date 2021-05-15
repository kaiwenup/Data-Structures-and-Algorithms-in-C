#include "../inc/mysorted.h"


/**冒泡排序
 * **/
void BubbleSort(int* array, int n){

    if(n <= 1) return;
    int flag = 0;
    int i,j;
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
}