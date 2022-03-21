 #include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "iostream"
 
using namespace std;
#define MaxVex 10                //假设当前顶点数最多为10个
#define INFINITY  65535 /* 表示权值的无穷*/
typedef char VertexType;        //元素类型以字符
int visited[MaxVex];            //用来存放当前顶点是否遍历过

//*****定义邻接矩阵****
typedef struct MGraph {
    VertexType vexs[MaxVex];//点集合
    int arcs[MaxVex][MaxVex];//邻接矩阵集合
    int vexnum, arcnum;
} MGraph;

//******定义邻接表******
typedef struct ArcNode            //邻接表中的边结点类型
{
    int adjvex;                    //邻接点在数组中的位置
    struct ArcNode *nextarc;    //指向下一个边结点的链域
} ArcNode;

typedef struct VNode            //邻接表表头结点类型
{
    VertexType data;
    ArcNode *firstarc;
} VNode;

typedef struct                    //邻接表
{
    VNode vertices[MaxVex];
    int vexnum, arcnum;
} ALGraph;

//若G中存在v,则返回该顶点在图中位置,否则返回-1
int LocateVex(MGraph G, VertexType v) {
    int a=0;
    do{
        if(G.vexs[a]==v){
            return a;
        }
        a++;
    }while (G.vexs[a]);
    return -1;
}

int LocateVex(ALGraph G, VertexType v) {
    int i;
    for (i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data == v)
            return i;
    }
    return -1;
}

//返回顶点v的第一个临接点位置,否则返回-1
int FisrtAdjVertex(MGraph G, int v) {
    //请填写完整代码
    //......
}

//返回顶点v相对于w的下一个临接点位置,否则返回-1
int NextAdjVertex(MGraph G, int v, int w) {
    //请填写完整代码
    //......
}

//邻接矩阵存储方式建立无向图
void CreateMGraph(MGraph &G) {
    /*
    1.输入图中顶点总数与边的总数。
    2.输入图中顶点信息，存放到G.vexs[i]数组中。
    3.初始化邻接矩阵中所有值为0
    4.输入边的信息，修改邻接矩阵中相对应的元素值。
    */
    int i,j,k;
    printf("请输入顶点数,边数:");
    scanf("%d,%d",&G.vexnum,&G.arcnum);
    getchar();//接收上一次输入的回车，便于下一次输入

    for(i=0; i<G.vexnum; i++)
    {
        printf("请输入第%d个顶点信息:",i+1);
        scanf("%c",&G.vexs[i]);
        getchar();
    }

    for(i=0; i<G.vexnum; i++)
        for(j=0; j<G.vexnum; j++)
            G.arcs[i][j]=0;

    VertexType v1,v2;
    for(k=0; k<G.arcnum; k++)//构造邻接矩阵
    {
        printf("请输入第%d条边的两个顶点（a,b）:",k+1);
        scanf("%c,%c",&v1,&v2);
        //确定v1和v2在G中的位置
        i=LocateVex(G, v1);
        j=LocateVex(G, v2);
        G.arcs[i][j]=1;
        G.arcs[j][i]=1;
        getchar();
    }
}

//输出图的邻接矩阵
void PrintMGraph(MGraph MG) {
    int i, j;
    printf("下标   元素值  边的信息\n");
    for (i = 0; i < MG.vexnum; i++) {
        printf("%d\t%c\t", i, MG.vexs[i]);
        for (j = 0; j < MG.vexnum; j++)
            printf("%d ", MG.arcs[i][j]);
        printf("\n");
    }
}

//从第i个顶点开始深度遍历
void DFSMGraph(MGraph G, int i) {
    printf("下表为%d的顶点数据为：%c\n",i,G.vexs[i]);
    visited[i]=1;
    for(int n=0;n<G.vexnum;n++){
        if(G.arcs[i][n]==1){
            if(visited[n]!=1){
                DFSMGraph(G,n);
            }
        }
    }
}

//从第i个顶点开始广度遍历
void BFSMGraph(MGraph G, int i) {
    //请填写完整代码
    //......
}

//建立邻接表存储方式的无向图
void CreateALGraph(ALGraph &G) {
    /*	1.输入图中顶点总数与边的总数
        2.输入图中顶点信息，存放到G.vertices[i].data中。
        3.输入边的信息，建立边结点，插入到相对应数组元素后的边表中（注：无向图中每条边需要插入两个边结点）。*/
    int i, j, k;
    printf("请输入顶点数,边数:");
    scanf("%d,%d", &G.vexnum, &G.arcnum);
    getchar();

    for (i = 0; i < G.vexnum; i++) {
        printf("请输入第%d个顶点信息:", i + 1);
        scanf("%c", &G.vertices[i].data);
        G.vertices[i].firstarc = NULL;
        getchar();
    }

    VertexType v1, v2;
    ArcNode *p, *q;
    for (k = 0; k < G.arcnum; k++) {//构造邻接矩阵
        printf("请输入第%d条边的两个顶点(a,b):", k + 1);
        scanf("%c,%c", &v1, &v2);
        //确定v1和v2在G中的位置
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);

        //在i顶点后面插入表结点(头插)
        p = G.vertices[i].firstarc;
        q = (ArcNode *) malloc(sizeof(ArcNode));
        q->adjvex = j;
        q->nextarc = p;
        G.vertices[i].firstarc = q;
        //在j顶点后面插入表结点(头插)
        p = G.vertices[j].firstarc;
        q = (ArcNode *) malloc(sizeof(ArcNode));
        q->adjvex = i;
        q->nextarc = p;
        G.vertices[j].firstarc = q;
        getchar();
    }
}

