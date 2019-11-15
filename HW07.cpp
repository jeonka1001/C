//
//  main.c
//  HW07_20190701
//
//  Created by 전경안 on 01/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
double inputdistance(void);//입력거리
double inputspeed(void);//입력출력
double calctime(double,double);//계산1
double calcmin(double);//계산2
void output(double,double);//출력시간

double spe,dis,time,min;

int main() {
    dis = inputdistance();
    spe = inputspeed();
    time = calctime(dis,spe);
    min = calcmin(time);
    output(time,min);
    return 0;
}

double inputdistance()//입력함수거리
{
    double a;
    printf("거리를 입력하세요(km):");
    scanf("%lf",&a);
    return a;
}

double inputspeed()//입력함수속도
{
    double b;
    printf("시속을 입력하세요(km/h):");
    scanf("%lf",&b);
    return b;
}

double calctime(double dis,double spe)//계산함수1
{
    double c;
    c = dis/spe;
    return c;
}

double calcmin(double time)//계산함수2
{
    double d;
    d = (time-(int)time)*60;
    return d;
}

void output(double time, double min)//출력함수
{
    printf("%.3lfkm를 주행하는데 걸리는 시간은 %d시간 %d분 %.3lf초 입니다.\n",dis,(int)time,(int)min,(min-(int)min)*60);
}

