//
//  main.c
//  void pointer sort
//
//  Created by 전경안 on 2020/01/29.
//  Copyright © 2020 전경안. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<memory.h> // memcpy()함수를 쓰기위해 include
#include<string.h>
void genericSort(void*, int, size_t, int (*)(void*, void*));
void display(void*, int, size_t, void (*)(void*));
int integerCompare(void*, void*);
int doubleCompare(void*, void*);
int stringCompare(void*, void*);
void integerPrint(void*), doublePrint(void*), stringPrint(void*);
//-------------------------------------------------------------------
int main()
{
    
    //정수형데이터 정렬하여 출력하기
    int iArray[10] = { 5,2,9,11,1,8,10,15,20,3 };
    genericSort(iArray, sizeof(iArray) / sizeof(iArray[0]), sizeof(iArray[0]),
                integerCompare);
    printf("[[정수형 데이터 정렬하여 출력하기]]\n");
    display(iArray, sizeof(iArray) / sizeof(iArray[0]), sizeof(iArray[0]),
            integerPrint);
    
    //실수형데이터 정렬하여 출력하기
    double dArray[5] = { 12.5, 3.12, 7.7, 20.35, 9.8 };
    genericSort(dArray, sizeof(dArray) / sizeof(dArray[0]), sizeof(dArray[0]),
                doubleCompare);

    printf("[[실수형 데이터 정렬하여 출력하기]]\n");
    display(dArray, sizeof(dArray) / sizeof(dArray[0]), sizeof(dArray[0]),
            doublePrint);

    //문자열형데이터 정렬하여 출력하기
    char sArray[7][10] = { "희망", "꿈", "도전", "용기", "노력", "믿음",
        "협력" };
    genericSort(sArray, sizeof(sArray) / sizeof(sArray[0]), sizeof(sArray[0]),
                stringCompare);
    printf("[[문자열형 데이터 정렬하여 출력하기]]\n");
    display(sArray, sizeof(sArray) / sizeof(sArray[0]), sizeof(sArray[0]),
            stringPrint);
    return 0;
}

void genericSort(void *data ,int num ,size_t size ,int (*workFun)(void*,void*)){
    void *begin=data;
    void *end=(char*)data+(num-1)*size;
    void *nextdata=(char*)data+size;
    int res;
    while(begin!=end){
       
        res=workFun(data,nextdata);
        if(res==1){
            data=nextdata;
            nextdata=(char*)data+size;
        }
        else if(res==-1){
            data=nextdata;
            nextdata=(char*)data+size;
        }
        else{
            end=(char*)end-size;
            data=begin;
            nextdata=(char*)data+size;
        }
        if(nextdata==end){
            data=nextdata;
        }
    }
}
void display(void *data ,int num ,size_t size ,void (*workFun)(void*)){
    void *end=(char*)data+(num-1)*size;
    while(data!=end){
        workFun(data);
        data=(char*)data+size;
    }
    printf("\n");
}
/////int 관련 함수////////////////////////////
int integerCompare(void *vp1,void *vp2){
    int *p1=(int*)vp1;
    int *p2=(int*)vp2;
    int tmp;
    if(*p1==*p2){
        return 0;
    }
    else{
        if(*p1>*p2){
            tmp=*p1;
            *p1=*p2;
            *p2=tmp;
            return 1;
        }
        else{
            return -1;
        }
    }
}
void integerPrint(void *vp){
    printf("%d\n",*(int*)vp);
}
//double 관련 함수///////////////////////////////
int doubleCompare(void *vp1,void *vp2){
    double *p1=(double*)vp1;
    double *p2=(double*)vp2;
    double tmp;
    if(*p1==*p2){
        return 0;
    }
    else{
        if(*p1>*p2){
            tmp=*p1;
            *p1=*p2;
            *p2=tmp;
            return 1;
        }
        else{
            return -1;
        }
    }
}
void doublePrint(void *vp){
    printf("%.2lf\n",*(double*)vp);
}
/////char 관련 함수///////////////////

int stringCompare(void *vp1,void *vp2){
    char *p1=(char*)vp1;
    char *p2=(char*)vp2;
    char *tmp[10];
    if(strcmp(p1,p2)==0){
        return 0;
    }
    else{
        if(strcmp(p1,p2)>0){
            memcpy(tmp,p1,10);
            memcpy(p1,p2,10);
            memcpy(p2,tmp,10);
            return 1;
        }
        else{
            return -1;
        }
    }
}
void stringPrint(void *vp){
    printf("%s\n",(char*)vp);
}
