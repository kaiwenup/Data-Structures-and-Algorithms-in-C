#ifndef _STACK_H
#define _STACK_H

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <stack>
using namespace std;

template <typename elemType>
class StackNode;

template <typename elemType>
class Stack;

template <typename valType>
class StackNode{
public:
    valType data;
    StackNode *pNext;

};

template <typename elemType>
class Stack{
    friend class StackNode<elemType>;
public:
    Stack();
    ~Stack();

    void CreateStack(int val);
    void ClearStack();
    elemType GetTop();
    void TraverseStack();
    bool IsEmpty();
    int GetLength();

    void Push(const elemType val);
    elemType Pop();

private:
    StackNode<elemType> *top ;
    int count;

};

template <typename elemType>
inline Stack<elemType>::Stack(){
    // head = new Node;
    // head->data = 0;
    top = NULL;
    count = 0;
    // head->pNext = NULL;
    

}

template <typename elemType>
inline Stack<elemType>::~Stack(){
    delete top;
}


template <typename elemType>
inline void Stack<elemType>::CreateStack(int val){
   if(val < 0)
        cout << "input number of StackNode error" << endl;
    
    else{
        srand(time(0));
        int ival = val;
        StackNode<elemType> *pnew;
        while(ival-- > 0){
            elemType temp = rand() %100 +1;  
            pnew = new StackNode<elemType>;
            pnew->data = temp;
            pnew->pNext = top;
            top = pnew;
            count++;
        }
    } 
}

template <typename elemType>
inline void Stack<elemType>::TraverseStack(){
    StackNode<elemType> *p = top;

    while(p != NULL && count != 0){
        cout << p->data << " ";
        p = p->pNext;
    }

    cout << endl;
}

template <typename elemType>
inline void Stack<elemType>::ClearStack(){
    StackNode<elemType> *ptemp,*pdelete = top;
    while( pdelete != NULL){
        ptemp = pdelete->pNext;
        delete pdelete;
        pdelete = ptemp;
    }
    count = 0;
}

template <typename elemType>
inline void Stack<elemType>::Push(const elemType val){
    StackNode<elemType> *pnew;
    pnew = new StackNode<elemType>;
    pnew->data = val;
    pnew->pNext = top;
    top = pnew;
    count++;
    
}

template <typename elemType>
inline elemType Stack<elemType>::Pop(){
    if(top == NULL){
        cout << "Stack pop error!!!"<< endl;
        return -1;
    }

    StackNode<elemType> *pdelete = top;
    int data = pdelete->data;
    top = pdelete->pNext;
    delete pdelete;
    count--;
    return data;
        
}

template <typename elemType>
inline elemType Stack<elemType>::GetTop(){
    cout << "Top Data is "<< top->data <<endl;  
    return top->data;
}

template <typename elemType>
inline bool Stack<elemType>::IsEmpty(){
    
    if(count == 0)
        return true;
    else
        return false;
}

template <typename elemType>
inline int Stack<elemType>::GetLength(){
    cout << "Stack Length is " << count << endl;
    return count;

}



#endif