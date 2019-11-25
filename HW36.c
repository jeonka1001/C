//
//  main.c
//  HW36_20190711
//
//  Created by 전경안 on 11/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
void input(int*);

int main() {
    int number,i,temp,ary1,ary2,sum;
    ary1=1;ary2=1;
    sum=2;
    input(&number);
    
    if(number!=1){
        printf("%d + %d ",ary1,ary2);
        for(i=1;i<number-1;i++)
        {
            temp=ary1;
            ary1=ary2;
            ary2+=temp;
            sum+=ary2;
            printf("+ %d ",ary2);
        }
        printf("= %d\n",sum);
    }
    else{
        printf("1 = 1\n");
    }
    
    return 0;
}

void input(int *np)
{
    printf("피보나치 수열의 항수를 입력하시오:");
    scanf("%d",np);
    while(1){
        if(*np>=1&&*np<=30)
        {
            break;
        }else{
            scanf("%d",np);
        }
    }
}
