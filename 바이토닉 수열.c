#include<stdio.h>

int input(void);
int A[10001],D[1001],D2[1001];
void upcalc(int);
void downcalc(int);
int maxcalc(int);
int main(){
    int num,maxnum;
    num = input();
    upcalc(num);
    downcalc(num);
    maxnum = maxcalc(num);
    printf("이 수열의 부분수열 중 가장 긴 바이토닉 수열의 길이는 %d 이다.\n",maxnum);
    return 0;
}

int input(){
    int i,t,*p;
    p=A;
    printf("수열의 길이는?");
    scanf("%d",&t);
    printf("수열을 입력해주세요:");
    for(i=0;i<t;i++){
        scanf("%d",(p+i));
    }
    return t;
}

void upcalc(int t){
    int i,j,*p,*d;
    p=A;
    d=D;
    for(i=0;i<t;i++){
        *(d+i)=1;
        for(j=0;j<i;j++){
            if( *(p+j) < *(p+i) && *(d+i) < *(d+j)+1 ){
                *(d+i) = *(d+j)+1;
            }
        }
    }
}

void downcalc(int t){
    int i,j,*p,*d2;
    p=A;
    d2=D2;
    for(i=t-1;i>=0;i--){
        *(d2+i)=1;
        for(j=t-1;j>i;j--){
            if( *(p+i) > *(p+j) && *(d2+i) < *(d2+j)+1){
                *(d2+i) = *(d2+j)+1;
            }
        }
    }
}

int maxcalc(int t){
    int max=0;
    int*d,*d2;
    d=D;
    d2=D2;
    
    for(int i=0;i<t;i++){
        if(max < *(d+i) + *(d2+i)){
            max=*(d+i) + *(d2+i);
        }
    }
    return max-1;
}


