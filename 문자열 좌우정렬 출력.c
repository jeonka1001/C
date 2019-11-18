//
//  main.c
//  HW12_20190703
//
//  Created by 전경안 on 03/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main() {
    char name[20];
    
    printf("이름을 입력하세요:");
    fgets(name,sizeof(name),stdin);
    name[strlen(name)-1]=NULL;
    
    printf("\"%s\"\n",name);
    printf("\"%20s\"\n",name);
    printf("\"%-20s\"\n",name);
    return 0;
}

