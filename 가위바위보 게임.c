//
//  main.c
//  HW26_20190704
//
//  Created by 전경안 on 04/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randNo(void);
int input(void);
void output(int,int);
void myflush(void);

int win,draw;

int main() {
    win=0;
    draw=0;
    int select,number;
    
    srand((unsigned)time(NULL));
    while(1){
        number=randNo();
        select = input();
        if((select-number)==1)
        {
            output(select,number);
            break;
        }
        else if(select==1&&number==3)
        {
            output(select,number);
            break;
        }
        else if(select==1&&number==3)
        {
            output(select,number);
        }
        else
        {
            output(select,number);
        }
       
    }
    printf("게임결과 %d승 %d 무\n",win,draw);
    return 0;
}

int randNo()
{
    int res;
    res = (rand()%3)+1;
    return res;
}

int input()
{
    int a,res;
    printf("# 바위는 1, 가위는 2, 보는 3 중에서 선택하세요:");
    res = scanf("%d",&a);
    while(1)
    {
        if(res==1)
        {
            if(a>=1&&a<=3)
            {
                break;
            }
            else{
                myflush();
                printf("# 바위는 1, 가위는 2, 보는 3 중에서 선택하세요:");
                res = scanf("%d",&a);
            }
        }
        else{
            myflush();
            printf("# 바위는 1, 가위는 2, 보는 3 중에서 선택하세요:");
            res = scanf("%d",&a);
        }
    }
    return a;
}
void output(int select,int number)
{
   
    switch(select){
        case 1:
            printf("당신은 바위 선택,");
            break;
        case 2:
            printf("당신은 가위 선택,");
            break;
        case 3:
            printf("당신은 보 선택,");
            break;
    }
    switch(number)
    {
        case 1:
            printf("컴퓨터는 바위 선택: ");
            break;
        case 2:
            printf("컴퓨터는 가위 선택: ");
            break;
        case 3:
            printf("컴퓨터는 보 선택: ");
            break;
    }
    if((select-number)==-1)
    {
        win ++;
        printf("이겼습니다.\n");
    }else if(select==number){
        draw ++;
        printf("비겼습니다.\n");
    }else if(select==3&&number==1){
        win ++;
        printf("이겼습니다.\n");
    }else{
        printf("당신이 졌습니다.\n");
    }
}

void myflush()
{
    while(getchar()!='\n')
    {
        ;
    }
}

