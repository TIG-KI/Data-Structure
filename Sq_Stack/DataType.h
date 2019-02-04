#define DT  0

#if DT == 1
typedef int SElemType;
typedef int Status;
#else
typedef char SElemType;
typedef int Status;
#endif // DT

/*
    如果 #if 指令后的参数表达式为为真，则编译#if到#else 之间的程序段，否则编译 #else 到#endif
    之间的代码段
*/
