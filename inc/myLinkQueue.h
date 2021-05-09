#ifndef MYLINKQUEUE_H
#define MYLINKQUEUE_H

#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status; 

typedef int QElemType; /* QElemType类型根据实际情况而定，这里假设为int */

typedef struct Qnode{  /* 结点结构 */
    QElemType data;
    struct Qnode* next;

}Qnode, *QueuePtr;

typedef struct{  /* 队列的链表结构 */
    QueuePtr front, rear;  /* 队头、队尾指针 */  
}LinkQueue;

Status InitQueue(LinkQueue *Q);
Status DestroyQueue(LinkQueue *Q);
Status ClearQueue(LinkQueue *Q);
Status QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
QElemType GetHead(LinkQueue Q);
Status EnQueue(LinkQueue *Q,QElemType e);  //入队列
QElemType DeQueue(LinkQueue *Q);  // 出队列
Status QueueTraverse(LinkQueue Q);

void base_queue_demo();
int myLinkQueue_demo();

#endif