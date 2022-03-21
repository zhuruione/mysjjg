
#include<stdio.h>    //若用printf,scanf,getchar,putchar,gets,puts函数需包含该头文件
#include<malloc.h>    //用malloc,free,realloc函数需包含该头文件
#include<conio.h>    //若用getch()使得屏幕暂停，需包含该头文件
#include<stdlib.h>
#define MAXSIZE 100        //设线性表初始分配空间大小
#define INSERTSIZE 10;
typedef int ElemType;    //先设定数据元素的类型为整型

//定义顺序表的结构类型
typedef struct {
    ElemType *elem;
    int listsize;
    int length;
} SqList;

//初始化顺序表
int InitList_Sq(SqList &L) {
    L.elem = (ElemType *) malloc(MAXSIZE * sizeof(ElemType));
    if (!L.elem) {
        printf("分配内存失败");
        return 0;
    }
    L.listsize = MAXSIZE;
    L.length = 0;
    return 1;
}

//定位元素
int Location_Sq(SqList L, ElemType e) {
    ElemType *lelem = L.elem;
    for (int n = 0; n <= L.length; n++) {

    }
    return 0;
}

//插入
int ListInsert_Sq(SqList &L, int i, ElemType e) {
    if (i < 0 || i > L.length + 1)
        return 0;
    ElemType *newelem = NULL;
    if (L.length > L.listsize) {
        newelem = (ElemType *) realloc(L.elem, (L.listsize + 10) * sizeof(ElemType));
        if (!newelem)
            return 0;
        L.listsize += INSERTSIZE;
        L.elem = newelem;
    }
    //获取要插入位置的地址
    int *p = &(L.elem[i - 1]);
    //指针-1是指指针所指的地址减去指针的大小
    for (ElemType *a = &(L.elem[L.length - 1]); a >= p; a--) {
        *(a + 1) = *a;
    }
    *p = e;
    L.length++;
    return 1;

}

//删除
int ListDelete_Sq(SqList &L, int i, ElemType &e) {
    while (i < 0 || i > L.length) {
        printf("输入错误");
        scanf("%d", i);
    }
    int *p = &(L.elem[i - 1]);
    e = *p;
    while (*(p + 1) != NULL) {
        *p = *(p + 1);
        p++;
    }
    L.length--;
    return 1;
}

//翻转表
int ReverseList(SqList &L) {
    if (L.length % 2 == 1) {
        int n = 0;
        while (1) {
            if (n == L.length / 2)
                break;
            int eg = *(L.elem + n);
            *(L.elem + n) = *(L.elem + L.length - n - 1);
            *(L.elem + L.length - n - 1) = eg;
            n++;
        }
    } else {
        int n = 0;
        do {
            int eg = *(L.elem + n);
            *(L.elem + n) = *(L.elem + L.length - n - 1);
            *(L.elem + L.length - n - 1) = eg;
            n++;
        } while (n != L.length / 2);
    }

}

//合并两个有序表
int MergeList(SqList La, SqList Lb, SqList &Lc) {
    int *b = Lb.elem;
    int *a = La.elem;
    for (int a = 1; a <= La.length; a++) {
        ListInsert_Sq(Lc, a, *(La.elem + a - 1));
    }

    for (int n = 0; n < Lb.length; n++) {
        int s = *(Lb.elem + n);
        for (int nn = 0; nn < Lc.length; nn++) {
            if (s < *(Lc.elem)) {
                ListInsert_Sq(Lc, 1, s);
                break;
            }
            if (s > *(Lc.elem + Lc.length - 1)) {
                ListInsert_Sq(Lc, Lc.length + 1, s);
                break;
            }
            if (s >= *(Lc.elem + nn) && s < *(Lc.elem + nn + 1)) {
                ListInsert_Sq(Lc, nn + 2, s);
                break;
            }
        }
    }
}
//int MergeList2(SqList La, SqList Lb, SqList& Lc) {
//	for (int a = 0; a < La.length; a++) {
//		for (int b = 0; b < La.length; b++) {
//			if(*(La.elem))
//		}
//	}
//	
//}

//打印表中元素值
int PrintList(SqList &L) {
    int i;
    for (i = 0; i < L.length; i++)
        printf("%d\n", L.elem[i]);
}

//主函数
int main() {
    setbuf(stdout,NULL);
    SqList La, Lb, Lc;
    int i, n, e;

    //创建第一个表
    printf("1. 建第一个表 \n");
    InitList_Sq(La);
    printf("请输入要往La表中插入元素的个数：");
    scanf("%d", &n);
    printf("输入%d个递增有序的整数：\n", n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &e);
        ListInsert_Sq(La, i, e);
    }
    printf("La表长为：%d\n", La.length);
    PrintList(La);
    system("pause"); //屏幕暂停，等候按任何键继续

    //删除
    printf("\n2.删除\n");
    printf("请输入要删除元素的位置：");
    scanf("%d", &i);
    ListDelete_Sq(La, i, e);
    printf("被删除的元素是：%d\n", e);
    printf("删除后La表：\n");
    PrintList(La);
    printf("La表表长为：%d\n", La.length);

    //插入数据
    printf("\n插入数据");
    printf("请输入要插入数据的位置");
    scanf("%d", &i);
    printf("请输入要输入的数据");
    scanf("%d", &e);
    ListInsert_Sq(La, i, e);
    printf("插入后表为：");
    PrintList(La);
    printf("插入后表长为%d", La.length);

    //创建第二个表
    printf("\n3.建第二个表\n");
    InitList_Sq(Lb);
    printf("请输入要往Lb表中插入元素的个数：");
    scanf("%d", &n);
    printf("输入%d个递增有序的整数：\n", n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &e);
        ListInsert_Sq(Lb, i, e);
    }
    printf("Lb表长为：%d\n", Lb.length);
    system("pause");

    //合并有序表
    printf("\n4. 合并有序表，将La,Lb表中元素合并到Lc表中，仍保持有序。\n");
    InitList_Sq(Lc);
    MergeList(La, Lb, Lc);
    printf("合并有序表后，Lc表元素为：\n");
    PrintList(Lc);
    printf("合并有序表后，Lc表表长为：%d", Lc.length);
    system("pause");

    //翻转表
    printf("\n5. 翻转Lc表\n");
    ReverseList(Lc);
    printf("翻转Lc表后，Lc表元素为：\n");
    PrintList(Lc);
    system("pause");
}
