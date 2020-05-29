//
//  9.c
//  Day_0529
//
//  Created by 전경안 on 2020/05/29.
//  Copyright © 2020 전경안. All rights reserved.
//

//이중 연결 리스트
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node *head;
Node *tail;
int count;

int listInitialize(){
    head = calloc(1,sizeof(Node));
    if(head== NULL){
        perror(__func__);
        return -1;
    }
    tail = calloc(1,sizeof(Node));
    if(tail == NULL){
        perror(__func__);
        return -1;
    }
    head->prev = head;
    head->next = tail;
    
    tail->prev = head;
    tail->next = tail;
    count =0;
    return 0;
}

int addFront(int data){
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->prev = head;
    node->next = head->next;
    
    head->next->prev = node;
    head->next = node;
    
    count ++;
    return 0;
}

int addBack(int data){
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = tail;
    node->prev=tail->prev;
    
    tail->prev->next = node;
    tail->prev = node;
    
    count ++;
    return 0;
}

int dataInsert(int data, int index){
    Node *node = malloc(sizeof(Node));
    node->data=data;
    
    Node *cur ;
    if(count/2 >index){
        cur = head;
        for(int i = 1; i<=index;i++){
            cur = cur->next;
        }
    }
    else{
        cur = tail;
        for(int i = count; i >= index ; i--){
            cur=cur->prev;
        }
    }
    node->prev = cur->prev;
    node->next = cur;
    cur->prev->next = node;
    cur->prev = node;
    count ++;
    return 0;
}

int dataUpdate(int newData, int *oldData, int index){
    Node *cur ;
    if(count/2 >index){
        cur = head;
        for(int i = 1; i<=index;i++){
            cur = cur->next;
        }
    }
    else{
        cur = tail;
        for(int i = count; i >= index ; i--){
            cur=cur->prev;
        }
    }
    *oldData = cur -> data;
    cur->data=newData;
    return 0;
}
int printList(){
    system("clear");
    Node *temp = head;
    printf("[head]");
    while(temp->next != tail){
        temp=temp->next;
        printf("->[%2d]",temp->data);
    }
    printf("->[tail]");
    getchar();
    return 0;
}

int dataDelete(int *oldData,int index){
    Node *cur ;
    if(count/2 >index){
        cur = head;
        for(int i = 1; i<=index;i++){
            cur = cur->next;
        }
    }
    else{
        cur = tail;
        for(int i = count; i >= index ; i--){
            cur=cur->prev;
        }
    }
    *oldData=cur->data;
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    free(cur);
    return 0;
}

int main(){
    listInitialize();
    printList();
    for(int i = 0 ; i < 5; i ++){
        addBack(i+1);
        printList();
    }
    addFront(99);
    printList();
    dataInsert(77,3);
    printList();
    int oldData;
    dataUpdate(25, &oldData, 5);
    printList();
    printf("이전 : %d, 변경 후 : 25\n",oldData);
    dataDelete(&oldData, 2);
    printf("삭제 : %d\n",oldData);
    printList();
    return 0;
    
}
