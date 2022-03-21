
#include<stdio.h>        //若用printf,scanf,getchar,putchar,gets,puts函数需包含该头文件
#include<malloc.h>        //用malloc,free,realloc函数需包含该头文件


typedef int ElemType;    //先设定数据元素的类型为整型

//定义类型
typedef struct LNode {
    ElemType data;
    LNode *next;

} LNode, *LinkList;

//求表长
int ListLength(LinkList L) {
    LinkList p = L;
    int n = 0;
    while (p->next != NULL) {
        n++;
        p = p->next;
    }

    return n;
}

//查找元素，获取表中第i个元素的值
int GetElem(LinkList L, int i, ElemType &e) {

    LNode *p = L->next;
    int j = 1;            //p指向第一个结点，j为计数器
    while (p && j < i)    //顺指针向后查找，直到p指向第i个元素或p为空
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return 0;        //第i个元素不存在
    e = p->data;        //取得第i个元素
    return 1;
}

//判断元素e是否在该链表中
int LocateElem(LinkList La, ElemType e) {
    int n = 0;
    LinkList p = La->next;
    if (p == NULL) {
        return 0;
    }
    while (1) {
        n++;
        if (p->data == e) {
            return n;
        }
        if (p->next != NULL) {
            p = p->next;
        } else {
            break;
        }
    }
    return n;
}

//打印表中元素值
int PrintList(LinkList L) {
    LinkList nownode = L->next;
    if (nownode == NULL) {
        printf("表为空");
        return 1;
    }
    printf("表中元素为:");
    while (1) {
        printf("%d   ", nownode->data);
        if (nownode->next != NULL) {
            nownode = nownode->next;
        } else {
            break;
        }
    }
}

//插入操作
int ListInsert(LinkList &L, int i, ElemType e) {
    LinkList p = L;
    for (int a = 1; a < i; a++) {
        p = p->next; //找出这个次序的节点的上一个节点;
    }
    LinkList nextnode = p->next;
    p->next = (LinkList) malloc(sizeof(LNode));
    p->next->data = e;
    p->next->next = nextnode;
    return 1;
}

//删除操作
int ListDelete(LinkList &L, int i, ElemType &e) {
    LinkList p = L;
    for (int a = 1; a < i; a++) {
        p = p->next; //找出这个次序的节点的上一个节点;
    }
    LinkList delect = p->next;
    e = delect->data;
    p->next = p->next->next;
    free(delect);
    return 1;
}

//尾插法建表
int CreateListwei(LinkList &L, int n) {
    while (n < 1) {
        printf("表厂不可以为0");
        scanf("%d", n);
    }
    L = (LinkList) malloc(sizeof(LNode));
    printf("请输入值：");
    scanf("%d", &L->data);
    LinkList nownode = L;
    if (n > 1) {
        for (int a = 1; a < n; a++) {
            nownode->next = (LinkList) malloc(sizeof(LNode));
            nownode = nownode->next;
            printf("请输入值：");
            scanf("%d", &nownode->data);

        }
    }


}

//头插法建表
int CreateList(LinkList &L, int n) {
    L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    while (n < 1) {
        printf("表厂不可以为0");
        scanf("%d", n);
    }
    LinkList p = NULL;
    printf("请输入值：");
    for (int a = 0; a < n; a++) {
        p = (LinkList) malloc(sizeof(LNode));
        printf("请输入值：");
        scanf("%d", &p->data);
        p->next = L->next; //将新节点的下一个存放为头节点指的值
        L->next = p;
    }


    /*scanf("%d", &L->data);
    L->next = NULL;
    LinkList nownode = L;
    if (n > 1) {
        for (int a = 1; a < n; a++) {
            L = (LinkList)malloc(sizeof(LNode));
            printf("请输入值：");
            scanf("%d", &L->data);
            L->next = nownode;
            nownode = L;
        }
    }*/


}

//合并两个有序表
int MergeList(LinkList La, LinkList Lb, LinkList &Lc) {
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    LinkList pc;
    Lc = pc = La;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(Lb);
}

//主函数
int main() {
    setbuf(stdout,NULL);
    LinkList La;
    ElemType e;
    int i, n;

    //创建第一个表
    printf("1.建第一个表 \n");
    printf("请输入要往La表中插入元素的个数：");
    scanf("%d", &n);
    printf("输入%d个元素值：(头插法建表，请逆序输入)\n", n);
    CreateList(La, n);
    PrintList(La);
    printf("表长为：%d\n", ListLength(La));

    //取值
    printf("\n2.查找第i位元素的值\n请输入位序：");
    scanf("%d", &n);
    if (n <= ListLength(La)) {
        GetElem(La, n, e);
        printf("第%d位元素的值为：%d\n", n, e);
    } else
        printf("表长只有%d", ListLength(La));


    //定位
    printf("\n3.定位操作\n请输入要查找的元素:");
    scanf("%d", &e);
    i = LocateElem(La, e);
    if (i)
        printf("所要查找的元素在表中第%d位\n", i);
    else
        printf("表中无该元素\n");

    //插入
    printf("\n4.插入操作\n输入要插入元素的位序：");
    scanf("%d", &i);
    printf("输入要插入的元素值：");
    scanf("%d", &e);
    ListInsert(La, i, e);
    printf("插入后表中元素为：\n");
    PrintList(La);

    //删除
    printf("\n5.删除操作\n输入要删除元素的位序：");
    scanf("%d", &n);
    ListDelete(La, n, e);
    printf("要删除的元素值为：%d\n", e);
    printf("删除后表中元素为：\n");
    PrintList(La);

    //建立第二个表
    LinkList Lb, Lc;
    printf("\n6.建第二个表\n");
    printf("请输入Lb表中元素个数:");
    scanf("%d", &n);
    printf("输入%d个元素值：(头插法建表，请逆序输入)\n", n);
    CreateList(Lb, n);
    printf("表中元素为：\n");
    PrintList(Lb);

    //合并
    printf("\n7.合并两个有序表：\n");
    MergeList(La, Lb, Lc);
    printf("合并后Lc表中元素为：\n");
    PrintList(Lc);
}




