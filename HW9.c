//
//  main.c
//  HW9_20190628
//
//  Created by 전경안 on 28/06/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>

int input(void);

int a;

int main() {
    int number;
    number = input();
    printf("입력된 값은 8진수로 %#o입니다.\n",number);
    printf("입력된 값은 16진수로 %#x입니다.\n",number);
    return 0;
}

int input(){
    printf("정수값을 입력하세요:");
    scanf("%d",&a);
    return a;
}
