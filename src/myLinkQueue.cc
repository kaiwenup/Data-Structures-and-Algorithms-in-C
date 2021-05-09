#include "../inc/myLinkQueue.h"

/* 构造一个空队列Q */
Status InitQueue(LinkQueue* Q){
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(Qnode));
    if(!Q->front)
        return -1;
    
    Q->front->next = NULL;
    return OK;
}

/* 插入元素e为Q的新的队尾元素 */
Status EnQueue(LinkQueue *Q,QElemType e){
    QueuePtr s=(QueuePtr)malloc(sizeof(Qnode));
    if(!s) /* 存储分配失败 */
        return ERROR;
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;

    return OK;
}

/* 若队列不空,删除Q的队头元素,并返回其值,否则返回ERROR */
QElemType DeQueue(LinkQueue *Q){
    QueuePtr p;
    QElemType data;
    if(Q->front == Q->rear)
        return ERROR;
    p = Q->front->next;
    data = p->data;
    Q->front->next = p->next;
    if(Q->rear == p)  // 注意此处 /* 若队头就是队尾，则删除后将rear指向头结点*/
        Q->rear = Q->front;  //思考为什么不是Q->front = Q->rear 
    free(p);
    return data;
}

/* 若队列不空,则用队头元素,否则返回ERROR */
QElemType GetHead(LinkQueue Q){
    QueuePtr ptr;
    if(Q.front == Q.rear)
        return ERROR;
    ptr = Q.front->next;
    return ptr->data;
}

/* 销毁队列Q */
Status DestroyQueue(LinkQueue* Q){
    while(Q->front){
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }

    return OK;
}

/* 将Q清为空队列 
    Note：注意Destroy和Clear的区别*/
Status ClearQueue(LinkQueue* Q){
    QueuePtr p,q;
    Q->rear = Q->front;
    p = Q->front->next;
    Q->rear->next = NULL;
    while(p){
        q = p;
        p = p->next;
        free(q);
    }

    return OK;
}

/* 若Q为空队列,则返回TRUE,否则返回FALSE */
Status QueueEmpty(LinkQueue Q)
{ 
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}

/* 求队列的长度 */
int QueueLength(LinkQueue Q){
    int num = 0;
    QueuePtr ptr;
    ptr = Q.front;
    while(Q.rear != ptr){
        num++;
        ptr = ptr->next;
    }

    return num;
}

Status QueueTraverse(LinkQueue Q){
    QueuePtr ptr;
    ptr = Q.front->next;
    while(ptr){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");

    return OK;
}

void base_queue_demo(){
    int i;
	QElemType d;
	LinkQueue q;
	i=InitQueue(&q);
	if(i)
		printf("成功地构造了一个空队列!\n");
	printf("是否空队列？%d(1:空 0:否)  ",QueueEmpty(q));
	printf("队列的长度为%d\n",QueueLength(q));
	EnQueue(&q,-5);
	EnQueue(&q,5);
	EnQueue(&q,10);
	printf("插入3个元素(-5,5,10)后,队列的长度为%d\n",QueueLength(q));
	printf("是否空队列？%d(1:空 0:否)  ",QueueEmpty(q));
	printf("队列的元素依次为：");
	QueueTraverse(q);
	printf("队头元素是：%d\n",GetHead(q));
	printf("删除了队头元素%d\n",DeQueue(&q));
    printf("新的队头元素是：%d\n",GetHead(q));
	ClearQueue(&q);
	printf("清空队列后,q.front=%u q.rear=%u q.front->next=%u\n",q.front,q.rear,q.front->next);
	DestroyQueue(&q);
	printf("销毁队列后,q.front=%u q.rear=%u\n",q.front, q.rear);
}

int myLinkQueue_demo(){
    
    // base_queue_demo();
    return 0;

}