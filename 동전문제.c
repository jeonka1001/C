//
//  main.c
//  동전문제
//
//  Created by 전경안 on 2020/01/01.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <stdio.h>
void input(int *,int *);
int calc(int,int,int);

int coin[101];
int d[10001][101]={0,};

int main(){
    int n,k,low=0,tmp;
    input(&n,&k);
    tmp=calc(low,n,k);
    printf("%d",tmp);
    return 0;
}

void input(int *n,int*k){
    printf("동전 개수, 동전 크기:");
    scanf("%d %d",n,k);
    printf("동전 가치:");
    for(int i=0;i<*n;i++){
        scanf("%d",&coin[i]);
    }
}

int calc(int low,int n,int k){
    if(k==0)return 1;
    if(d[k][low]!=0)return d[k][low];
    for(int i=low;i<n;i++){
        for(int j=k;j>0;j--){
            if(k==coin[i]*j){
                d[k][low]+=1;
            }
            else{
                if(k>coin[i]*j){
                    d[k][low]+=calc(i+1,n,k-coin[i]*j);
                }
            }
        }
    }
    return d[k][low];
}

