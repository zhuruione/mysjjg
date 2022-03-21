//
// Created by zr on 2021/11/11.
//

#include <iostream>
#include <malloc.h>

using namespace std;

typedef int Elemtype;

typedef struct QNode {
    Elemtype data;
    QNode *next;
} QNode, *QNodePtr;

typedef struct {
    QNodePtr front;//队头指针
    QNodePtr rear;//队尾指针
} LinkQueue;

//初始化队列
int Init_Queue(LinkQueue &queue) {
    queue.rear = queue.front = (QNodePtr) malloc(sizeof(QNodePtr));
    queue.rear->data = NULL;
    if (!queue.rear) {
        cout << "初始化失败" << endl;
        return 0;
    }
    queue.front->next = NULL;
    return 1;
}

int QueueLength(LinkQueue queue) {
    int n = 0;
    QNodePtr p = queue.front;
    while (p != queue.rear) {
        n++;
        p = p->next;
    }
    return n;
}

//判断队列是否为空
int QueueEmpty(LinkQueue queue) {
    if (queue.front == queue.rear) {
        return 1;
    } else
        return 0;
}

//销毁队列
int DestroyQueue(LinkQueue &queue) {
    while (queue.front) {
        QNodePtr nextnode = queue.front->next;
        free(queue.front);
        queue.front = nextnode;
    }
}

//插入元素作为队尾元素
int EnQueue(LinkQueue &queue, Elemtype e) {
    QNodePtr newnode = (QNodePtr) malloc(sizeof(QNode));
    if (!newnode) {
        cout << "插入失败" << endl;
        return 0;
    }
    newnode->data = e;
    newnode->next = NULL;
    queue.rear->next = newnode;//将队列之前最后一个节点的下一个节点指向当前新建的节点
    queue.rear = newnode;//将队列的最后一个元素改为当前元素
    return 1;

}

int DeQueue(LinkQueue &queue, Elemtype &e) {
    //若队列不为空 则输出头节点元素并删去头节点元素、
    if (QueueEmpty(queue)) {
        return 0;
    }
    if (queue.front->next == queue.rear) {
        e = queue.rear->data;
        free(queue.rear);
       queue.rear=queue.front;
        return 1;
    }

    e = queue.front->next->data;
    QNodePtr front = queue.front->next->next;
    free(queue.front->next);
    queue.front->next = front;
    return 1;

//    QNodePtr delectnode=queue.front->next;
//    queue.front->next=queue.front->next->next;
//    free(delectnode);
//    return 1;


}

int GetHead(LinkQueue queue, Elemtype &e) {
    if (queue.front != queue.rear) {
        e = queue.front->next->data;
        return 1;
    } else {
        return 0;
    }
}


int PrintQueue(LinkQueue queue) {
    QNodePtr p = queue.front;
    while (p != queue.rear) {
        cout << p->next->data << endl;
        p = p->next;
    }
}

//主函数
int main() {

    setbuf(stdout, NULL);
    LinkQueue Q;
    int select;
    Elemtype e;
    if ((Init_Queue(Q)) == 0)
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
            system("cls");
        } while (select);
    }
}
