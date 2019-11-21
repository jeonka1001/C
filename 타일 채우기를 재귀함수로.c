#include<stdio.h>
int input(void);
int dynamic(int);
int main(){
    int n,res;
    n=input();
    res = dynamic(n);
    printf("2x%d의 타일을 채우는 방법의 수는: %d이다.\n",n,res);
    return 0;
}
int input(){
    int num;
    printf("타일의 가로길이 입력:");
    scanf("%d",&num);
    return num;
}
int dynamic(int n){
    int d[10000];
    if(n==1||n==2)return n;
    d[n]=dynamic(n-1)+dynamic(n-2);
    return d[n];
}
