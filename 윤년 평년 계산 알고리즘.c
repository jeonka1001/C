//
//  main.c
//  HW19_20190628
//
//  Created by 전경안 on 28/06/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
int inputyear(void);
int calcyear(int);
void outputyear(int);

int year,yearcheck;

int main() {
    year = inputyear();
    yearcheck = calcyear(year);
    outputyear(yearcheck);
    return 0;
}

int inputyear(void){
    int yy;
    printf("년도를 입력하세요:");
    scanf("%d",&yy);
    return yy;
}

int calcyear(int year)
{
    if(year%4==0){
        if(year%100!=0||(year%100==0&&year%400==0)){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}
void outputyear(int yearcheck){
    if(yearcheck == 1){
        printf("%d년은 윤년입니다.\n",year);
    }
    else{
        printf("%d년은 평년입니다.\n",year);
    }
}
