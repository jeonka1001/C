//
//  main.c
//  HW05_20190701
//
//  Created by 전경안 on 01/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
int input(void);
double calccharge(double);//전체요금
double calctax(double);//세금
void output(double,double);

double elect,total,tax;

int main() {
    elect = input();
    total=calccharge(elect);
    tax=calctax(total);
    output(total,tax);
    return 0;
}

int input()
{
    double a;
    printf("전기 사용량을 입력하세요(kw):");
    scanf("%lf",&a);
    return a;
}

double calccharge(double elect)
{
    double b;
    b = 660 + (elect*88.5);
    return b;
}

double calctax(double total)
{
    double c;
    c = total*0.09;
    return c;
}

void output(double total,double tax)
{
    printf("전기 사용 요금은 %lf입니다.\n",total+tax);
}
