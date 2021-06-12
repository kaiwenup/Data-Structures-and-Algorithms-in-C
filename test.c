#include "inc/mylist.h"
#include "inc/mystack.h"
#include "inc/myLinkQueue.h"
#include "inc/mysorted.h"
#include "inc/myhash.h"
#include "inc/ComFun.h"
#include "inc/uthash/uthash.h"
#include "inc/mybinarytree.h"
#include "inc/exptree.h"
#include "time.h"

int main() 
{
    if(SRAND_BUTTON)
        srand((unsigned)time(NULL));

    /******单链表相关算法******/
    // single_list_demo();

    /******堆栈相关算法******/
    // mystack_demo();

    /******队列相关算法******/
    // myLinkQueue_demo();

    /******排序相关算法******/
    // mysorted_demo();

    /******Hash相关算法******/
    // hash_base_demo();

    /******二叉树相关算法******/
    // 二叉搜索树
    // mybinarytree_demo();
    MySearchTreeDemo();
    // 表达式树
    // ExpressionTree();

    
 
    return 0;
}
