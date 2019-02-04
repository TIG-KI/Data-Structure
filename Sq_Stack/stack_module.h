#include"DataType.h"
#ifndef STACK_MOUDLE
#endif // STACK_MOUDLE
#define STACK_INIT_SIZE 100 //����ռ��ʼ������
#define STACKINCREMENT  10  //�洢�ռ��������
#define ERROR 0
#define OK 1
#define OVERFLOW -2

typedef struct{
    SElemType *top;   //ջ��ָ��
    SElemType *base;   //��ջ����֮ǰ������֮��base��ֵΪNULL
    int stacksize;      //��ǰ�ѷ���Ĵ洢�ռ�
}SqStack;

extern Status InitStack(SqStack &s);
extern Status GetTop(SqStack s,SElemType &e);
extern Status Push(SqStack &s, SElemType e);
extern Status Pop(SqStack &s, SElemType &e);
extern void DisStack(SqStack &s);
void ClearStack(SqStack &s);
void DestoryStack(SqStack &s);
