#ifndef _RPN_H
#define _RPN_H


/**
 * 逆波兰(Reverse Polish Notation, NPN)表示:
 * 一种不需要括号的后缀表达式来进行四则运算
 * **/

/***
 * 后续优化建议：
 * 1.错误输入字符时，提示错误，而不要运行的时报段错误
 * 2.一些数组或者变量可以划为私有，以便各个函数共用
*/

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // get the priority of the operator
    int getPriority(char ch);
    
    // convert infix expression to postfix expression
    vector<char> toRPN(string s);

    int calculateRPN(vector<char> str);

    int calculate(string s);

    void display_RPN(string s);

private:
    vector<char> ans;
    stack<char> op;
};

inline int Solution::getPriority(char ch)
    {
        switch(ch)
        {
            case '(': return 0;
            case '+': return 1;
            case '-': return 1;
            case '*': return 2;
            case '/': return 2;
            default: return -1;
        }
    }

inline vector<char> Solution::toRPN(string s)
{
    vector<char> ans;   // store the postfix expression
    stack<char> op;    // operator stack
    int len = s.length();
    for(int i = 0; i < len; ++i)
    {
        // jump the space
        if(s[i] == ' ') continue;
        
        // if s[i] is a digit, put the value into ans directly
        if(s[i] >= '0' && s[i] <= '9')
        {
            while(s[i] >= '0' && s[i] <= '9')
            {
                ans.push_back(s[i]);
                ++i;
            }
            ans.push_back(' ');
            --i;
        }
        // if s[i] is an operator
        if(s[i] == '(')
        {
            op.push(s[i]);
        }

        if(s[i] == ')')
        {
            while(op.top() != '('){
                ans.push_back(op.top());
                op.pop();
            }

            op.pop();
        }

        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            // if op is empty, push s[i] directly
            if(op.empty()) op.push(s[i]);
            // if op is not empty, we should compare the priority
            else
            {
                if(getPriority(s[i]) > getPriority(op.top()))
                    op.push(s[i]);
                else
                {
                    while(!op.empty() && (getPriority(s[i]) <= getPriority(op.top())))
                    {
                        ans.push_back(op.top());
                        ans.push_back(' ');
                        op.pop();
                    }
                    op.push(s[i]);
                }
            }
            
        }
    }
    while(!op.empty())
    {
        ans.push_back(op.top());
        ans.push_back(' ');
        op.pop();
    }
    return ans;
}

inline int Solution::calculateRPN(vector<char> str)
{
    int len = str.size();
    int value1, value2, ans;
    stack<int> value;
    for(int i = 0; i < len; ++i)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            int tmp = str[i] - 48;
            int j = ++i;
            while(str[j] >= '0' && str[j] <= '9')
            {
                tmp = tmp * 10 + (str[j] - 48);
                ++j;
            }
            value.push(tmp);
            i = --j;
        }
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            value2 = value.top();
            value.pop();
            value1 = value.top();
            value.pop();
            if(str[i] == '+') ans = value1 + value2;
            else if(str[i] == '-') ans = value1 - value2;
            else if(str[i] == '*') ans = value1 * value2;
            else ans = value1 / value2;
            value.push(ans);
        }
    }
    return value.top();
}

inline int Solution::calculate(string s) {
    return calculateRPN(toRPN(s));
}

inline void Solution::display_RPN(string s){

    vector<char> str = toRPN(s);
    int len = str.size();
    for(int i = 0; i < len; i++){
        cout << str[i] << " ";
    }
}

#endif