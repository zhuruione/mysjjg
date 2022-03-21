//
// Created by zr on 2021/11/10.
//

#ifndef MYHOMEWORK_TOOLS_H
#define MYHOMEWORK_TOOLS_H


#define MAXSIZE 100
#define STACKINCREMENT 10
typedef char ElemType;
typedef struct STACK {
    ElemType *base;
    ElemType *top;
    int stacksize;

} SqStack;


class tools {
public:
    //构造函数
    tools();
    ~tools();

    int InitStack(SqStack &s);

    void ClearStack(SqStack &S);

    int StackEmpty(SqStack S);

    int StackLength(SqStack S);

    int GetTop(SqStack s, ElemType &e);

    int Push(SqStack &s, ElemType e);

    int Pop(SqStack &s, ElemType &e);

    void PrintElem(SqStack S);
};


#endif //MYHOMEWORK_TOOLS_H
