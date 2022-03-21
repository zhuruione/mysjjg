//
// Created by zr on 2021/11/10.
//

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "tools.h"

using namespace std;

tools::tools() {
    printf("创建了工具类对象\n");
}

tools::~tools() {
    printf("删除了工具类对象\n");
}

//初始化栈
int tools::InitStack(SqStack &s) {
    printf("初始化栈\n");
    s.base = (ElemType *) malloc(sizeof(ElemType));
    if (!s.base)
        return 0;
    s.top = s.base;
    s.stacksize = MAXSIZE;
    return 1;
}

//清空栈
void tools::ClearStack(SqStack &S) {
    if (S.base)
        S.top = S.base;
}

//判栈空
int tools::StackEmpty(SqStack S) {
    if (S.base != S.top)
        //栈不为空
        return 1;
    else
        //头节点和尾节点相同 栈为空
        return 0;
}

//求栈中元素个数
int tools::StackLength(SqStack S) {
    return S.top - S.base;
}

//获取栈顶元素值
int tools::GetTop(SqStack s, ElemType &e) {
    if (StackEmpty(s)) {
        e = *(s.top - 1);
        return 1;
    }else{
        return 0;
    }
}

//入栈
int tools::Push(SqStack &s, ElemType e) {
    //如果栈满则追加新的空间
    if (s.top - s.base >= s.stacksize) {
        s.base = (ElemType *) realloc(s.base, (s.stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (!s.base)
            return 0;
        s.top += s.stacksize;
        s.stacksize += STACKINCREMENT;
    }
    //将e的值赋到s.top节点中  并将s.top节点上移一个单位
    //先计算是s.top=e  然后是s.top++
    *s.top++ = e;
}

//出栈
int tools::Pop(SqStack &s, ElemType &e) {
    if (s.top != s.base) {
        e = *--s.top;
        return e;
    } else
        return NULL;

}

//打印栈中元素
void tools::PrintElem(SqStack S) {
    ElemType *p = S.base;
    while (p < S.top) {
        std::cout<<*p<<endl;
        p++;
    }
}

