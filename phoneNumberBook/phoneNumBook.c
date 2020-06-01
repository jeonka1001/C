//
//  phoneNumBook.c
//  Day_0601
//
//  Created by 전경안 on 2020/06/01.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "phoneNumBook.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Person{
    char *name;
    char *num;
}Person;

Person* personInit(char* _name,char* _num){
    if(_name == NULL || _num == NULL){
        fprintf(stderr,"personInit : argument is NULL\n");
        return NULL;
    }
    Person *p = malloc(sizeof(Person));
    unsigned long nameLen = strlen(_name);
    unsigned long numLen = strlen(_num);
    p->name = malloc(sizeof(char)*nameLen);
    p->num = malloc(sizeof(char)*numLen);
    strcpy(p->name,_name);
    strcpy(p->num,_num);
    return p;
}

void setNumber(Person *p,char *_num){
    if(p == NULL || _num == NULL){
        fprintf(stderr,"setNumber : argument is NULL\n");
        return ;
    }
    unsigned long numLen = strlen(_num);
    free(p->num);
    p->num = malloc(sizeof(char)*numLen);
    strcpy(p->num,_num);
    return ;
}
void setName(Person *p,char *_name){
    if(p == NULL || _name == NULL){
        fprintf(stderr,"setName : argument is NULL\n");
        return ;
    }
    unsigned long nameLen = strlen(_name);
    free(p->name);
    p->name = malloc(sizeof(char)*nameLen);
    strcpy(p->name,_name);
    return ;
}
char* getNum(Person *p){
    if(p == NULL){
        fprintf(stderr,"getNum : argument is NULL\n");
        return NULL;
    }
    return p->num;
}
char* getName(Person* p ){
    if(p == NULL){
        fprintf(stderr,"persogetNamenInit : argument is NULL\n");
        return NULL;
    }
    return p->name;
}
char* toString(void *o){
    if(o == NULL){
        fprintf(stderr,"toString : argument is NULL\n");
        return NULL;
    }
    Person *p = o;
    static char buf[32];
    sprintf(buf,"%s(%s)",p->name,p->num);
    return buf;
}

int freePerson(void *o){
    if(o == NULL){
        fprintf(stderr,"freePerson : argument is NULL\n");
        return -1;
    }
    Person *p = o;
    free(p->name);
    free(p->num);
    free(p);
    return 0;
}

