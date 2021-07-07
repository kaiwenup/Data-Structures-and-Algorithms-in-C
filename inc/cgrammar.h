#ifndef CGRAMMAR_H
#define CGRAMMAR_H

// 系统头文件
#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"  
#include <unistd.h> 
#include "math.h"  
#include "time.h"

// 自定义头文件
#include "fatal.h"

// 参考博客：https://coolshell.cn/articles/11377.html
struct test{
    int i;
    short c;
    char *p;
    char s[10];
};

// 零长度数组
struct line{
    int length;
    char contents[0]; // C99的玩法是：char contents[]; 没有指定数组长度

};

typedef struct line2{
    int length;
    char *contents;
} line2;

void CGrammarDemo();


#endif