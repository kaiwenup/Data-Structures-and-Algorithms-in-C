#ifndef MYSORTED_H
#define MYSORTED_H

#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"  
#include <unistd.h> 

#include "math.h"  
#include "time.h"

#define ARRAY_SIZE 6

void BubbleSort(int* array, int n);
void InsertSort(int* array, int n);
void SelectionSort(int* array, int n);

void mysorted_demo();



#endif