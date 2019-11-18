//
//  main.c
//  HW16_20190628
//
//  Created by 전경안 on 28/06/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
int calccharge(int);
int sta,charge;

int main() {
    int i=0;//while 반복문
    while(i<=4){
        printf("정거장의 수를 입력하세요:");
        scanf("%d",&sta);
        charge = calccharge(sta);
        printf("요금은 %d원입니다.\n",charge);
        i++;
    }
    return 0;
}

int calccharge(int sta){
    int a=10;//10정거장 초과시 사용될 변수
    
    if(sta>=1&&sta<=5){
        charge = 600;
    }
    else if(sta>=6&&sta<=10){
        charge=800;
    }
    else {
       
        charge=800;
        while(a<=sta){
            if(a%2==1){
                charge+=100;
            }
            a++;
        }
    }
    return charge;
}
