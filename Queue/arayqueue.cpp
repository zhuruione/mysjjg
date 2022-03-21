
#include <stdio.h>
#include <malloc.h>
#include <iostream>

using namespace std;

#define MAXQSIZE 4    //最大队列长度，实际使用MAXQSIZE-1
typedef int ElemType;

//循环队列(少用一个存储单元)
typedef struct {
    ElemType *base;
    int front;
    int rear;
} SqQueue;

//构造一个空队列Q
int InitQueue(SqQueue &Q) {
    Q.base=(ElemType *)malloc(sizeof (ElemType)*MAXQSIZE);
    if(!Q.base){
        cout<<"初始化失败"<<endl;
        return 0;
    }
    cout<<"初始化成功"<<endl;
    Q.front=Q.rear=0;
    return 1;
}

//队列判空，若队列Q为空队列，则返回1，否则返回0
int QueueEmpty(SqQueue &Q) {
    if(Q.front==Q.rear)
        return 1;
    else
        return 0;
}

//求队列的长度
int QueueLength(SqQueue &Q) {
    return (Q.rear+MAXQSIZE-Q.front)%MAXQSIZE;
}

//求队头元素值，若队列不为空，则用e返回Q的队头元素，并返回1；否则返回0
int GetHead(SqQueue &Q, ElemType &e) {
    if(Q.rear!=Q.front){
        e=Q.front;
        return 1;
    }else
        return 0;
}

//插入元素e作为Q的新的队尾元素\
//入队
int EnQueue(SqQueue &Q, ElemType e) {
    if((Q.rear+1)%MAXQSIZE!=Q.front){
        Q.base[Q.rear]=e;
        //如果大于数组的下标则会从零开始
        Q.rear=(Q.rear+1)%MAXQSIZE;
        return 1;
    } else{
        return 0;
    }
}

//若队列不空，则删除Q的队头元素，用e返回其值，并返回1,否则返回0
//出队
int DeQueue(SqQueue &Q, ElemType &e) {
    if(Q.rear==Q.front)
        return 0;
    else{
        e=Q.base[Q.front];
        Q.front=(Q.front+1)%MAXQSIZE;
        return 1;
    }
}

//输出队列中元素值,从头到尾
void PrintQueue(SqQueue &Q) {
    int n=Q.front;
    while(n!=Q.rear){
        cout<<Q.base[n]<<endl;
        n=(n+1)%MAXQSIZE;
    }
}

//主函数
int main() {
    setbuf(stdout,NULL);
    SqQueue Q;
    int select;
    ElemType e;
    if ((InitQueue(Q)) == 0)
        printf("分配失败，即将退出程序！\n");
    else {
        do {
            printf("\n1：判断队列是否为空\n");
            printf("2：求队列长度\n");
            printf("3：取队头元素值\n");
            printf("4：入队\n");
            printf("5：出队\n");
            printf("6：显示队中元素\n");
            printf("0：结束\n\n");
            printf("请输入您的选择：");
            scanf("%d", &select);
            switch (select) {
                case 1:
                    if (QueueEmpty(Q) == 1)
                        printf("队列为空\n");
                    else
                        printf("队列不为空\n");
                    break;
                case 2:
                    printf("队列长度为：%d\n", QueueLength(Q));
                    break;
                case 3:
                    if (GetHead(Q, e) == 0)
                        printf("队列为空\n");
                    else
                        printf("队首元素为：%d\n", e);
                    break;
                case 4:
                    printf("请输入要插入的元素值：");
                    scanf("%d", &e);
                    if (EnQueue(Q, e) == 0)
                        printf("队列满，插入失败\n");
                    else
                        printf("元素成功插入\n");
                    break;
                case 5:
                    if (DeQueue(Q, e) == 0)
                        printf("队列空，无数据可删\n");
                    else
                        printf("删除元素为：%d\n", e);
                    break;
                case 6:
                    PrintQueue(Q);
                    break;
                case 0:
                    printf("操作结束\n");
                    break;
                default:
                    printf("输入选择出错！\n");
            }
        } while (select);
    }
}