//输出图的邻接表
void PrintALGraph(ALGraph G) {
    int i;
    ArcNode *p;
    printf("下标   元素值   边的信息\n");
    for (i = 0; i < G.vexnum; i++) {
        printf("%d\t%c\t", i, G.vertices[i].data);
        p = G.vertices[i].firstarc;
        while (p) {
            printf("->%d ", p->adjvex);
            p = p->nextarc;
        }
        printf("\n");
    }
}

//深度遍历邻接表
void DFSALGraph(ALGraph G, int i) {
    //请填写完整代码
    //......
}

//广度遍历邻接表
void BFSALGraph(ALGraph G, int i) {
    //请填写完整代码
    //......
}

//邻接矩阵转换为邻接表
void GraphChange(MGraph MG, ALGraph &ALG) {
    int i, j;
    ALG.vexnum = MG.vexnum;
    ALG.arcnum = MG.arcnum;
    for (i = 0; i < MG.vexnum; i++) {
        ALG.vertices[i].data = MG.vexs[i];
        ALG.vertices[i].firstarc = NULL;
    }
    for (i = 0; i < MG.vexnum; i++) {
        for (j = 0; j < MG.vexnum; j++) {
            if (MG.arcs[i][j] != 0) {
                ArcNode *p = (ArcNode *) malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->nextarc = ALG.vertices[i].firstarc;
                ALG.vertices[i].firstarc = p;
            }
        }
    }
}

//主函数
int main() {
    setbuf(stdout, NULL);
    int i, v;
    MGraph MG;
    ALGraph ALG;
    int select;

    while (1) {
        printf("\n");
        printf("1.建立图(邻接矩阵存储)\n");
        printf("2.深度遍历(邻接矩阵)\n");
        printf("3.广度遍历(邻接矩阵)\n");
        printf("4.建立图(邻接表存储)\n");
        printf("5.深度遍历(邻接表)\n");
        printf("6.广度遍历(邻接表)\n");
        printf("7.图的邻接矩阵存储转换为邻接表存储\n");
        printf("8.退出\n");

        printf("请选择要执行的操作:");
        scanf("%d", &select);
        switch (select) {
            case 0:
                return 0;
            case 1:
                printf("\n建立图的邻接矩阵存储\n");
                CreateMGraph(MG);
                printf("\n输出图的邻接矩阵\n");
                PrintMGraph(MG);
                break;
            case 2:
                printf("\n输入深度遍历的起始顶点位置:");
                scanf("%d", &v);
                for (i = 0; i < MG.vexnum; i++)
                    visited[i] = 0;
                printf("深度遍历序列(邻接矩阵): ");
                DFSMGraph(MG, v);
                printf("\n");
                break;
            case 3:
                printf("\n输入广度遍历的起始顶点位置:");
                scanf("%d", &v);
                for (i = 0; i < MG.vexnum; i++)
                    visited[i] = 0;
                printf("广度遍历序列(邻接矩阵): ");
                BFSMGraph(MG, v);
                printf("\n");
                break;
            case 4:
                printf("\n建立图的邻接表存储\n");
                CreateALGraph(ALG);
                printf("\n输出图的邻接表\n");
                PrintALGraph(ALG);
                break;
            case 5:
                printf("\n输入深度遍历的起始顶点位置:");
                scanf("%d", &v);
                for (i = 0; i < ALG.vexnum; i++)
                    visited[i] = 0;
                printf("深度遍历序列(邻接表):");
                DFSALGraph(ALG, v);
                printf("\n");
                break;
            case 6:
                printf("\n输入广度遍历的起始顶点位置:");
                scanf("%d", &v);
                for (i = 0; i < ALG.vexnum; i++)
                    visited[i] = 0;
                printf("广度遍历序列(邻接表):");
                BFSALGraph(ALG, v);
                printf("\n");
                break;
            case 7:
                GraphChange(MG, ALG);
                printf("\n输出图的邻接表\n");
                PrintALGraph(ALG);
                printf("\n");
                break;
            case 8:
                return 0;
            default:
                printf("请确认选择项!\n");
        }
    }
}
