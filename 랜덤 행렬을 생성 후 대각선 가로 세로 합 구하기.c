//
//  main.c
//  HW56_20190715
//
//  Created by 전경안 on 15/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void randomnumber (int(*)[5]);
void output(int(*)[5]);

int main() {
    int number[5][5];
    srand((unsigned int)time(NULL));
    randomnumber(number);
    output(number);
    
    
    return 0;
}
void randomnumber(int (*np)[5]){
    int i,j;
    for(j=0;j<=4;j++){
        for(i=0;i<=4;i++){
            *(*(np+i)+j) = (rand()%20)+1;
        }
    }
}
void output(int (*num)[5]){
    int i,j,sum1=0,sum2=0,sum3=0;
    for(j=0;j<=4;j++){
        for(i=0;i<=4;i++){
            printf("%d\t",*(*(num+i)+j));
            if(i==j){
                sum1+=*(*(num+i)+j);
            }else if(i<j){
                sum2+=*(*(num+i)+j);
            }else{
                sum3+=*(*(num+i)+j);
            }
        }
        printf("\n");
    }
    printf("삼각형 상단 합 = %d\n",sum2);
    printf("대각선 합 = %d\n",sum1);
    printf("삼각형 하단 합 = %d\n",sum3);
}
