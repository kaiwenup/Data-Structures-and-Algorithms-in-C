#include "../inc/ComFun.h"

// 随机生成n以内的随机数
int GenRandomNum(int n){

    // srand((unsigned)time(NULL));

    return rand() % n + 1;
}

// 随机生成n个100以内的随机数
void GenRandomArray(int* array, int n){

    // 按时间重新播种
	// srand((unsigned)time(NULL));
    int num;
    int i;
    for (i = 0; i < n; i++)
	{
        array[i] = rand() % 100 + 1;
    }
}

// 遍历数组并打印
void ArrayTraverse(int* array, int n){

    int i;
    for (i = 0; i < n; i++)
	{
		printf("%2d ", array[i]);
	}
    printf("\n");
}