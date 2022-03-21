//
// Created by zr on 2021/12/11.
//
#include "iostream"
using namespace std;
int main(){
    int n=10;
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    //paixu
    int c,d;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            c=a[i];
            for(d=i-1;c<a[d];--d){
                a[d+1]=a[d];
            }
            a[d+1]=c;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}
