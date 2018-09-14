#include<stdio.h>
#include<stdlib.h>
#include "method.h" //包含头文件

//链表的初始化
void InitList(Sqlist *&L)
{
    L = (Sqlist*)malloc(sizeof(Sqlist));
    if(!L->elem)
    {
        return exit(1);
    }
    L->length = 0;
}

//链表的创建
void ListCreated(Sqlist *&L, ElemType *a, int n)
{
    int i;
    //L.elem = new ElemType[MAXSIZE];
    L = (Sqlist *)malloc(sizeof(Sqlist));
    for(i=0;i<n;i++)
    {
        L->elem[i]=a[i];
    }
    L->length=n;
}

//链表的展示
void DisList(Sqlist *L)
{
    int i;
    printf("{");
    for(i=0;i<L->length;i++)
    {
        if(i==L->length-1)
        {
            printf("%d ",L->elem[i]);
        }
        else if(i==0)
        {
            printf(" %d, ",L->elem[i]);
        }
        else
        {
            printf("%d, ",L->elem[i]);
        }
    }
    printf("}\n");

}

//顺序表的取值
bool GetElem(Sqlist *L, int i, ElemType &e) //&e是对实参的引用，这样在改变形参的同时才会改变实参的的值
{
    if(i<1||i>L->length)
    {
        return ERROR;
    }
    e=L->elem[i-1];

    return true;
}

//顺序表的查找
status LocatedElem(Sqlist *L, ElemType e)
{
    //在顺序表中查找值为e的元素，返回其号
    int i;
    for(i=0;i<L->length;i++)
    {
        if(L->elem[i]==e)
        {
            //return i+1;
            return OK;
        }
    }

    return 0; //查找失败返回0
}

//顺序表的插入
int ListInsert(Sqlist *&L, ElemType e, int i)
{
    //将数组插入到链表指定位置
    int j;
    if(i<1||i>L->length+1)
    {
        return ERROR;
    }
    if(L->length==MAXSIZE)
    {
        return ERROR; //当前储存空间已满
    }
    for(j=L->length;j>i-1;j--)
    {
        L->elem[j]=L->elem[j-1]; //将第i歌元素后面的所有元素向后移动
    }
    L->elem[i-1] = e;
    L->length++;

    return OK;
}

//顺序表的删除
int ListDelete(Sqlist *&L, int i)
{
    int j;
    //删除链表指定位置上的元素
    if(i<1||i>L->length)
    {
        return ERROR;
    }
    //将位置i以后的元素向前移动
    for(j=i;j<L->length-1;j++)
    {
        L->elem[j-1]=L->elem[j];
    }
    L->length--;

    return OK;
}

//计算顺序表的长度
int ListLength(Sqlist *L)
{
    return (L->length);
}

//线性表的合并
void MergeList(Sqlist *LA,Sqlist *LB)
{
    //将所有在线性表LB但不在LA中的数据元素插入到LA中
    int i;
    int e;
    int m = ListLength(LA),n = ListLength(LB);
    for(i=1;i<=n;i++)
    {
        GetElem(LB,i,e);
        if(!LocatedElem(LA,e))
        {
            ListInsert(LA,e,++m);//先对m加1在进行运算，如果是m++则是先进行运算再对m的值进行运算与理论结果不相符
        }
    }
}

//顺序有序表的合并
void MergeList_sq(Sqlist *LA, Sqlist *LB, Sqlist *&LC)
{
    //已知顺序有序表LA和LB 的元素 按值非递减排列
    //归并LA和LB的到新的顺序表LC,LC的元素也按值非递减排列

    //初始化LC创建一个length==0的空表
    InitList(LC);
    //创建分别指向各表的第一个元素的指针
    int *pc = LC->elem;
    int *pa = LA->elem;
    int *pb = LB->elem;

    //创建指向LA，LB最末尾元素的指针
    int *pa_last = LA->elem + (LA->length-1);
    int *pb_last = LB->elem + (LB->length-1);

    //将LA，LB相应元素进行对比，并将较小的值插入LC中
    while((pa<=pa_last)&&(pb<=pb_last))
    {
        if(*pa<*pb)
        {
            *pc++=*pa++;
            LC->length++;
        }
        else
        {
            *pc++=*pb++;
            LC->length++;
        }
    }

    //将有剩余的顺序表的剩下部分依次插入LC中
    while(pa<=pa_last)
    {
        *pc++=*pa++;
        LC->length++;
    }
    while(pb<=pb_last)
    {
        *pc++=*pb++;
        LC->length++;
    }

}

