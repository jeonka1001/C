//
//  main.c
//  HW06_20190701
//
//  Created by 전경안 on 01/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
double input(void);
double calcdegree(double);
void output(double, double);

double degreeF,degree;

int main() {
    degreeF = input();
    degree = calcdegree(degreeF);
    output(degree,degreeF);
    return 0;
}

double input()
{
    double a;
    printf("화씨 온도를 입력하세요:");
    scanf("%lf",&a);
    return a;
}

double calcdegree(double degreeF)
{
    double b;
    b = 5/(double)9*(degreeF-32);
    return b;
}

void output(double degree,double degreeF)
{
    printf("입력하신 화씨 %lf 는 섭씨 %.1lf 입니다.\n",degreeF,degree);
}
