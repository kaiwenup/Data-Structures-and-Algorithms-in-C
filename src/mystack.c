#include "../inc/mystack.h"

/*  构造一个空栈S */
Status InitStack(LinkStack *S){
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));

    if(!S->top)
        return ERROR;

    S->top = NULL;
    S->count = 0;

    return OK;
}

/* 把S置为空栈 */
Status ClearStack(LinkStack* S){
    LinkStackPtr p, q;
    p = S->top;
    while(p){
        q = p;
        p = p->next;
        free(q);

    }

    S->count = 0;

    return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status IsEmpty(LinkStack S){
    if(S.count == 0)  // 注意此处的写法和链表写法的区别
        return TRUE;
    else
        return FALSE;
}

/* 返回S的元素个数，即栈的长度 */
int StackLength(LinkStack S){
    return S.count;
}

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
SElemType GetTop(LinkStack S){
    if(S.top == NULL)
        return -1;
    else  
        return S.top->data;
}

/* 插入元素e为新的栈顶元素 */
Status Push(LinkStack *S, SElemType elem){
    LinkStackPtr newNode = (LinkStackPtr)malloc(sizeof(StackNode));

    newNode->data = elem;
    newNode->next = S->top;
    S->top = newNode;
    S->count++;

    return OK;


}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
SElemType Pop(LinkStack *S){
    LinkStackPtr delNode;
    if(IsEmpty(*S))
        return ERROR;
    
    SElemType elem = S->top->data;
    delNode = S->top;
    S->top = S->top->next;
    free(delNode);

    S->count--;

    return elem;
}

// 遍历堆栈
Status TraverseStack(LinkStack S){

    LinkStackPtr tmp;
    tmp = S.top;
    while(tmp){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }

    printf("\n");

    return OK;
}

void CreateStack(LinkStack* S, int val){

    int i = 0;
    if(InitStack(S) == OK){  // 不加这一行报段错误
        for(i=0; i<val; i++){
            Push(S, i);
        }
    }
    
    
}

// 根据逆波兰表示法，求表达式的值,栈实现。
// 有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
// https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/solution/ni-bo-lan-biao-da-shi-qiu-zhi-by-leetcod-wue9/
bool isNumber(char* token){
    return strlen(token) > 1 || ('0' <= token[0] && token[0] <= '9');

}

int evalRPN(char** tokens, int tokensSize){
    int n = tokensSize;
    LinkStack stk;
    int num2;
    int num1;
    if(InitStack(&stk) == OK)
    {
        int i;
        for(i = 0; i < n; i++){
            char* token = tokens[i];
            if(isNumber(token)){
                int tmp = atoi(token);
                Push(&stk, tmp);
            }
            else{
                num2 = Pop(&stk);
                num1 = Pop(&stk);
            }
            switch (token[0])
            {
            case '+':
                Push(&stk, num1 + num2);
                break;
            case '-':
                Push(&stk, num1 - num2);
                break;
            case '*':
                Push(&stk, num1 * num2);
                break;
            case '/':
                Push(&stk, num1 / num2);
                break;
            }
        }

        return GetTop(stk);
    }

    return ERROR;
}

int mystack_demo(){

    LinkStack s1;
    CreateStack(&s1,10);
    printf("栈中元素依次为：\n");
    TraverseStack(s1);
    printf("弹出的栈顶元素: e=%d\n", Pop(&s1));
    printf("栈空否：%d(1:空 0:否)\n",IsEmpty(s1));
    printf("栈顶元素: e=%d 栈的长度为: %d\n", GetTop(s1),StackLength(s1));
    ClearStack(&s1);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",IsEmpty(s1));

    /******根据逆波兰表示法，求表达式的值,栈实现******/
    printf("根据逆波兰表示法，求表达式的值\n");
    char* tokens[] = {"4","13","5","/","+"};  // 答案是6
    printf("结果是：%d\n", evalRPN(tokens, 5));
    
    return 0 ;
}

