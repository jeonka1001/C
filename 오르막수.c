// 오르막수란 앞 숫자가 뒤의 숫자보다 작거나 같은 수
//ex) 1111, 123345, 11225566, 12367

#include<stdio.h>

int input(void);
int calc(int );

int main(){
    int n,numc;
    n=input();
    numc=calc(n);
    printf("%d\n",numc);
    return 0;
}

int input(){
    int num;
    printf("숫자를 입력해봐라:");
    scanf("%d",&num);
    return num;
}

int calc(int n){
    int i,d[100][100]={0,},f,j,sum=0;
    for(i=0;i<=9;i++){
        d[1][i]=1;
    }
    for(f=2;f<=n;f++){
        for(i=0;i<=9;i++){
            for(j=0;j<=i;j++){
                d[f][i] += d[f-1][j];
            }
            printf("\n");
        }
    }
    for(i=0;i<=9;i++){
        sum+=d[n][i];
    }
    return sum;
}
