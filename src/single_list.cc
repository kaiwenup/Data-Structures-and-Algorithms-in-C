#include "../inc/single_list.h"




Status visit(ElemType c){
    printf("%d ", c);
    return OK;
}

Status InitList(Linklist *L){
    *L = (Linklist)malloc(sizeof(List_Node));

    if(!(*L)){
        return ERROR;
    }

    (*L)->next = NULL;

    return OK;
}

Status ListEmpty(Linklist L){  // 注意与上个函数传入值的区别
    if(L->next == NULL)
        return FALSE;
    else  
        return TRUE;
}

Status ClearList(Linklist *L){
    Linklist p,q;
    p = (*L)->next;

    while(p){
        q = p->next;
        free(p);
        p = q;
    }

    (*L)->next = NULL;
    return OK;
}

/* 初始条件：链式线性表L已存在。操作结果：返回L中数据元素个数 */
Status ListLength(Linklist L){
    int i = 0;
    Linklist p = L->next;
    while(p){
        ++i;
        p = p->next;
    }

    return i;
}

/* 初始条件：链式线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
Status GetElem(Linklist L, int i, ElemType *e){
    // Linklist p = L->next;

    // while(--i){
    //     if(p == NULL)
    //         return ERROR;
    //     p = p->next;
    // }

    // *e = p->data;
    // return TRUE;
    int j;
	Linklist p;		/* 声明一结点p */
	p = L->next;		/* 让p指向链表L的第一个结点 */
	j = 1;		/*  j为计数器 */
	while (p && j<i)  /* p不为空或者计数器j还没有等于i时，循环继续 */
	{   
		p = p->next;  /* 让p指向下一个结点 */
		++j;
	}
	if ( !p || j>i ) 
		return ERROR;  /*  第i个元素不存在 */
	*e = p->data;   /*  取第i个元素的数据 */
	return OK;
}

/* 初始条件：链式线性表L已存在 */
/* 操作结果：返回L中第1个与e满足相等关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
Status LocateElem(Linklist L, ElemType e){
    int i = 0;
    Linklist p = L->next;

    while(p){
        i++;
        if(p->data == e)
            return i;
        
        p = p->next;
    }

    return ERROR;

}

/* 初始条件：链式线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(Linklist *L, int i, ElemType e){
    Linklist index, tmp;
    index = *L;
    int j = 1;

    while(index->next && j < i ){
        index = index->next;
        ++j;
    }
    if (!index || j > i) 
		return ERROR;   /* 第i个元素不存在 */

    tmp = (Linklist)malloc(sizeof(List_Node));
    tmp->data = e;
    tmp->next = index->next;
    index->next = tmp;



    return OK;
    
}


/* 初始条件：链式线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */

Status ListDelete(Linklist *L, int i, ElemType *e){
    
    Linklist index, tmp;
    index = *L;

    int j = 1;

    while(index->next && j < i ){
        index = index->next;
        ++j;
    }

    if(!(index->next) || j > i){
        return ERROR;
    }
    
    tmp = index->next;
    index->next = tmp->next;
    *e = tmp->data;
    free(tmp);
    return OK;

}

/* 初始条件：链式线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(Linklist L){
    Linklist index = L->next;

    while(index){
        visit(index->data);
        index = index->next;
    }
    printf("\n");
    return OK;
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void CreateListHead(Linklist *L, int n) {
    Linklist index;
    int i;
    srand(time(0));  // 初始化随机数种子
    *L = (Linklist)malloc(sizeof(List_Node));
    (*L)->next = NULL;

    for(i = 0; i < n; i++){
        index = (Linklist)malloc(sizeof(List_Node));
        index->data = rand()%100+1;             /*  随机生成100以内的数字 */
        index->next = (*L)->next;
        (*L)->next = index;

    }
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(Linklist *L, int n) {
    Linklist tmp, index;

    *L = (Linklist)malloc(sizeof(List_Node));
    index = *L;
    int i;
    srand(time(0));  // 初始化随机数种子
    for(i = 0; i < n; i++){
        tmp = (Linklist)malloc(sizeof(List_Node));
        tmp->data =  rand()%100+1;    /*  随机生成100以内的数字 */
        index->next = tmp;
        index = tmp;
    }

    index->next = NULL;
}

