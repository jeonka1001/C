#include<stdio.h>
int calc(int);
int d[1000001];
int main(){
    int num,n;
    printf("수 입력:");
    scanf("%d",&num);
    n=calc(num);
    printf("%d의 제곱수의 최소항은 %d개 입니다.\n",num,n);
    return 0;
}
int calc(int n){
    int tmp;
    if(n==1){
        return 0;
    }
    if(d[n]>0){
        return d[n];
    }
    d[n]=calc(n-1)+1;
    if(n%2==0){
        tmp=calc(n/2)+1;
        if(d[n]>tmp){
            d[n]=tmp;
        }
    }
    if(n%3==0){
        tmp=calc(n/3)+1;
        if(d[n]>tmp){
            d[n]=tmp;
        }
    }
    return d[n];
}
