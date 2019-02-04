#include"DataType.h"
#ifndef STACK_MOUDLE
#endif // STACK_MOUDLE
#define STACK_INIT_SIZE 100 //储存空间初始分配量
#define STACKINCREMENT  10  //存储空间分配增量
#define ERROR 0
#define OK 1
#define OVERFLOW -2

typedef struct{
    SElemType *top;   //栈顶指针
    SElemType *base;   //在栈构造之前和销毁之后，base的值为NULL
    int stacksize;      //当前已分配的存储空间
}SqStack;

extern Status InitStack(SqStack &s);
extern Status GetTop(SqStack s,SElemType &e);
extern Status Push(SqStack &s, SElemType e);
extern Status Pop(SqStack &s, SElemType &e);
extern void DisStack(SqStack &s);
void ClearStack(SqStack &s);
void DestoryStack(SqStack &s);
