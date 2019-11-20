//
//  main.c
//  HW23_20190702
//
//  Created by 전경안 on 02/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//
// 입력받은 정수 개수만크 별을 찍는 프로그램 입니다. 줄당 5개씩

#include <stdio.h>
int input(void);//

int main() {
    int num,i;
    i=1;
    
    num=input();
    while (i<=num)
    {
        printf("*");
        if(i%5==0)
        {
            printf("\n");
        }
        i++;
    }
    printf("\n");
    return 0;
}

int input()
{
    int a;
    printf("# 정수값을 입력하세요:");
    scanf("%d",&a);
    return a;
}
