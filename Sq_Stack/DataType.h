#define DT  0

#if DT == 1
typedef int SElemType;
typedef int Status;
#else
typedef char SElemType;
typedef int Status;
#endif // DT

/*
    ��� #if ָ���Ĳ������ʽΪΪ�棬�����#if��#else ֮��ĳ���Σ�������� #else ��#endif
    ֮��Ĵ����
*/
