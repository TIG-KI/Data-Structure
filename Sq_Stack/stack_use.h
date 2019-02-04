#ifndef STACK_USE
#endif  // STACK_USE

extern void conversion(SqStack &s, int n);
void SymbolCheck(SqStack &s);

/*
    #ifdef 宏替换名
    语句段  //如果宏替换名已经被定义了，则对语句段进行编译，如果未被定义则对语句段不进行编译
    #endif

    #ifndef 宏替换名
    语句段 //如果未定指令后的宏替换名则对后面的语段进行编译，否则不对后面的语段进行编译
    #endif

    #ifndef 用于处理头文件中，防止对文件内容进行多次编译
*/
