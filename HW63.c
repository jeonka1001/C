//
//  main.c
//  HW59_20190718
//
//  Created by 전경안 on 18/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
int input(int*);
int jollyjum(int,const int*);
void output(int,int*,int);

int main() {
    int a,num[100],jolly;
    a=input(num);
    jolly=jollyjum(a,num);
    output(jolly,num,a);
    return 0;
}

int input(int *num){
    int i,a;
    printf("숫자개수 및 수열을 입력하시오:");
    scanf("%d",&a);
    for(i=0;i<a;i++){
        scanf("%d",(num+i));
    }
    return a;
}

int jollyjum(int a,const int *num)
{
    int i,j=0,jolly[99],temp;
    for(i=1;i<a;i++){
        jolly[i-1]=*(num+i)-*(num+i-1);
        if(jolly[i-1]<0){
            jolly[i-1]=-jolly[i-1];
        }
    }
    while(j<a-1)
    {
      
        for(i=j+1;i<a-1;i++){
            if(jolly[j]<=jolly[i]){
                ;
            }else{
                temp=jolly[i];
                jolly[i]=jolly[j];
                jolly[j]=temp;
            }
        }
        j++;
    }
    for(i=1;i<a-1;i++){
        if(jolly[i]-jolly[i-1]!=1){
            return 0;
        }
        else{;}
    }
    return 1;
}

void output(int jolly,int *np,int a){
    int i;
    printf("검사한 수열 :");
    if(jolly==1){
        for(i=0;i<a;i++){
            printf("%4d",np[i]);
        }
        printf(" (jolly jumper)\n");
    }else{
        for(i=0;i<a;i++){
            printf("%4d",np[i]);
        }
         printf(" (N.O.T.! jolly jumper)\n");
    }
}
