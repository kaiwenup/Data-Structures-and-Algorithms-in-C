#include "../inc/mysorted.h"


void BubbleSort(int* array, int n){

    if(n <= 1) return;
    int flag = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1-i; j++){
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

void InsertSort(int* array, int n){

    if(n <= 1) return;

    for(int i = 1; i < n; ++i){
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