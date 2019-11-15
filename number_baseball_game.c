//
//  main.c
//  Baseball game
//
//  Created by 전경안 on 16/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomnumber(int *);
void inputnumber(int *,int*);
int gamestart(int*,int*,int*,int*);
void endgame(int*);
void myflush(void);

int main() {
    int number[4],innum[4],res;
    int strike=0,ball=0,i,count=1;
    srand((unsigned int)time(NULL));
    randomnumber(number);
    while(1){
        inputnumber(innum,number);
        res = gamestart(number,innum,&strike,&ball);
        if(res==0){
            break;
        }
        else{
            switch(res){
                case 1:
                    printf("OUT\n");
                    count++;
                    break;
                case 2:
                    printf("\'%d\'STRIKE \'%d\'BALL\n",strike,ball);
                    count++;
                    break;
                default :
                    for(i=0;i<=3;i++){
                        printf ("%3d",*(number+i));
                    }
                    break;
            }
        }
    } endgame:
    printf("축하합니다! 정답 :");
    for(i=0;i<=3;i++){
        printf ("%3d",*(number+i));
    }
    printf(" 를 %d번째만에 맞추셨습니다!\n",count);
    return 0;
}

void randomnumber(int *a)
{
    int i,j=0;
    
    for(i=0;i<=3;i++){
        *(a+i)=rand()%10;
        if(i>0){
            while(1){
                if(i==j){
                    j=0;
                    break;
                }
                else{
                    if(a[i]==a[j]){
                        a[i]=rand()%10;
                        j=0;
                    }
                    else{
                        j++;
                    }
                }
            }
        }
        else{;}
    }
    
    /*for(i=0;i<=3;i++){
        printf("%d",*(a+i));
    }*/
}

void inputnumber(int *ip,int *a){//==1
    int res,i,j;
    for (i=0;i<=3;i++){
        while(1){
            printf(" %d 번째 숫자를 입력하세요(0-9):",i+1);
            res=scanf("%d",ip+i);
            if(ip[i]==96){
                goto endgame;
            }
            if(res==1&&getchar()=='\n')
            {
                if(*(ip+i)>=0&&*(ip+i)<=9)
                {
                    if(i>=1){
                        for(j=0;j<i;j++)
                        {
                            if(res==1&&(ip[i]==ip[j])){
                                printf("전에 입력했던 숫자와 중복되지 않은 %d 번째 숫자를 입력하세요(0-9):",i+1);
                                res=scanf("%d",(ip+i));
                                j=-1;
                            }
                            else{
                                if(res!=1){
                                    myflush();
                                    printf(" %d 번째 \'숫자\'를 입력하세요(0-9):",i+1);
                                    res=scanf("%d",(ip+i));
                                    j=-1;
                                }
                                else
                                {
                                    ;
                                }
                            }
                        }
                    }
                    else{;}
                    break;
                }
                else{;}
            }
            else{
                myflush();
            }
        }
    }
    if(ip[i]==99){
    endgame:
        for(i=0;i<=3;i++){
            printf("%d",*(a+i));
        }
    }
    //printf("%d %d %d %d",*(ip+0),*(ip+1),*(ip+2),*(ip+3));//입력값 체크
}

int gamestart(int *np,int *ip,int *strike,int *ball){
    int i=0,j,scount=0,bcount=0;
    while(i<=3){
        for(j=0;j<=3;j++){
            if(*(np+i) == *(ip+j)){
                if(i==j){
                    scount ++;
                }
                else{
                    bcount ++;
                }
            }else{
                ;
            }
        }
        i++;
    }
    if(scount==0&&bcount==0){
        return 1;
    }else if(scount==4){
        return 0;
    }
    else{
        *strike = scount;
        *ball = bcount;
        return 2;
    }
}

void myflush(){//stdin 잔여 데이터 확인
    while(getchar()!='\n'){
        ;
    }
}

