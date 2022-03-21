
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef char ElemType;	//定义二叉树结点值的类型为字符型
const int MaxLength=10;	//结点个数不超过10个

int LEAFCOUNT=0;
int NODECOUNT=0;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

void CreateBiTree(BiTree &T)//按先序次序输入，以特殊字符表示空树
{
    char newchar;
    scanf("%c",&newchar);
    getchar();
    if(newchar==' '){
        T=NULL;
        return;
    }else{
        T=(BiTree) malloc(sizeof (BiTNode));
        T->data=newchar;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }

}

void PreOrderTraverse(BiTree T)//先序遍历
{


    if(T){
        if(!T->lchild&&!T->rchild){
            printf("###%c#####",T->data);
        }
        printf("%c  ",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverse(BiTree T)//中序遍历
{
    if(T){
       InOrderTraverse(T->lchild);
        printf("%c  ",T->data);
        InOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse(BiTree T)//后序遍历
{
    if(T){
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c  ",T->data);
    }
}

void LevelOrderTraverse(BiTree T)//层序遍历
{
    BiTree stack[MaxLength];
    int front=0,rear=0;
    //将树根入队
    stack[rear]=T;
    rear=(rear+1)%MaxLength;
    BiTree nownode;
    if(T){
        //循环结束条件为队列中没有元素可以出队
        while (front!=rear){
            //出队
            nownode=stack[front];
            front=(front+1)%MaxLength;
            printf("%c",nownode->data);
            if(nownode->lchild){
                stack[rear]=nownode->lchild;
                rear=(rear+1)%MaxLength;
            }
            if(nownode->rchild){
                stack[rear]=nownode->rchild;
                rear=(rear+1)%MaxLength;
            }
        }

    }

//    BiTree Q[MaxLength];
//    int front=0,rear=0;
//    BiTree p;
//    if(T)				//根结点入队
//    {
//        Q[rear]=T;
//        rear=(rear+1)%MaxLength;
//    }
//    while(front!=rear)
//    {
//        p=Q[front];		//队头元素出队
//        front=(front+1)%MaxLength;
//        printf("%c ",p->data);
//        if(p->lchild)  //左孩子不为空，入队
//        {
//            Q[rear]=p->lchild;
//            rear=(rear+1)%MaxLength;
//        }
//        if(p->rchild) //右孩子不为空，入队
//        {
//            Q[rear]=p->rchild;
//            rear=(rear+1)%MaxLength;
//        }
//    }
}

void NRPreOrder(BiTree bt){//非递归的先序遍历算法
    BiTree stack[MaxLength];
    int top=0;
    if(!bt)
    {
        printf("空树!\n");
        return;
    }
    while(bt || top!=0)
    {
        while(bt)
        {
            stack[top++] = bt;
            printf("%c ",bt->data);
            bt=bt->lchild;
        }
        bt=stack[--top];
        bt=bt->rchild;
    }
}

void NRInOrder(BiTree bt)//非递归的中序遍历算法
{
    BiTree stack[MaxLength];
    int top=0;
    if(!bt)
    {
        printf("空树!\n");
        return;
    }
    while (bt||top!=0){
        while (bt){
            stack[top++]=bt;
            bt=bt->lchild;
        }
        bt=stack[--top];
        printf("%c",stack[top]->data);
        bt=bt->rchild;
    }

}

/*非递归的后序遍历算法
bt是要遍历树的根指针，后序遍历要求在遍历完左右子树后，再访问根。需要判断根结点的左右子树是否均遍历过。
可采用标记法，结点入栈时，配一个标志tag一同入栈(1：遍历左子树前的现场保护，2：遍历右子树前的现场保护)。
首先将bt和tag(为1)入栈，遍历左子树；返回后，修改栈顶tag为2，遍历右子树；最后访问根结点。*/
typedef struct
{
    BiTree ptr;
    int tag;
}stacknode;

void NRPostOrder(BiTree bt)//非递归的后序遍历算法
{
    stacknode s[MaxLength],x;
    BiTree p=bt;
    int top;
    if(bt!=NULL){
        top=0;
        p=bt;
        do{
            while (p!=NULL)//遍历左子树
            {
                s[top].ptr = p;
                s[top].tag = 1;			//标记为左子树
                top++;
                p=p->lchild;
            }
            while (top>0 && s[top-1].tag==2)
            {
                x = s[--top];
                p = x.ptr;
                printf("%c ",p->data);	//tag为R，表示右子树访问完毕，故访问根结点
            }
            if (top>0)
            {
                s[top-1].tag =2;		//遍历右子树
                p=s[top-1].ptr->rchild;
            }
        }while (top>0);
    }
}

int BTDepth(BiTree T)//求二叉树的深度
{
    //请填写代码
    //..........
    return 0;
}

void Leaf(BiTree T)//求二叉树的叶子数, 使用全局变量
{
    //请填写代码
    //..........
}

void NodeCount(BiTree T)//求二叉树的结点总数, 使用全局变量
{
    //请填写代码
    //..........
}

int  main()
{
    setbuf(stdout, NULL);
    BiTree T=NULL;
    int select;
    while(1)
    {
        printf("\n1.创建二叉树\n");
        printf("2.二叉树的递归遍历算法（先,中,后）\n");
        printf("3.二叉树的层次遍历算法\n");
        printf("4.求二叉树的深度\n");
        printf("5.求二叉树的叶子结点\n");
        printf("6.求二叉树的结点总数\n");
        printf("7.二叉树的非递归遍历算法（先,中,后）\n");
        printf("0.退出\n");
        printf("请选择要执行的操作: ");

        scanf("%d",&select);
        printf("---------------------- ");
        switch(select)
        {
            case 0:
                return 0;
            case 1:
                printf("\n按先序次序输入各结点的值，以空格表示空树(输入时可连续输入):\n");
                fflush(stdin);//清空输入缓冲
                CreateBiTree(T);
                printf("二叉树创建成功!\n");
                break;
            case 2:
                if(!T)
                    printf("未建立树，请先建树！\n");
                else{
                    printf("\n先序遍历: ");
                    PreOrderTraverse(T);
                    printf("\n中序遍历: ");
                    InOrderTraverse(T);
                    printf("\n后序遍历: ");
                    PostOrderTraverse(T);
                    printf("\n");
                }
                break;
            case 3:
                printf("\n层序遍历: ");
                LevelOrderTraverse(T);
                printf("\n");
                break;
            case 4:
                printf("\n二叉树的深度为: ");
                printf("%d\n",BTDepth(T));
                break;
            case 5:
                printf("\n叶子节点数: ");
                LEAFCOUNT=0;
                Leaf(T);
                printf("%d\n",LEAFCOUNT);
                break;
            case 6:
                printf("\n总节点数: ");
                NODECOUNT=0;
                NodeCount(T);
                printf("%d\n",NODECOUNT);
                break;
            case 7:
                if(!T)
                    printf("未建立树，请先建树！");
                else
                {
                    printf("\n先序遍历: ");
                    NRPreOrder(T);
                    printf("\n中序遍历: ");
                    NRInOrder(T);
                    printf("\n后序遍历: ");
                    NRPostOrder(T);
                    printf("\n");
                }
                break;
            default:
                printf("请确认选择项:\n");
        }
    }
}