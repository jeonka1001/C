//
//  main.c
//  HW25_20190704
//
//  Created by 전경안 on 04/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int randomnum(void);
int input(void);
void output(int);

void myflush(void);

int sw,num,randnum;//num=사용자가입력하는수, randnum=random number
int num2=0,num3=100;//num2=작은값,num3큰값

int main() {
    
    int count=1,al;
    
    srand((unsigned int)time(NULL));
    randnum = randomnum();
    num = input();
    while(num!=randnum)
    {
        if(num>randnum){
            sw=1;
            output(sw);
            count++;
            al=input();
            if(num>al&&al>num2){
                if(al>randnum){
                    num=al;
                }else if(al<randnum){
                    num2=al;
                }else{
                    break;
                }
            }
            else{
                sw=3;
                output(sw);
            }
        }
        else if(num<randnum){
            sw=2;
            output(sw);
            count++;
            al=input();
            if(al>num&&al<num3){
                if(al>randnum){
                    num3=al;
                }else if(al<randnum){
                    num=al;
                }else {
                    break;
                }
            }
            else{
                sw=3;
                output(sw);
            }
        }
        else{
            break;
        }
    }
    printf("축하합니다 %d번째로 정답을 맞추셨습니다.\n",count);
    return 0;
}

int randomnum()
{
    int randn;
    randn=(rand()%100)+1;
    return randn;
}

int input(void)
{
    int a,res;
    
    printf("숫자를 입력해 주세요:");
    res = scanf("%d",&a);
    
    while(1)
    {
        if(res==1){
            if(a<=100&&a>=1){
                break;
            }
            else{
                myflush();
                printf("ERROR) 범위를 준수하여 입력해주십시오(1~100):");
                res = scanf("%d",&a);
            }
        }
        else{
            myflush();
            printf("\'양수\' 를 입력해 주세요:");
            res = scanf("%d",&a);
        }
    }
    return a;
}

void output(int sw)
{
    switch(sw)
    {
        case 1:
            printf("Tip)%d보다 크고 %d보다 작습니다.\n",num2,num);
            break;
        case 2:
            printf("Tip)%d보다 크고 %d보다 작습니다.\n",num,num3);
            break;
        case 3:
            printf("ERROR)아래에 \'팁\' 을 다시 한번 봐주십시오.(Count+=1)\n");
            break;
    }
}

void myflush()
{
    while(getchar()!='\n')
    {
        ;
    }
}

