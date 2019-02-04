#include<stdio.h>
#include<stdlib.h>
#include"DataType.h"
#include"stack_module.h"

Status InitStack(SqStack &s){
    //����һ����ջ
    s.base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(int));
    if(!s.base){
        exit(OVERFLOW);
    }
    s.top = s.base;
    s.stacksize = STACK_INIT_SIZE;
    return OK;
} //ջ�ĳ�ʼ��

Status GetTop(SqStack s,SElemType &e){
    //��ջ��Ϊ�գ�����e����s��ջ��Ԫ�أ�������OK�����򷵻�ERROR
    if(s.top == s.base){
        return ERROR;
    }
    //printf("%d\n",*(s.top-1));
    e = *(s.top-1);
    return OK;
} //��ȡջ��Ԫ��

Status Push(SqStack &s, SElemType e){
    //����Ԫ��eΪ�µ�ջ��Ԫ��
    if((s.top-s.base)>= s.stacksize){
        s.base = (SElemType *)realloc(s.base,(STACK_INIT_SIZE+STACKINCREMENT)*sizeof(SElemType));
        if(!s.base){
            exit(OVERFLOW); //�洢�ռ����ʧ��
        }
        s.top = s.base + s.stacksize;
        s.stacksize  += STACKINCREMENT;
    }

    *s.top++ = e; //��e������ԭջ��ָ����ָλ�ã�Ȼ��ջ��ָ��λ�ü�һ
    //printf("%d\n",*(s.top-1));
    return OK;
} //��ջ��ѹ���µ�ջ��Ԫ��

Status Pop(SqStack &s, SElemType &e){
    //��ջ��Ϊ�գ���ɾ��s��ջ��Ԫ�أ���e������ֵ������ok�����򷵻�error
    if(s.base == s.top){ //ջΪ��
        return ERROR;
    }
    e = *--s.top; //�Ƚ�ջ��ָ���һȻ�󽫴�ʱջ��ָ����ָ��ַ�����ݸ���e����Ϊ���eΪԭջ��ջ��Ԫ��
    return OK;
} // ����ջ��Ԫ��

void DisStack(SqStack &s){
    SElemType e;
    if(s.base==s.top){
        printf("��ջΪ��!");
    }
    while(s.base!=s.top){
        Pop(s,e);
        printf("%c ",e);
    }
}

//��ջ���
void ClearStack(SqStack &s){
    SElemType e;
    while(s.top != s.base){
        Pop(s,e);
    }
}

//����ջ
void DestoryStack(SqStack &s){
    ClearStack(s);
    s.stacksize = 0;
    s.top = s.base = NULL;
}


