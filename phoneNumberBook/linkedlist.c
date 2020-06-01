//
//  linkedlist.c
//  Day_0601
//
//  Created by 전경안 on 2020/06/01.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char * (* PRINT_FUNC )(void*);
typedef int(*FreeFunc)(void *);
typedef struct Node{
    void* data;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct List{
    Node *head;
    Node *tail;
    int count;
    FreeFunc fp;
}List;

List* listInitialize(FreeFunc ffp){
    List* list = malloc(sizeof(List));
    if(list == NULL){
        perror("listInitialize");
        return NULL;
    }
    list->head = malloc(sizeof(Node));
    if(list->head == NULL){
        perror("listInitialize");
        free(list);
        return NULL;
    }
    list->tail = malloc(sizeof(Node));
    if(list->tail == NULL){
        perror("listInitialize");
        free(list->head);
        free(list);
        return NULL;
    }
    list->head->next = list->tail;
    list->head->prev = list->head;
    
    list->tail->prev = list->head;
    list->tail->next = list->tail;
    list->count = 0;
    list->fp = ffp;
    return list;
}

//void listFinalize(List *list){
//    if(list == NULL){
//        fprintf(stderr,"listFinalize : argument is null\n");
//        return ;
//    }
//
//}

int listAdd(void* data,List *list){
    Node *node = malloc(sizeof(Node));
    if(node == NULL){
        perror("listAdd");
        return -1;
    }
    node->data = data;
    node->next = list->tail;
    node->prev = list->tail->prev;
    
    list->tail->prev->next = node;
    list->tail->prev = node;
    
    list->count ++;
    return 0;
}

void listDisplay(const List *list,PRINT_FUNC printFunc){
    system("clear");
    Node *temp = list->head;
    printf("[head]");
    while(temp->next != list->tail){
        temp = temp->next;
        printf("<-->[%2s]",printFunc(temp->data));
    }
    printf("<-->[tail]");
    getchar();
    return ;
}

void listDisplayBack(const List *list,PRINT_FUNC printFunc){
    system("clear");
    Node *temp = list->tail;
    printf("[tail]");
    while(temp->prev != list->head){
        temp = temp->prev;
        printf("<-->[%2s]",printFunc(temp->data));
    }
    printf("<-->[head]\n");
    getchar();
    return ;
}

int listAddHead(void* data,List *list){
    Node *node = malloc(sizeof(Node));
    if(node == NULL){
        perror("listAddHead");
        return -1;
    }
    node->data = data;
    node->prev = list->head;
    node->next = list->head->next;
    
    list->head->next->prev = node;
    list->head->next = node;
    
    list->count ++;
    return 0;
}

Node* listGet(const int index,const List *list){
    Node *node = NULL;
    if(index < 0 || index >= list->count){
        printf("listInsert : out of index\n");
        return node;
    }
    if(index <= (list->count >> 1)){
        node = list->head;
        for(int i = 0; i <= index; i ++){
            node = node->next;
        }
    }
    else{
        node = list->tail;
        for(int i = list->count; i > index; i --){
            node = node->prev;
        }
    }
    return node;
    
}

void* getData(Node* node){
    if(node == NULL){
        fprintf(stderr,"getData : node is NULL\n");
        return NULL;
    }
    return node->data;
}

int listInsert(const int index,void* data,List *list){
    if(index < 0 || index >= list->count){
        printf("listInsert : out of index\n");
        return -1;
    }
    Node *node = malloc(sizeof(Node));
    if(node == NULL){
        perror("listInsert");
        return -1;
    }
    node->data=data;
    Node *cur ;
    cur = listGet(index,list);
    node->prev = cur->prev;
    node->next = cur;
    cur->prev->next = node;
    cur->prev = node;
    list->count ++;
    return 0;
}

int listCount(const List *list){return list->count;}

int listRemove(const int index, void **oldData,List *list){
    Node *cur ;
    if(oldData == NULL){
        perror("listRemove");
        return -1;
    }
    cur = listGet(index,list);
    *oldData=cur->data;
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    free(cur);
    list->count--;
    return 0;
}

int listRemoveTail(void **oldData,List *list){
    if( oldData == NULL){
        perror("listRemoveTail");
        return -1;
    }
    
    Node *cur = list->tail->prev;
    *oldData = cur->data;
    list->tail->prev = cur->prev;
    cur->prev->next = list->tail;
    free(cur);
    list->count--;
    return 0;
}
int listRemoveHead(void **oldData,List *list){
    if(oldData == NULL){
        perror("listRemoveHead");
        return -1;
    }
    Node *cur = list->head->next;
    *oldData = cur->data;
    list->head->next= cur->next;
    cur->next->prev = list->head;
    free(cur);
    list->count--;
    return 0;
}

void* listRemoveData(List* list, Node* node){
    if(list==NULL || node == NULL){
        fprintf(stderr,"listRemoveData : argument is null ");
        return NULL;
    }
    Node *prev = node->prev;
    Node *next = node->next;
    prev->next = next;
    next->prev = prev;
    void * outdata = node->data;
    free(node);
    return outdata;
}
