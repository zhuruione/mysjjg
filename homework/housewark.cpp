//
// Created by zr on 2021/11/14.
//
#include <stdio.h>
#include <time.h>

#define X 8
#define Y 8

int nowxy[X][Y] = {0};


int housemove(int position, int &x, int &y) {
    switch (position) {
        //上左
        case 0:
            if (x - 1 >= 0 && y - 2 >= 0 && nowxy[x - 1][y - 2] == 0) {//如果x,y坐标有棋子而且这个棋子没有被遍历
                x = x - 1;
                y = y - 2;
                return 1;
            }
            break;
            //上右
        case 1:
            if (x + 1 <= X - 1 && y - 2 >= 0 && nowxy[x + 1][y - 2] == 0) {
                x = x + 1;
                y = y - 2;
                return 1;
            }
            break;
            //右上
        case 2:
            if (x + 2 <= X - 1 && y - 1 >= 0 && nowxy[x + 2][y - 1] == 0) {
                x = x + 2;
                y = y - 1;
                return 1;
            }
            break;
            //右下
        case 3:
            if (x + 2 <= X - 1 && y + 1 <= Y - 1 && nowxy[x + 2][y + 1] == 0) {
                x = x + 2;
                y = y + 1;
                return 1;
            }
            break;
            //下右
        case 4:
            if (x + 1 <= X - 1 && y + 2 <= Y - 1 && nowxy[x + 1][y + 2] == 0) {
                x = x + 1;
                y = y + 2;
                return 1;
            }
            break;
            //下左
        case 5:
            if (x - 1 >= 0 && y + 2 <= Y - 1 && nowxy[x - 1][y + 2] == 0) {
                x = x - 1;
                y = y + 2;
                return 1;
            }
            break;
            //左下
        case 6:
            if (x - 2 >= 0 && y + 1 <= Y - 1 && nowxy[x - 2][y + 1] == 0) {
                x = x - 2;
                y = y + 1;
                return 1;
            }
            break;
            //左上
        case 7:
            if (x - 2 >= 0 && y - 1 >= 0 && nowxy[x - 2][y - 1] == 0) {
                x = x - 2;
                y = y - 1;
                return 1;
            }
            break;
    }
    return 0;
}



int test(int tag,int x,int y){

    int x1=x,y1=y;
    int next=0;
    int position=0;
    nowxy[x][y]=tag;
    //判断是否成功
    if(tag==X*Y){
        return 1;
    }


    //找🐎下一个位置
    next=housemove(position,x1,y1);
    while (next==0&&position<=7){
        next= housemove(++position,x1,y1);
    }


    while(next){
        if(test(tag+1,x1,y1))
            return 1;
        x1=x;
        y1=y;

        position++;
        next= housemove(position,x1,y1);
        while (next==0&&position<=7){
            next= housemove(++position,x1,y1);
        }
    }

    //没有下一个位置可以走
    if(next==0){
        nowxy[x][y]=0;
    }
    return 0;
}


void print(){
    int count=0;
    for(int n=0;n<X;n++){
        for(int m=0;m<Y;m++){
            if(count%8==0)
                printf("\n");
            printf("%2d  ",nowxy[n][m]);
            count++;
        }
    }
}



int main(){

    int tag=1;
    int x,y;
    scanf("%d,%d",&x,&y);
    test(tag,x,y);
    print();

    int a[64];
    for(int n=0;n<64;n++){
        a[n]=n+1;
    }


    for(int n=0;n<X;n++){
        for(int m=0;m<Y;m++){
            for(int n=0;n<64;n++){
                for(int c=0;c<64;c++){
                    if(a[c]==nowxy[n][m])
                        a[c]=0;
                }
            }
        }
    }
    printf("\n\n======");
    for(int n=0;n<64;n++){
        if(a[n]!=0){
            printf("%d  ",a[n]);
        }
    }
}