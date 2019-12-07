//
//  main.c
//  HW54_20190717
//
//  Created by 전경안 on 17/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int input(char *);
int calculate(char *,int);
void output(int,char*);
int main() {
    char num[100],count;
    char end[]="end";
    int sum;
    while(1){
        count=input(num);
        if(strcmp(num,end)==0){
            break;
        }
        sum=calculate(num,count);
        output(sum,num);
        
    }
    return 0;
}

int input(char *num)
{
    int i=0,count=0;
    printf("문장을 입력하시오.:");
    while(1){
        scanf("%c",num+i);
        count++;
        if(*(num+i)=='\n'){
            *(num+i)='\0';
            break;
        }
        i++;
    }
    return count;
}

int calculate(char *np,int count){
    int j=0,i,num[100],numcount=0,sum=0,k,ii,numcount1;
    for(i=0;i<count;i++){
        k=0;
        if(*(np+i)>='0'&&*(np+i)<='9'){
            num[j]= *(np+i)-'0';
            numcount++;
            j++;

        }
       
        else{
            numcount1=numcount;
            if(numcount!=0){
                for(ii=j-numcount;ii<=j-1;ii++){//방 읽기
                    while(k<numcount1-1){//자릿수
                        num[ii]*=10;
                        k++;
                    }
                    sum+=num[ii];
                    numcount1--;
                    k=0;
                }
            }
            else{;}
            numcount=0;
        }
    }
    return sum;
}

void output(int sum,char *num){
    printf("\"%s\"내의 총 숫자는 [%d] 입니다.\n",num,sum);
}
