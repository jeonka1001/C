//
//  main.c
//  HW18_20190628
//
//  Created by 전경안 on 28/06/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
int inputage(void);
int inputdiscount(void);
int calcmoney(int,int);
int percent(int,int);
int calccharge(int, int);

int age,dis;

int main() {
    int money,discount,charge;
    age = inputage();
    dis = inputdiscount();
    money = calcmoney(age,dis);
    discount = percent(money,dis);
    charge = calccharge(money,discount);
    printf("입장료:%d원 \n할인금액:%d원 \n결제금액:%d원\n",money,discount,charge);
    return 0;
}

int inputage(){
    int a;
    printf("입장객의 나이를 입력하시오:");
    scanf("%d",&a);
    return a;
}

int inputdiscount(){
    int b;
    printf("입장객의 수를 입력하시오:");
    scanf("%d",&b);
    return b;
}

int calcmoney(int age,int dis){
    int totalmoney;
    if(age>=8&&age<=13){
        totalmoney=dis*700;
    }else if(age>=14&&age<=19){
        totalmoney=dis*1000;
    }else if(age>=20&&age<=55){
        totalmoney=dis*1500;
    }else{
        totalmoney=dis*500;
    }
    return totalmoney;
}

int percent(int money,int dis){
    int c;
    if(dis>=5){
    c = money/10;
    }
    else{
        c = 0;
    }
    return c;
}

int calccharge(int money,int discount){
    int d;
    d = money - discount;
    return d;
}
