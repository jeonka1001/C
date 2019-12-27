#include<stdio.h>

int input(void);
void calc(int);
int sum(int);

int D[100001];
int A[100001];

int main(){
    int num,snum;
    num=input();
    calc(num);
    snum=sum(num);
    printf("%d",snum);
    return 0;
}

int input(){
    int t;
    int *a;
    a=A;
    printf("수열의 길이를 입력:");
    scanf("%d",&t);
    printf("수열을 입력:");
    for(int i=0;i<t;i++){
        scanf("%d",a+i);
    }
    return t;
}

void calc(int t){
    int *d,*a;
    int tmp;
    d=D;
    a=A;
    *d=*a;
    for(int i=1;i<t;i++){
        tmp = *(d+(i-1)) + *(a+i);
        if(tmp > *(a+i)){
            *(d+i)=tmp;
        }
        else{
            *(d+i)=*(a+i);
        }
    }
}

int sum(int t){
    int tmp;
    int *d;
    d=D;
    tmp=*d;
    for(int i=0;i<t;i++){
        if(tmp < *(d+i)){
            tmp = *(d+i);
        }
    }
    return tmp;
}
