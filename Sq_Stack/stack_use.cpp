#include<stdio.h>
#include<stdlib.h>
#include"stack_module.h"
#include"stack_use.h"


//进制转换
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

//括号匹配的检验
void SymbolCheck(SqStack &s){
    char e,e1,e3;
    for(int a=0;a<7;a++){
        scanf("%c",&e);
        /*
            //scanf() 函数在逐一接受单个字符时会接受不可见的换行符和空格符，
            所以会导致产生的结果与预期不相同所以
            应该在scanf()函数后添加一个getchar()接受不可见字符;
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

//行编辑程序
void LineEdit(SqStack &s){
    //利用字符栈，从终端接收一行并传送至调用过程的数据区
    SElemType c;
    SElemType ch = getchar(); //从终端接收第一个字符
    while(ch != EOF){ //EOF 为全文结束符
        while(ch != EOF && ch != '\n'){
            switch(ch){
                case '#': Pop(s,c);break; //仅当栈非空时退栈
                case '@': ClearStack(s);break; //重置s为空栈
                default: Push(s,ch);break; // 有效字符进栈，未考虑栈满情况
            }
            ch = getchar(); //从终端接收下一个字符
        }
        /*将从栈底到栈顶的栈内字符传送至调用过程的数据区*/
        ClearStack(s); //重置栈为空栈
        if(ch != EOF){
            ch = getchar();
        }
    }

}
