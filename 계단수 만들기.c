//
//  main.c
//  쉬운 계단수 만들기
//
//  Created by 전경안 on 2019/11/25.
//  Copyright © 2019 전경안. All rights reserved.
// 계단수란 인접한 자리의 수의 차가 1인 수 예)456567

#include <stdio.h>
int input(void);
int calc(int);
int main() {
    int num,ans;
    num = input();
    ans = calc(num);
    printf("%d",ans);
    return 0;
}
int input(){
    int a;
    printf("계단수의 길이를 입력하세요:");
    scanf("%d",&a);
    return a;
}
int calc(int n){
    int d[10000][9],i,j,ans[10000];
    d[1][0]=0;
    for(j=1;j<=9;j++){
        d[1][j]=1;
        ans[1]+=d[1][j];
        
    }
    for(i=2;i<=n;i++){
        for(j=0;j<=9;j++){
            d[i][j]=0;
            if((j-1)>=0){
                d[i][j]+=d[i-1][j-1];
            }
            else{};
            if((j+1)<=9){
                d[i][j]+=d[i-1][j+1];
            }
            else{};
            
            ans[i]+=d[i][j];
            
        }
    }
    return ans[n];
}
