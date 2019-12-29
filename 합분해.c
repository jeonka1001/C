//
//  main.c
//  합분해
//
//  Created by 전경안 on 2019/12/29.
//  Copyright © 2019 전경안. All rights reserved.
//

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
