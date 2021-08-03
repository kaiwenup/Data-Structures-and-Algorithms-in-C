#include "limits.h"

#include "../inc/cgrammar.h"

void CGrammarDemo(){
    struct test t;
    struct test *pt = NULL;
    int i = 0;

    // pt = &t;
    // t.i = 666;
    // printf("%d\n", pt->i);


    // 零长度数组
    // 柔性数组(Flexible Array)分配一个不定长的数组
    // 结构体line中 length代表的是数组的长度，contents代表的数组的内容
    int this_length = 10;
    struct line *thisline = (struct line *)malloc(sizeof(struct line) + this_length);
    thisline->length = this_length;
    memset(thisline->contents, 'a', this_length);


    // 注意与line结构结构体初始化的区别
    line2 *thisline2 = (line2*)malloc(sizeof(line2));
    thisline2->length = this_length;
    thisline2->contents = (char*)malloc(sizeof(char)*this_length);
    memset(thisline2->contents, 'a', this_length);

    // 枚举
    enum Jar_Type {
        CUP = 1, PINT, QUART , GALLON
    };

    printf("%d\n", INT_MIN);

}