/*  随机产生n个元素的值，建立环形单链线性表L（尾插法)，并将尾部节点指向第k个节点 */
void CreateCircularListTail(Linklist *L, int n, int k) {
    Linklist tmp, index;

    if(n < k){
        
        printf("CreateCircularListTail initial error!!!\n");
        return ;
    }

    *L = (Linklist)malloc(sizeof(List_Node));
    index = *L;
    int i;
    srand(time(0));  // 初始化随机数种子
    for(i = 0; i < n; i++){
        tmp = (Linklist)malloc(sizeof(List_Node));
        tmp->data =  i+1;    /*  随机生成100以内的数字 */
        index->next = tmp;
        index = tmp;
    }

    tmp = (*L)->next;
    int j = 1;
    while(tmp && j<k){
        tmp = tmp->next;
        ++j;
    }
    if(!tmp || j>i){
        
        printf("CreateCircularListTail  error!!!\n");
        return ;
    }


    index->next = tmp;
    printf("cycle data is: %d | ",tmp->data);
}

// 使用尾插法生成n个有序链表
void CreateSortedListTail(Linklist *L, int n) {
    Linklist tmp, index;
    int sum = 0;

    *L = (Linklist)malloc(sizeof(List_Node));
    index = *L;
    int i;
    
    for(i = 0; i < n; i++){
        tmp = (Linklist)malloc(sizeof(List_Node));
        srand(time(0));  // 初始化随机数种子
        tmp->data =  sum + rand()%10+1;    /*  sum随机加10以内的数字 */
        sum = tmp->data;
        index->next = tmp;
        index = tmp;
    }

    index->next = NULL;
}


// 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null
// https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode-solution/
Linklist* detectCycle(Linklist* head){
    Linklist fast = *head, slow = *head;
    while(fast != NULL){
        slow = slow->next;
        if(fast->next == NULL)
            return NULL;
        fast = fast->next->next;
        if(fast == slow){
            static Linklist ptr = *head;
            while(ptr != slow){
                ptr = ptr->next;
                slow = slow->next;
            }
        
            return &ptr;
        }
    
    }
    return NULL;
}



