//
//  main.c
//  HW27_20190705
//
//  Created by 전경안 on 05/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
void inputnumber(int count);
void myflush(void);

int main() {
    int count=1;
    
    while(count<=10){
        inputnumber(count);
        count++;
    }
    printf("*** 달걀 포장 완료 !\n");
    return 0;
}
void inputnumber(int count)
{
    int res;
    double a;
    while(1)
    {
        printf("#계란의 무게를 입력하시오(단위:g):");
        res = scanf("%lf",&a);
        if(res==1)
        {
            if(a>=150&&a<=500)
            {
                printf("달걀의 수:%d\n",count);
                myflush();
                break;
            }
            else if(a<150){
                printf("메추리는 ㄴㄴ해~\n");
                myflush();
            }
            else if(a>500){
                printf("타조알은 ㄴㄴ해~\n");
                myflush();
            }
            else{
                ;
            }
        }
        else{
            printf("문자가 아닌 수를 입력해 주세요(범위 150-500)\n");
            myflush();
        }
    }
}

void myflush()
{
    while(getchar()!='\n')
    {
        ;
    }
}
