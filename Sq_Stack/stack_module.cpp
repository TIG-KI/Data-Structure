#include<stdio.h>
#include<stdlib.h>
#include"DataType.h"
#include"stack_module.h"

Status InitStack(SqStack &s){
    //构造一个空栈
    s.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(int));
    if(!s.base){
        exit(OVERFLOW);
    }
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
    return OK;
} //栈的初始化

Status GetTop(SqStack s,SElemType &e){
    //若栈不为空，则用e返回s的栈顶元素，并返回OK，否则返回ERROR
    if(s.top == s.base){
        return ERROR;
    }
    //printf("%d\n",*(s.top-1));
    e = *(s.top-1);
    return OK;
} //获取栈顶元素

Status Push(SqStack &s, SElemType e){
    //插入元素e为新的栈顶元素
    if((s.top-s.base)>= s.stacksize){
        s.base = (SElemType *)realloc(s.base,(STACK_INIT_SIZE+STACKINCREMENT)*sizeof(SElemType));
        if(!s.base){
            exit(OVERFLOW); //存储空间分配失败
        }
        s.top = s.base + s.stacksize;
        s.stacksize  += STACKINCREMENT;
    }

    *s.top++ = e; //将e放置于原栈顶指针所指位置，然后将栈顶指针位置加一
    //printf("%d\n",*(s.top-1));
    return OK;
} //向栈顶压入新的栈顶元素

Status Pop(SqStack &s, SElemType &e){
    //若栈不为空，则删除s的栈顶元素，用e返回其值并返回ok，否则返回error
    if(s.base == s.top){ //栈为空
        return ERROR;
    }
    e = *--s.top; //先将栈顶指针减一然后将此时栈顶指针所指地址的数据赋给e，因为这个e为原栈的栈顶元素
    return OK;
} // 弹出栈顶元素

void DisStack(SqStack &s){
    SElemType e;
    if(s.base==s.top){
        printf("该栈为空!");
    }
    while(s.base!=s.top){
        Pop(s,e);
        printf("%c ",e);
    }
}

//将栈清空
void ClearStack(SqStack &s){
    SElemType e;
    while(s.top != s.base){
        Pop(s,e);
    }
}

//销毁栈
void DestoryStack(SqStack &s){
    ClearStack(s);
    s.stacksize = 0;
    s.top = s.base = NULL;
}


