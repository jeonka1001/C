//
//  main.c
//  2019.12.04
//
//  Created by 전경안 on 2019/12/04.
//  Copyright © 2019 전경안. All rights reserved.
// 첫째자리에는 1 / 1이 연속으로 두번 나오면 룰 위반 / 이친수 만들기 ex) 1 1001 1010 100001000101
// 1101 0101 0111 10100101011 는 안되는 예시
// 자릿수 입력시 가능한 방안 수 출력

#include <stdio.h>
int input(void);
int calc(int,int);

int main() {
    int num,num2;
    num = input();
    num2 = calc(num,1)+calc(num,0);
    printf("%d",num2);
    return 0;
}
int input(){
    int a;
    printf("자릿수 입력.:");
    scanf("%d",&a);
    return a;
}

int calc(int n,int l){
    int d[90][2];
    if(n==2&&l==0){
        return 1;
    }
    else if(n==2&&l==1){
        return 0;
    }
    else{
        if(l==1){
            d[n][l]=calc(n-1,0);
        }
        else{
            d[n][l]=calc(n-1,1)+calc(n-1,0);
        }
        return d[n][l];
    }
}
