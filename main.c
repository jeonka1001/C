//
//  main.c
//  2xN 타일 채우기
//
//  Created by 전경안 on 2019/11/18.
//  Copyright © 2019 전경안. All rights reserved.
// 문제) 2xN크기의 타일을 2x1,1x2의 타일로 채우려 한다. 채울 수 있는 방법의 총 합은?

#include <stdio.h>

int input(void);
int calc(int,int);
int upnum(int,int);
int downnum(int);

int main() {
    int rnum,n,count=0;
    n = input();
    rnum=calc(n,count);
    printf("%d\n",rnum%10007);
    return 0;
}
int input(){
    int num;
    printf("숫자줘:");
    scanf("%d",&num);
    return num;
}

int calc(int n,int count){
    int cnum;
    cnum=upnum(n,n-count)/downnum(n-count);
    if((n-count)==1){
        return n;
    }
    else if((n-count)==0){
        return 1;
    }
    else{
        count++;
        n--;
        return cnum+calc(n,count);
    }
}
int upnum(int n,int count){
    int i=1,ans=1;
    while(i<=count){
        ans*=n;
        n--;
        i++;
    }
    return ans;
}
int downnum(int count){
    int i=1,ans=1;
    while(i<=count){
        ans*=i;
        i++;
    }
    return ans;
}