// 翻转单链表 迭代法
Linklist* reverseList(Linklist* head) {
    Linklist prev = NULL;
    Linklist curr = (*head)->next;
    while (curr) {
        Linklist next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    (*head)->next = prev;
    return head;
}

// 翻转单链表 递归法
static Linklist tail = NULL;

// static Linklist* tail = NULL; 
//错误写法，将指针设置成静态变量时，程序可以全程调用tail所指向地址的数据也就是能够读取到(*tail)的数据，但是读取不到(*tail->data)的数据

Linklist* reverseList_Iteration(Linklist* head) {

    if((*head)==NULL || (*head)->next == NULL)
        return head;


    tail = (*reverseList_Iteration(&((*head)->next)));
    // tail = reverseList_Iteration(&((*head)->next));
    (*head)->next->next = (*head);
    (*head)->next = NULL;


    return &tail;

}

Linklist* reverseList_It(Linklist* head){

    Linklist* tmp = reverseList_Iteration(&((*head)->next));
    
    (*head)->next = (*tmp);

    return head;

}



// 合并两个有序列表
// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

// 迭代法 时间复杂度：O(n+m) 空间复杂度：O(1)
Linklist* mergeTwoLists(Linklist* head1, Linklist* head2){
    Linklist prehead;
    InitList(&prehead);
    static Linklist prev = prehead;
    Linklist l1 = (*head1)->next, l2 = (*head2)->next;
    while(l1 != NULL && l2 != NULL){
        if(l1->data <= l2->data){
            prev->next = l1;
            l1 = l1->next;
        }
        else{
            prev->next = l2;
            l2 = l2->next;
        }
        prev = prev->next;
    }

    prev->next = l1 == NULL ? l2 : l1;
    // prev->next = ((l1 == NULL) ? l2 : l1);
    head1 = &prehead;
    return head1;

}

// 递归法 时间复杂度：O(n+m) 空间复杂度：O(n+m)
// https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/yi-kan-jiu-hui-yi-xie-jiu-fei-xiang-jie-di-gui-by-/
Linklist* mergeTwoLists_Iteration(Linklist* l1, Linklist* l2){

    // static Linklist l1 = *head1, l2 = *head2;
    if((*l1) == NULL)
        return l2;
    if((*l2) == NULL)
        return l1;
    if((*l1)->data <= (*l2)->data){
        (*l1)->next = (*mergeTwoLists_Iteration(&(*l1)->next, l2));
        return l1;
    }
    else{
        (*l2)->next = (*mergeTwoLists_Iteration(l1, &(*l2)->next));
        return l2;
    }

}

Linklist* mergeTwoLists_It(Linklist* head1, Linklist* head2){
    
    Linklist* tmp =  mergeTwoLists_Iteration(&((*head1)->next), &((*head2)->next));

    (*head1)->next = (*tmp);

    return head1;
}

// 删除链表的倒数第N个节点 双指针
// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
// 仅遍历一次
// https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/
Linklist* removeNthFromEnd(Linklist* head, int n){

    Linklist p = *head;
    Linklist q = *head;
    Linklist delNode;

    for(int i = 0; i < n+1; i++){
        q = q->next;
    }

    while(q){
        p = p->next;
        q = q->next;
    }

    delNode = p->next;
    p->next = delNode->next;
    free(delNode);

    return head;
    
}
// 错误示范
// Linklist* removeNthFromEnd(Linklist* head, int n){
//     // Linklist node_head = (*head)->next;
//     // Linklist dummyhead;
//     // InitList(&dummyhead);
//     // dummyhead->next = (*head)->next;
//     Linklist p = *head; // 写法有问题
//     Linklist q = *head;
//     // Linklist* p = &dummyhead; 
//     // Linklist* q = &dummyhead;
//     for(int i = 0; i < n; i++){
//         q = q->next;
//     }
//     while(q){
//         p = p->next;
//         q = q->next;
//     }

//     Linklist* delNode = &(p->next);
//     p->next = (*delNode)->next;
//     free(*delNode);

//     return head;
    
// }

// 错误示范
// Linklist* removeNthFromEnd(Linklist* head, int n){
//     Linklist* dummy;
//     *dummy = (Linklist)malloc(sizeof(List_Node));
//     (*dummy)->next = (*head)->next;
//     Linklist* first = &((*head)->next);
//     Linklist* second = dummy;

//     while (*first) {
//         (*first) = (*first)->next;
//         (*second) = (*second)->next;
//     }


// }

// 给定一个头结点为head的非空单链表，返回链表的中间结点。
// 如果有两个中间结点，则返回第二个中间结点。
// 快慢指针法
// https://leetcode-cn.com/problems/middle-of-the-linked-list/solution/
Linklist* middleNode(Linklist* head){
    static Linklist slow = (*head);
    Linklist fast = (*head);

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return &slow;
}

void single_list_demo(){
    Linklist L;
    Linklist* L1, * L3;  // 注意初始化的方式
    ElemType e;
    Status i;
    int j, k;
    int num = 3;

    Linklist SortedL1,  SortedL2,SortedL3,  SortedL4, * mergeL3,* mergeL4;

    /********单链表顺序插入******/
    i = InitList(&L);
    printf("初始化L后：ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L);

    /********翻转单链表******/
    // L1 = reverseList_Iteration(&(L->next));
    L1 = reverseList_It(&L);
    printf("翻转之后：L.data=");
    ListTraverse(*L1);

    /********检测链表的环(有待改进)******/
    Linklist* L2;  // 注意初始化的方式
    printf("链表中环的检测：\n");
    CreateCircularListTail((&(*L1)->next),7,3);
    L2 = detectCycle(L1);
    if( L2 != NULL)
        visit((*L2)->data);

    printf("\n");

    /********合并两个有序链表******/
    // 迭代法
    printf("使用迭代法合并两个有序单链表：\n");
    CreateSortedListTail(&SortedL1, 8);
    // sleep(1);  //延时等待一秒
    // CreateSortedListTail(L1, 8); // 错误初始方法，不能将指针传入，作为一个初始化的参数，而是要将一个实体传入
    CreateSortedListTail(&SortedL2, 2);
    ListTraverse(SortedL1);
    ListTraverse(SortedL2);
    mergeL3 = mergeTwoLists(&SortedL1, &SortedL2);
    ListTraverse(*mergeL3);

    // 递归法
    printf("使用递归法合并两个有序单链表：\n");
    CreateSortedListTail(&SortedL3, 3);
    // sleep(1);  //延时等待一秒
    CreateSortedListTail(&SortedL4, 2);
    ListTraverse(SortedL3);
    ListTraverse(SortedL4);
    mergeL4 = mergeTwoLists_It(&SortedL3, &SortedL4);
    ListTraverse(*mergeL4);
    
    /********删除单链表中的倒数第n个节点******/
    printf("删除单链表中的倒数第n个节点\n");
    Linklist L4;
    Linklist* L5;
    CreateListTail(&L4, 10);
    ListTraverse(L4);
    L5 = removeNthFromEnd(&L4,3);
    ListTraverse(*L5);

    /********求链表的中间节点******/
    printf("求链表的中间节点\n");
    Linklist L6;
    Linklist* L7;
    CreateListTail(&L6, 5);
    ListTraverse(L6);
    L5 = middleNode(&L6);
    printf("链表的中间节点数值为：%d\n", (*L5)->data);



    

    
}