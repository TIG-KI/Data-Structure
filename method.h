#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2

//结构声明
struct LinkList
{
    int  elem[MAXSIZE];
    int length;
};

//类型定义
typedef struct LinkList Sqlist;
typedef int status;
typedef int ElemType;


extern void InitList(Sqlist *&L);
extern void ListCreated(Sqlist *&L, ElemType *a, int n);
extern  void DisList(Sqlist *L);
extern bool GetElem(Sqlist *L, int i, ElemType &e);
extern status LocatedElem(Sqlist *L, ElemType e);
extern int ListInsert(Sqlist *&L, ElemType e, int i);
extern int ListDelete(Sqlist *&L, int i);
extern int ListLength(Sqlist *L);
extern void MergeList(Sqlist *LA,Sqlist *LB);
extern void MergeList_sq(Sqlist *LA, Sqlist *LB, Sqlist *&LC);
