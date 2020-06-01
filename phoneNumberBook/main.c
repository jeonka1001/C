//
//  main.c
//  Day_0601
//
//  Created by 전경안 on 2020/06/01.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "linkedlist.h"
#include "phoneNumBook.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef Node Node;
typedef Person Person;
int display(void);
void inputInfo(List* ,char *);
void updateInfo(List*,char *);
void displayInfo(const List*,PRINT_FUNC);
void searchInfo(const List*,char*);
void deleteInfo(List*, char*);
Node* findName(const List*,char*);

void myflush(void);

int main(){
    List *phoneBook = listInitialize(freePerson);
    if(phoneBook == NULL){
        return -1;
    }
    char msg[64];
    while(1){
        switch(display()){
            case 0:
                return 0;
            case 1:
                inputInfo(phoneBook,msg);
                fprintf(stderr,"%s",msg);
                getchar();
                break;
            case 2:
                updateInfo(phoneBook,msg);
                fprintf(stderr,"%s",msg);
                getchar();
                break;
            case 3:
                searchInfo(phoneBook, msg);
                fprintf(stderr,"%s",msg);
                getchar();
                break;
            case 4:
                deleteInfo(phoneBook,msg);
                fprintf(stderr,"%s",msg);
                getchar();
                break;
            case 5:
                displayInfo(phoneBook, toString);
                break;
            default:
                myflush();
                fprintf(stderr,"main : number select error\n");
                fprintf(stderr,"press enter key");
                getchar();
                break;
        }
        
    }
}

int display(){
    int sel = 0;
    while(1){
        system("clear");
        printf("#전화번호부 관리 프로그램#\n");
        printf("1.등록\n2.수정\n3.검색\n4.삭제\n5.목록\n");
        printf("----------------------------------\n");
        printf("메뉴(0. 종료) : ");
        if(scanf("%d",&sel)!=1){
            myflush();
            fprintf(stderr,"display : input number \n");
            fprintf(stderr,"press enter key");
            getchar();
        }
        else{break;}
    }
    getchar();
    return sel;
}

void myflush(){
    while(getchar() != '\n'){
        ;
    }
}

void inputInfo(List* phoneBook,char* msg){
    if(phoneBook == NULL){
        fprintf(stderr,"inputInfo : argument is NULL\n");
        return ;
    }
    
    char _name[32];
    char _num[32];
    printf("이름을 입력해주세요 : ");
    scanf("%s",_name);
    if(findName(phoneBook,_name)!=NULL){
        strcpy(msg,"already exist name, press enter key");
        return ;
    }
    printf("전화번호를 입력해주세요 : ");
    scanf("%s",_num);
    Person *p = personInit(_name, _num);
    getchar();
    if(p!=NULL){
        if(listAddHead(p, phoneBook)==0){
            strcpy(msg,"input success, press enter key");
            return ;
        }
    }
    strcpy(msg,"input failed, press enter key");
    getchar();
    return ;
}

void displayInfo(const List* pb,PRINT_FUNC pf){
    if(pb == NULL || pf == NULL ){
        fprintf(stderr,"displayInfo : argument is NULL\n");
        return ;
    }
    listDisplay(pb, pf);
    return;
}

Node* findName(const List *phoneBook,char* _name){
    if(phoneBook == NULL || _name==NULL){
        fprintf(stderr,"inputInfo : argument is NULL\n");
        return NULL;
    }
    int cnt = listCount(phoneBook);
    for(int i = 0 ; i < cnt;i++){
        Node* node = listGet(i,phoneBook);
        Person *p = getData(node);
        if(strcmp(getName(p),_name)==0){
            return node; // 이름이 있으면 1 반환
        }
    }
    return NULL;
}

void updateInfo(List* phoneBook,char *msg){
    if(phoneBook == NULL || msg == NULL ){
        fprintf(stderr,"inputInfo : argument is NULL\n");
        return ;
    }
    char _name[32] ;
    printf("수정할 사람의 이름을 적어주세요 : ");
    scanf("%s",_name);
    Node* node = findName(phoneBook,_name);
    if(node != NULL){
        printf("수정할 번호 입력 : ");
        char _num[32] ;
        scanf("%s",_num);
        setNumber(getData(node),_num);
        strcpy(msg,"update success, press enter key");
        return ;
    }
    strcpy(msg,"dose not exsit name, press enter key");
    getchar();
    return;
}

void searchInfo(const List* phoneBook, char* msg){
    if(phoneBook == NULL || msg == NULL ){
        fprintf(stderr,"inputInfo : argument is NULL\n");
        return ;
    }
    char _name[32] ;
    printf("검색할 사람의 이름을 적어주세요 : ");
    scanf("%s",_name);
    Node* node = findName(phoneBook,_name);
    if(node != NULL){
        printf("%s",toString(getData(node)));
        strcpy(msg,"press enter key");
        return ;
    }
    strcpy(msg,"dose not exsit name, press enter key");
    getchar();
    return ;
}

void deleteInfo(List* phoneBook,char* msg){
    if(phoneBook == NULL || msg == NULL ){
        fprintf(stderr,"inputInfo : argument is NULL\n");
        return ;
    }
    char _name[32] ;
    printf("삭제할 사람의 이름을 적어주세요 : ");
    scanf("%s",_name);
    Node* node = findName(phoneBook,_name);
    if(node != NULL){
        Person *outData = listRemoveData(phoneBook, node);
        printf("%s 님 삭제 완료.",toString(outData));
        strcpy(msg,"press enter key");
        return ;
    }
    strcpy(msg,"dose not exsit name, press enter key");
    getchar();
    return ;
}
