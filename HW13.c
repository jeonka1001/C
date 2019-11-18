//
//  main.c
//  HW13_20190703
//
//  Created by 전경안 on 03/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main() {
    
    char name[100],first[100];
    
    printf("성을 입력하세요:");
    scanf("%s",first);
    
    
    printf("이름을 입력하세요:");
    scanf("%s",name);
    
    
    printf("%s %s\n",first,name);
    
    printf("%*u %*u\n",(int)strlen(first),(unsigned)strlen(first),(int)strlen(name),(unsigned)strlen(name));
    return 0;
}
