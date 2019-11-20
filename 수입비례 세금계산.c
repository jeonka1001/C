//
//  main.c
//  HW20_20190702
//
//  Created by 전경안 on 02/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
int input(void);//입력
int totalcalc(int);//총수입계산
int taxcalc(int);//세금
void output(int,int);//출력

int time,total,tax;

int main() {
    time = input();
    total = totalcalc(time);
    tax = taxcalc(total);
    output(total,tax);
    return 0;
}

int input(void)
{
    int a;
    printf("* 1주일간의 근무시간을 입력하시오:");
    scanf("%d",&a);
    return a;
}

int totalcalc(int time)
{
    int c,d,b;//c=총 급여, d = 초과시간,b=초과시간급여
    b=0;d=0;
    
    if (time>40)
    {
        d = time-40;
        b = d*8500*1.5;
    }
    c = b+((time-d)*8500);
    return c;
}

int taxcalc(int total)
{
    int e,f,g;//e=총세금,f=초과세금g=초과금액
    g=0;f=0;
    
    if(total>100000)
    {
        g=total-100000;
        f=g*0.25;
    }
    e=f+((total-g)*0.15);
    return e;
}

void output(int total, int tax)
{
    printf("# 총수입: %d원\n# 세금: %d원\n# 실수입: %d원\n",total,tax,total-tax);
}
