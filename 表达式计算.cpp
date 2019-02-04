//符号优先级比较
char SymbolCompare(char a,char b){
    char flag;
    switch(a){
        case '+':
            switch(b){
                case '+':case '-':case ')':case '#':flag='>';break;
                case '*':case '/':case '(':flag='<';break;
            }
            break;
        case '-':
            switch(b){
                case '+':case '-':case ')':case '#':flag='>';break;
                case '*':case '/':case '(':flag='<';break;
            }
            break;
        case '*':
            switch(b){
                case '+':case '-':case '*':case '/':case ')':case '#':flag='>';break;
                case '(':flag='<';break;
            }
            break;
        case '/':
            switch(b){
                case '+':case '-':case '*':case '/':case ')':case '#':flag='>';break;
                case '(':flag='<';break;
            }
            break;
        case '(':
            switch(b){
                case '+':case '-':case '*':case '/':case '(':flag='<';break;
                case ')':flag='=';break;
                case '#':flag=NULL;break;
            }
            break;
        case ')':
            switch(b){
                case '+':case '-':case '*':case '/':case ')':case '#':flag='>';break;
                case '(':flag=NULL;break;
            }
            break;
        case '#':
            switch(b){
                case '+':case '-':case '*':case '/':case '(':flag='<';break;
                case ')':flag=NULL;break;
                case '#':flag='=';break;
            }
            break;
        default:
            break;
    }
    return flag;
}

//输入判断
int In(char c){
    char str1[]={'+','-','*','/','(',')','#'};
    int i = 0;
    while(i<7){
        if(c == str1[i]){
            return 1;
        }
        i++;
    }
    return 0;
}

//计算
int Operate(int a,char c,int b){
    int sum = -1;
    switch(c){
        case '+':
            sum = a+b;break;
        case '-':
            sum = a-b;break;
        case '*':
            sum = a*b;break;
        case '/':
            sum = a/b;break;
        default:
            break;
    }
    return sum;
}