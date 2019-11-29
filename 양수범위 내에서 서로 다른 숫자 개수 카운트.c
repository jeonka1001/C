//
//  main.c
//  HW59_20190717
//
//  Created by 전경안 on 17/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
// 중복인 숫자를 지우고 서로 다른 숫자의 개수만을 판별

#include <stdio.h>
int input(int*,int*);
int checknumber(int*,int*);
int main() {
    int num[100],a,res,count;
    while(1){
        res = input(num,&a);
        if(res==0){
            break;
        }
        else{
            count = checknumber(num,&a);
            printf("서로 다른 숫자의 개수 : %d\n",count);
        }
    }
    return 0;
}

int input(int *num,int *a){
    int i,res;
    printf("입력할 숫자의 개수:");
    res=scanf("%d",a);
    if(res==0){
        return 0;
    }
    else{
        printf("숫자 입력:");
        for(i=0;i < *a;i++){
            scanf("%d",num+i);
        }
    }
    return 1;
}

int checknumber(int *num,int *a){
    int i=0,j,count=0;
    while(i<*a){
        for(j=*a-1;j>i;j--){
            if(*(num+i)==*(num+j)){
                *(num+j)=0;
            }
            else{;}
        }
        i++;
    }
    for(i=0;i<*a;i++){
        if(*(num+i)!=0){
            count++;
        }else{
            ;
        }
    }
    return count;
}
