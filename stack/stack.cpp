#include<stdio.h>    //若用printf,scanf,getchar,putchar,gets,puts函数需包含该头文件
#include<malloc.h>    //用malloc,free,realloc函数需包含该头文件
#include<conio.h>    //若用getch()使得屏幕暂停，需包含该头文件

#define MAXSIZE 100
#define STACKINCREMENT 10

typedef int ElemType;

typedef struct STACK {
    ElemType *base;
    ElemType *top;
    int stacksize;

} SqStack;

//函数声明
int InitStack(SqStack &s);

void ClearStack(SqStack &S);

int StackEmpty(SqStack S);

int StackLength(SqStack S);

int GetTop(SqStack s, ElemType &e);

int Push(SqStack &s, ElemType e);

int Pop(SqStack &s, ElemType &e);

//初始化,创建空栈
int InitStack(SqStack &s) {
    s.base=(ElemType *)malloc(sizeof(ElemType));
    if(!s.base)
        return 0;
    s.top=s.base;
    s.stacksize=MAXSIZE;
    return 1;
}

//清空栈
void ClearStack(SqStack &S) {
    if (S.base)
        S.top = S.base;
}

//判栈空
int StackEmpty(SqStack S) {
    if(S.base!=S.top)
        //栈不为空
        return 1;
    else
        //头节点和尾节点相同 栈为空
        return 0;
}

//求栈中元素个数
int StackLength(SqStack S) {
    return S.top-S.base;
}

//获取栈顶元素值
int GetTop(SqStack s, ElemType &e) {
    //请完善代码......
    return 1;
}

//入栈
int Push(SqStack &s, ElemType e) {
    //如果栈满则追加新的空间
   if(s.top-s.base>=s.stacksize){
       s.base=(ElemType*) realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof (ElemType));
       if(!s.base)
           return 0;
       s.top+=s.stacksize;
       s.stacksize+=STACKINCREMENT;
   }
   //将e的值赋到s.top节点中  并将s.top节点上移一个单位
   //先计算是s.top=e  然后是s.top++
   *s.top++=e;
}

//出栈
int Pop(SqStack &s, ElemType &e) {
    if(s.top!=s.base){
        e=*--s.top;
        return e;
    }else
        return NULL;

}

//打印栈中元素
void PrintElem(SqStack S) {
    ElemType *p = S.base;
    while (p < S.top) {
        printf("%d\n", *p);
        p++;
    }
}

//数制转换函数
void conversion() {
    ElemType e;
    SqStack S;
    InitStack(S);

    int n, R = 8;
    printf("请输入需要被转换的十进制数：");
    scanf("%d", &n);
    printf("请输入被转换成的R进制（2<=R<=10）：");
    scanf("%d", &R);
    //转换操作…
    while(n){
        Push(S,n%R);
        n=n/R;
    }
    //输出转换后的数…
    while (StackEmpty(S)) {
        Pop(S, e);
        printf("%d", e);
    }
    printf("\n");
}

//主函数
int main() {
    setbuf(stdout,NULL);
    ElemType e;
    SqStack S;

    printf("1.初始化栈\n");
    InitStack(S);
    printf("现在栈为空.\n");
    printf("请输入第一个要入栈的元素值：");
    scanf("%d", &e);
    Push(S, e);
    printf("现在栈中有一个元素：\n");
    PrintElem(S);
    printf("请输入第二个要入栈的元素值：");
    scanf("%d", &e);
    Push(S, e);
    printf("现在栈中有两个元素：\n");
    PrintElem(S);

    int n;
    printf("请输入还要入栈的元素的个数:");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("请输入第%d个元素：", i + 2);
        scanf("%d", &e);
        Push(S, e);
    }
    printf("现在栈中元素有：%d个\n", StackLength(S));
    printf("现在栈中元素为：\n");
    PrintElem(S);

    printf("2.现在出栈\n出栈前栈顶元素为：");
    Pop(S, e);
    printf("%d\n", e);
    GetTop(S, e);
    printf("出栈后新的栈顶元素为：%d\n", e);
    printf("栈中剩余元素有：\n");
    PrintElem(S);
    printf("现在栈中元素个数为：%d\n", StackLength(S));

    printf("\n3.数制转换\n");
    conversion();
}
