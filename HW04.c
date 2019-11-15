//
//  main.c
//  HW420190701
//
//  Created by 전경안 on 01/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
double input(void);
void calcdate(double);
void output(void);

double day,sec;
int date,time,min;

int main() {
    day=input();
    calcdate(day);
    output();
    return 0;
}

double input(void)
{
    double a;
    printf("일 을 입력하세요:");
    scanf("%lf",&a);
    return a;
}

void calcdate(double day)
{
    date=day/1;
    time=(day-date)*24/1;
    min=((day-date)*24-time)*60;
    sec=(((day-date)*24-time)*60-min)*60;
}

void output()
{
    printf("%lf일은 %d일 %d시간 %d분 %.2lf초 입니다.\n",day,date,time,min,sec);
}
