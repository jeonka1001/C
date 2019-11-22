//
//  main.c
//  HW31_20190708
//
//  Created by 전경안 on 08/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>

void menu(char*);//메뉴 입력을 위함
void inputInt(char*);//입금출력 출금출력 오류출력
void deposit(int*);//단순 입금 계산
void withdraw(int*);//단순 출금 계산
void myflush(void);

int main() {
    char setting;
    int money=0;
    
    while(1){
        menu(&setting);
        inputInt(&setting);
        if(setting=='i')
        {
            deposit(&money);
        }
        else if(setting=='o')
        {
            withdraw(&money);
        }else{
            break;
        }
    }
    printf("은행 업무 시스템을 종료합니다.\n");
    
    return 0;
}

void menu(char *option){
    printf("# 메뉴를 선택하세요(i-입금,o-출금,q-종료):");
    scanf(" %c",&*option);
}

void inputInt(char *option)
{
    while(*option!='q'){
        if(*option=='i'||*option=='o'||*option=='q')
        {
            break;
        }
        else
        {
            myflush();
            printf("*잘못 입력하였습니다.\n# 메뉴를 선택하세요(i-입금,o-출금,q-종료):");
            scanf("%c",option);
        }
    }
}
void deposit(int *inmoney){
    int res,intemp;
    
    printf("#입금액을 입력해 주세요:");
    
    while(1){
        res=scanf("%d",&intemp);
        if(res==1)
        {
            if(intemp>=0&&getchar()=='\n')
            {
                *inmoney+=intemp;
                printf("당신의 현재 잔액은 %d 입니다.\n",*inmoney);
                break;
            }else{
                myflush();
                printf("다시 입력해주세요:");
            }
        }else{
            myflush();
            printf("다시 입력해주세요:");
        }
    }
}
void withdraw(int *outmoney)
{
    int res,outtemp;
    printf("#출금 할 금액을 입력해 주세요:");
    while(1){
        res = scanf("%d",&outtemp);
        if(res == 1&&outtemp>=0)
        {
            if(getchar()=='\n')
            {
                if(outtemp<*outmoney)
                {
                    *outmoney-=outtemp;
                    printf("현재 잔액은 %d 입니다.\n",*outmoney);
                    break;
                }
                else{
                    printf("잔액이 부족합니다\n*현재 잔액은 %d 입니다.\n",*outmoney);
                    break;
                }
            }
            else{
                myflush();
                printf("잘못 입력하였습니다. 다시 입력하십시오:");
            }
        }
        else{
            myflush();
            printf("잘못 입력하였습니다. 다시 입력하십시오:");
        }
    }
}

void myflush(){
    while(getchar()!='\n')
    {
        ;
    }
}
