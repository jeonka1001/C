//
//  main.c
//  제곱수 구하기
//
//  Created by 전경안 on 2019/12/28.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>

int input(void);
int calc(int);
int D[100001];

int main() {
    int num,sqnum;
    num = input();
    for(int i=1;i<=num;i++){
        D[i]=i;
    }
    sqnum=calc(num);
    printf("%d",sqnum);
    return 0;
}

int input(){
    int num;
    printf("숫자 입력");
    scanf("%d",&num);
    return num;
}
int calc(int num){
    int *d;
    int tmp;
    d=D;
    if(d[num]!=num)return d[num];
    for(int i=1; i <= num ;i++){
        if(num==i*i){
            d[num]=1;
            return d[num];
        }
        else if(num > i*i){
            tmp = 1 + calc(num-(i*i));
            if(d[num]>tmp) {
                d[num]=tmp;
            }
        }
        else if(num < i*i){
            break;
        }
    }
    return d[num];
}
