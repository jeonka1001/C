//
//  main.c
//  HW57_20190718
//
//  Created by 전경안 on 18/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
#include <string.h>
void input(char (*)[20]);
void sort(char(*)[20]);
void output(char(*)[20]);
int main() {
    char str[5][20];
    input(str);
    sort(str);
    output(str);
    return 0;
}

void input(char (*sp)[20])
{
    int i;
    for(i=0;i<=4;i++){
        printf("%d번 문자열을 입력하시오:",i+1);
        scanf("%s",*(sp+i));
    }
}

void sort(char(*sp)[20]){
    int res,i,j;
    char tmp[20];
    i=0;
    while(i<4){
        for(j=i+1;j<=4;j++){
            res = strcmp(*(sp+i),*(sp+j));
            //printf("[%d]\n",res); 코드가 잘 동작하는지 확인하기 위해 넣은 코드
            if(res>0){
                strcpy(tmp,*(sp+j));
                strcpy(*(sp+j),*(sp+i));
                strcpy(*(sp+i),tmp);
            }else if(res<0){
                ;
            }else{;}
        }
        i++;
    }
}
void output(char(*sp)[20])
{
    int i;
    unsigned long str;
    for(i=0;i<=4;i++)
    {
        str = strlen(sp[i]);
        printf("str[%d] = %s",i,*(sp+i));
        printf("%2c %2c\n",sp[i][0],sp[i][str-1]);
    }
}
