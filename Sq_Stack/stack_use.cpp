#include<stdio.h>
#include<stdlib.h>
#include"stack_module.h"
#include"stack_use.h"


//����ת��
#if DT == 1
void conversion(SqStack &s, int n){
    int e;
    while(n!=0){
        Push(s,n%8);
        n = n/8;
    }
    while(s.base!=s.top){
        Pop(s,e);
        printf("%d",e);
    }
}
#endif // DT

int Pi(char c){
    int l = 0;
    switch(c){
        case '[': case ']':l = 1;break;
        case '{': case '}':l = 2;break;
        case '(': case ')':l = 3;break;
        default:break;
    }
    return l;
}

//����ƥ��ļ���
void SymbolCheck(SqStack &s){
    char e,e1,e3;
    for(int a=0;a<7;a++){
        scanf("%c",&e);
        /*
            //scanf() ��������һ���ܵ����ַ�ʱ����ܲ��ɼ��Ļ��з��Ϳո����
            ���Իᵼ�²����Ľ����Ԥ�ڲ���ͬ����
            Ӧ����scanf()���������һ��getchar()���ܲ��ɼ��ַ�;
        */
        getchar();
        GetTop(s,e1);
        if(Pi(e)==Pi(e1)){ //
            Pop(s,e3);
        }else{
            Push(s,e);
        }
    }
    DisStack(s);
}

//�б༭����
void LineEdit(SqStack &s){
    //�����ַ�ջ�����ն˽���һ�в����������ù��̵�������
    SElemType c;
    SElemType ch = getchar(); //���ն˽��յ�һ���ַ�
    while(ch != EOF){ //EOF Ϊȫ�Ľ�����
        while(ch != EOF && ch != '\n'){
            switch(ch){
                case '#': Pop(s,c);break; //����ջ�ǿ�ʱ��ջ
                case '@': ClearStack(s);break; //����sΪ��ջ
                default: Push(s,ch);break; // ��Ч�ַ���ջ��δ����ջ�����
            }
            ch = getchar(); //���ն˽�����һ���ַ�
        }
        /*����ջ�׵�ջ����ջ���ַ����������ù��̵�������*/
        ClearStack(s); //����ջΪ��ջ
        if(ch != EOF){
            ch = getchar();
        }
    }

}
