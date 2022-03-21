//
// Created by zr on 2021/12/11.
//

#include "iostream"
using namespace std;
int main(){
    int n=5;
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    //paixu
    for(int i=0;i<n-1;i++){
        int flag=1;
        for(int cont=0;cont<n-1;cont++){
            if(a[cont]>a[cont+1]){
                int eg=a[cont];
                a[cont]=a[cont+1];
                a[cont+1]=eg;
                flag=0;
            }
        }
        if(flag==1)
            break;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}
