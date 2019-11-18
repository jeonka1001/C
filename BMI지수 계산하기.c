//
//  main.c
//  HW15_20190627
//
//  Created by 전경안 on 27/06/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>

void calca(void);//몸무게 소견표 계산
double calcbmi(double BMI);//bmi계산함수
double height,weight,BMI;//키,체중,bmi


int main()//입력함수
{
    printf("키를 입력해 주세요(M):");
    scanf("%lf",&height);
    printf("몸무게를 입력해 주세요(Kg):");
    scanf("%lf",&weight);
    BMI=calcbmi(BMI);
    calca();
    return 0;
}

double calcbmi(double BMI)//bmi계산함수
{
    BMI=weight/(height*height);
    return BMI;
}

void calca()//출력함수
{
    if (BMI>=18.5&&BMI<25.0)
    {
        printf("당신의 BMI는 %.1lf 입니다.따라서 당신은 정상체중입니다.\n",BMI);
    }
    else if(BMI>=25.0&&BMI<30.0)
    {
        printf("당신의 BMI는 %.1lf 입니다.따라서 당신은 과체중입니다.\n",BMI);
    }
    else if(BMI>=30.0&&BMI<40.0)
    {
        printf("당신의 BMI는 %.1lf 입니다.따라서 당신은 비만입니다.\n",BMI);
    }
    else if(BMI>=40)
    {
        printf("당신의 BMI는 %.1lf 입니다.따라서 당신은 고도비만입니다.\n",BMI);
    }
    else{
        printf("당신의 BMI는 %.1lf 입니다.따라서 당신은 저체중입니다.\n",BMI);
    }
}
