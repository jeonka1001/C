//
//  main.c
//  HW23_20190703
//
//  Created by 전경안 on 03/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>

int main() {
    int a,b,res,n;
   
    while(1)
    {
        printf("두개의 정수를 입력하세요:");
        n = scanf("%d %d",&a,&b);
        
        if(n!=2)
        {
            break;
        }
        else if(a>=b)
        {
            res=a-b;
            printf("%d - %d = %d\n",a,b,res);
        }
        else{
            res=b-a;
            printf("%d - %d = %d\n",b,a,res);
        }
    }
    printf("계산을 종료합니다.\n");
    return 0;
}
