#include "../inc/demo.h"


void calculate_RPN_test(){

    string s = "9+(3-1)*3+10/2";  // ans: 20
    Solution sol;
    sol.display_RPN(s);
    cout << "Solution is: " << sol.calculate(s) << endl;

}

void stack_test()
{
    Stack<char> st;
    char a = 'a';
    st.CreateStack(10);
    st.TraverseStack();
    st.Push(a);
    st.TraverseStack();
    st.Pop();
    st.TraverseStack();
    st.GetLength();
    st.GetTop();
    st.ClearStack();
    if(!st.IsEmpty())
        st.TraverseStack();

 
}

void linear_test()
{
    int val = 10;
    LinkList li;
    li.CreateList(val);
    li.TraverseLinkList();
    li.InsertNode(1, 66);
    li.TraverseLinkList();
    li.DeleteNode(1);
    li.TraverseLinkList();
    int num = li.GetLength();
    cout << "Length is: " << num << endl;
    cout << "value is: " << li.GetValue(10) << endl;

    DoubleLinkList dli;
    dli.CreateList(9);
    dli.TraverseLinkList();
    dli.DeleteLinkList();
    dli.TraverseLinkList();
}
