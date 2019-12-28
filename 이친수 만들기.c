//
//  main.c
//  2019.12.04
//
//  Created by 전경안 on 2019/12/04.
//  Copyright © 2019 전경안. All rights reserved.
// 첫째자리에는 1 / 1이 연속으로 두번 나오면 룰 위반 / 이친수 만들기 ex) 1 1001 1010 100001000101
// 1101 0101 0111 10100101011 는 안되는 예시
// 자릿수 입력시 가능한 방안 수 출력

#include<stdio.h>

int input(void);
long long int a[91][3];
long long int calc(long long int);

int main(){
    int num;
    long long int d;
    num = input();
    d=calc(num);
    printf("%lld",d);
    return 0;
}

int input(){
    int num;
    printf("숫자 입력:");
    scanf("%d",&num);
    return num;
}

long long int calc(long long int n){
    int i,j;
    a[1][1]=1;
    a[1][0]=0;
    for(i=2;i<=n;i++){
        for(j=0;j<=1;j++){
            if(j==0)a[i][j]=a[i-1][0]+a[i-1][1];
            else if(j==1)a[i][j]=a[i-1][0];
        }
    }
    return a[n][0]+a[n][1];
}
