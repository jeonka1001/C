//
//  main.c
//  합분해
//
//  Created by 전경안 on 2019/12/29.
//  Copyright © 2019 전경안. All rights reserved.
//  정수 N을 입력받아 0에서 N까지의 정수 중 K개를 이용한 합으로 표현하는 코드.
//  총 몇가지의 방법이 있는지 방법의 수만 출력.
// ex) N=2 k=2 인 경우 N(=2)를 0에서 N(=2)까지의 정수 중 K(=2)개를 이용한 합 으로 표현하면 0+2 1+1 2+0 이므로 출력값 3.
// 1 <= N <= 200 , 1 <= k <= 200

#include <stdio.h>
#define mod 1000000000

void input(int*,int*);
long long int d[201][201]={0,};
long long int calc(int,int);

int main() {
    int n,k;
    long long int num;
    input(&n,&k);
    num = calc(n,k);
    printf("%lld",num);
    return 0;
}

void input(int *n,int *k){
    printf("n k 입력:");
    scanf("%d %d",n,k);
}

long long int calc(int n,int k){
    if(d[n][k]!=0)return d[n][k]%mod;
    if(n==0||k==1){
        d[n][k]=1;
        return d[n][k]%mod;
    }
    for(int i=0;i<=n;i++){
        d[n][k]+=calc(n-i,k-1);
    }
return d[n][k]%mod;
}
