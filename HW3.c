//
//  main.c
//  HW#3_20190627
//
//  Created by 전경안 on 27/06/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
int calchour(int);//시간 계산 함수
int calcmin(int);//분 계산 함수
int calcsec(int);//초 계산 함수

int a;//입력받는 시간에 대한 변수
int hour,min,sec;//환산하는 시간에 대한 변수

int main() {
    printf("초를 입력해 주세요:");
    scanf("%d",&a);
    hour = calchour(hour);
    min = calcmin(min);
    sec = calcsec(sec);
    printf ("%d시 %d분 %d초 입니다.\n",hour,min,sec);
    return 0;
}

int calchour(hour)//시간 계산 함수
{
    hour = a/3600;
    return hour;
}

int calcmin(min)//분 계산 함수
{
    min=(a-hour*3600)/60;
    return min;
}

int calcsec(sec)//초 계산 함수
{
    sec=(a-hour*3600)%60;
    return sec;
}
