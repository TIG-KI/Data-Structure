#include<stdio.h>
#include<stdlib.h>
#include "method.h" //����ͷ�ļ�

//����ĳ�ʼ��
void InitList(Sqlist *&L)
{
    L = (Sqlist*)malloc(sizeof(Sqlist));
    if(!L->elem)
    {
        return exit(1);
    }
    L->length = 0;
}

//����Ĵ���
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

//�����չʾ
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

//˳����ȡֵ
bool GetElem(Sqlist *L, int i, ElemType &e) //&e�Ƕ�ʵ�ε����ã������ڸı��βε�ͬʱ�Ż�ı�ʵ�εĵ�ֵ
{
    if(i<1||i>L->length)
    {
        return ERROR;
    }
    e=L->elem[i-1];

    return true;
}

//˳���Ĳ���
status LocatedElem(Sqlist *L, ElemType e)
{
    //��˳����в���ֵΪe��Ԫ�أ��������
    int i;
    for(i=0;i<L->length;i++)
    {
        if(L->elem[i]==e)
        {
            //return i+1;
            return OK;
        }
    }

    return 0; //����ʧ�ܷ���0
}

//˳���Ĳ���
int ListInsert(Sqlist *&L, ElemType e, int i)
{
    //��������뵽����ָ��λ��
    int j;
    if(i<1||i>L->length+1)
    {
        return ERROR;
    }
    if(L->length==MAXSIZE)
    {
        return ERROR; //��ǰ����ռ�����
    }
    for(j=L->length;j>i-1;j--)
    {
        L->elem[j]=L->elem[j-1]; //����i��Ԫ�غ��������Ԫ������ƶ�
    }
    L->elem[i-1] = e;
    L->length++;

    return OK;
}

//˳����ɾ��
int ListDelete(Sqlist *&L, int i)
{
    int j;
    //ɾ������ָ��λ���ϵ�Ԫ��
    if(i<1||i>L->length)
    {
        return ERROR;
    }
    //��λ��i�Ժ��Ԫ����ǰ�ƶ�
    for(j=i;j<L->length-1;j++)
    {
        L->elem[j-1]=L->elem[j];
    }
    L->length--;

    return OK;
}

//����˳���ĳ���
int ListLength(Sqlist *L)
{
    return (L->length);
}

//���Ա�ĺϲ�
void MergeList(Sqlist *LA,Sqlist *LB)
{
    //�����������Ա�LB������LA�е�����Ԫ�ز��뵽LA��
    int i;
    int e;
    int m = ListLength(LA),n = ListLength(LB);
    for(i=1;i<=n;i++)
    {
        GetElem(LB,i,e);
        if(!LocatedElem(LA,e))
        {
            ListInsert(LA,e,++m);//�ȶ�m��1�ڽ������㣬�����m++�����Ƚ��������ٶ�m��ֵ�������������۽�������
        }
    }
}

//˳�������ĺϲ�
void MergeList_sq(Sqlist *LA, Sqlist *LB, Sqlist *&LC)
{
    //��֪˳�������LA��LB ��Ԫ�� ��ֵ�ǵݼ�����
    //�鲢LA��LB�ĵ��µ�˳���LC,LC��Ԫ��Ҳ��ֵ�ǵݼ�����

    //��ʼ��LC����һ��length==0�Ŀձ�
    InitList(LC);
    //�����ֱ�ָ�����ĵ�һ��Ԫ�ص�ָ��
    int *pc = LC->elem;
    int *pa = LA->elem;
    int *pb = LB->elem;

    //����ָ��LA��LB��ĩβԪ�ص�ָ��
    int *pa_last = LA->elem + (LA->length-1);
    int *pb_last = LB->elem + (LB->length-1);

    //��LA��LB��ӦԪ�ؽ��жԱȣ�������С��ֵ����LC��
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

    //����ʣ���˳����ʣ�²������β���LC��
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

