//
//  main.c
//  dsds
//
//  Created by 전경안 on 2019/12/29.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>

int calc(int,int);

int main() {
    int a,b,g;
    long long int l;
    printf("두 수 입력");
    scanf("%d %d",&a,&b);
    g=calc(a,b);
    l=g*(a/g)*(b/g);
    printf("최대공약수는 %d, 최소공배수는 %lld입니다.\n",g,l);
    return 0;
}

int calc(int a,int b){
    int r;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
