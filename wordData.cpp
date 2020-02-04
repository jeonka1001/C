//
//  wordData.cpp
//  HW2_20200203
//
//  Created by 전경안 on 2020/02/03.
//  Copyright © 2020 전경안. All rights reserved.
//
#pragma warning (disable 4996)
#include "wordData.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <assert.h>

void strCopy(void *cp1,void *cp2){
    strcpy((char*)cp1,(char*)cp2);
}

void strPrint(void *cp){
    printf("%s /",(char*)cp);
}

void strClear(void *cp){
    cp = NULL;
}

int strCompare(void *cp1, void *cp2){
    if(strcmp((char*)cp1,(char*)cp2)>0){
        return 1;
    }
    else if(strcmp((char*)cp1,(char*)cp2)<0){
        return -1; // -1 의 경우 cp1 cp2 자리 버꾸기
    }
    else{
        return 0;
    }
}





