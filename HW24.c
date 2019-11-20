//
//  main.c
//  HW24_20190703
//
//  Created by 전경안 on 03/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
int input(void);
int calcdate(int);
void output(double,int);

int main() {
    int deep,date;
    
    deep=input();
    date=calcdate(deep);
    output(deep,date);
    return 0;
}

int input()
{
    int a;
    printf("우물의 깊이를 입력하시오(cm단위):");
    scanf("%d",&a);
    return a;
}

int calcdate(int deep)
{
    int b,c;//b=달팽이의 총 이동거리,c=달팽이가 이동하는데 걸린 날짜
    b=0;c=0;
    
    if(deep==0)
    {
        return 0;
    }
    else{
        while(1)
        {
            b+=50;
            if(b>=deep)
            {
                c++;
                break;
            }
            else{
                b-=20;
            }
            c++;
        }
    }
    return c;
}

void output(double deep, int date)
{
    double d;
    d=deep*0.01;
    printf("달팽이가 %.2lf미터 우물을 빠져나가기 위해서는 %d 일이 걸립니다.\n",d,date);
}
