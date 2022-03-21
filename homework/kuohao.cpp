//
// Created by zr on 2021/11/10.
//
#include <iostream>

using namespace std;

#include "../tool/tools.h"

int main() {
    //创建了栈的工具类
    tools *t = new tools;
    SqStack stack;
    t->InitStack(stack);
    char kh[20];
    cin.get(kh, 20);
    for (int n = 0; kh[n]; n++) {
        if(kh[n]=='['||kh[n]=='('){
            t->Push(stack,kh[n]);
        }
        if(kh[n]==']'||kh[n]==')'){
            if(!t->StackEmpty(stack)){
                cout<<"不匹配"<<endl;
                exit(0);
            }

            ElemType l;
            t->Pop(stack,l);
            if(l=='['){
                if(kh[n]!=']'){
                    cout<<"不匹配"<<endl;
                    exit(0);
                }
            }
            if(l=='('){
                if(kh[n]!=')'){
                    cout<<"不匹配"<<endl;
                    exit(0);
                }
            }

        }
    }
    cout<<"匹配成功"<<endl;
}
