//
//  main.c
//  사람정보저장
//
//  Created by 전경안 on 25/07/2019.
//  Copyright © 2019 전경안. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define namesize 20
#define pssize 20
enum BOOL{FALSE, TRUE};

typedef struct {
    
}person;//4+9+3=16

typedef struct node Node;

struct node {
    char name[namesize];
    char blood[4];
    char password[pssize];
    int birth;
    Node *next;
};

typedef struct {
    Node *head;
    Node *tail;
    int size;
}List;//단일 연결 리스트 작성

enum BOOL createList(List *);
enum BOOL addlist(List *);
enum BOOL deletelist(List *);
void adddata(Node *);
void output(List *);
int menu(void);

int main() {
    int res,red,rea;
    List list;
    createList(&list);
    while(1){
        res=menu();
        switch(res){
            case 1:
                rea=addlist(&list);
                break;
            case 2:
                red=deletelist(&list);
                break;
            case 3:
                output(&list);
                break;
        }
    }
    return 0;
}

enum BOOL createList(List *lp){
    lp->head=(Node*)malloc(sizeof(Node));
    if(lp->head==NULL){
        return FALSE;
    }else{;}
    lp->tail=(Node*)malloc(sizeof(Node));
    if(lp->tail==NULL){
        free(lp->head);
        return FALSE;
    }
    lp->head->next=lp->tail;
    lp->tail->next=lp->tail;
    lp->size=0;
    return TRUE;
}

enum BOOL addlist(List *lp){
    Node *new;
    new = (Node*)malloc(sizeof(Node));
    if(new==NULL){
        return FALSE;
    }else {;}
    new->next=lp->head->next;
    lp->head->next=new;
    adddata(new);
    lp->size++;
    return TRUE;
}

void adddata(Node *new){
    printf("아이디를 입력하세요:");
    scanf("%s",new->name);
    
    printf("비밀번호를 입력하세요:");
    scanf("%s",new->password);
    
    printf("혈액형을 입력하세요:");
    scanf("%s",new->blood);
    
    printf("생년월일을 입력하세요:");
    scanf("%d",&(new->birth));
}

void output(List*lp){
    Node *crup;
    Node *tmp;
    crup=lp->head;
    tmp=crup->next;
    printf("총 저장된 데이터의 개수는 %d 입니다.\n",lp->size);
    while(tmp!=lp->tail){
        printf("아이디 : %s\n",tmp->name);
        printf("비밀 번호: %s\n",tmp->password);
        printf("나이 :%d\n",tmp->birth);
        printf("혈액형 :%s\n",tmp->blood);
        printf("========================");
        
        crup=tmp;
        tmp=tmp->next;
        printf("\n");
    }
}

int menu(){
    int i;
    printf("[회원 정보 관리 시스템]\n");
    printf("1.회원 가입/2.회원 탈퇴/3.회원 내역 :");
    scanf("%d",&i);
    getchar();
    return i;
}

enum BOOL deletelist(List *lp){
    Node *crup;
    Node *tmp;
    char delname[namesize];
    int ret;
    crup=lp->head;
    tmp=crup->next;
    printf("삭제 할 데이터의 아이디를 입력하세요.:");
    fgets(delname,namesize,stdin);
    delname[strlen(delname)-1]='\0';
    while(tmp!=lp->tail){
        ret=strcmp(tmp->name,delname);
        if(ret==0){
            crup->next=tmp->next;
            free(tmp);
            tmp=tmp->next;
            lp->size--;
            return TRUE;
        }
        crup=tmp;
        tmp=tmp->next;
    }
    printf("회원 정보가 정확하지 않습니다.\n");
    return FALSE;
}
