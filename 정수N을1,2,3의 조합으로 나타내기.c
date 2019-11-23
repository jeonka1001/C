//
//  main.c
//  정수 n을 123의 조합으로 나타내는 방법
//
//  Created by 전경안 on 2019/11/23.
//  Copyright © 2019 전경안. All rights reserved.
// 정수 N이 있을 시 1,2,3의 조합의 합으로 나타내는 방법

#include <stdio.h>
int input(void);
int calc(int);
int main() {
    int ans,n;
    n=input();
    ans=calc(n);
    printf("%d를 1,2,3으로 나타내는 방법의 수는 %d 이다.\n",n,ans);
    return 0;
}

int input(){
    int a;
    printf("정수N을 입력하세요.:");
    scanf("%d",&a);
    return a;
}

int calc(int n){
    int d[10000];
    if(n<=3){
        if(n<=0){
            return 0;
        }
        else if(n==3){
            return 4;
        }
        else{
            d[n]=n;
            return n;
        }
    }
    else{
        d[n]=calc(n-1)+calc(n-2)+calc(n-3);
        return d[n];
    }
}
