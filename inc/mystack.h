#ifndef MYSTACK_H
#define MYSTACK_H

#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h" 
#include <stdbool.h> 
#include <unistd.h> 

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;
typedef int SElemType;

typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct{
    LinkStackPtr top;
    int count;
}LinkStack;

Status InitStack(LinkStack* S);
void CreateStack(LinkStack* S, int val);
Status ClearStack(LinkStack* S);
SElemType GetTop(LinkStack S);
Status TraverseStack(LinkStack S);
Status IsEmpty(LinkStack S);
int GetLength(LinkStack S);
Status Push(LinkStack *S, SElemType elem);
SElemType Pop(LinkStack *S);

bool isNumber(char* token);
int evalRPN(char** tokens, int tokensSize);


int mystack_demo();




#endif