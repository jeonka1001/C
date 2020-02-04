//
//  doublelyLinkedlist.c
//  Generic list code
//
//  Created by 전경안 on 2020/02/01.
//  Copyright © 2020 전경안. All rights reserved.
//


#pragma once
#pragma warning (disable : 4996)
#include <stdlib.h>
//typedef int BOOL;
enum BOOL{FALSE, TRUE};
typedef struct _node Node;                /* 구조체 노드 형명재지정 */
struct  _node {/* 노드 구조체 (자기참조 구조체 사용) */
    Node *prev;                        // 앞 노드를 가리키는 포인터 영역
    Node *next;                            /* 다음 노드를 가리키는포인터 영역 */
};
typedef  struct  _list {                 /* 연결 리스트 관리 구조체 */
    Node *head;                            /* head pointer (head node 가리킴) */
    Node *tail;                         /* tail pointer (tail node 가리킴) */
    int size;                            /* 연결 리스트의 크기 - 실제 data node의 개수 */
}List;

BOOL createList(List *lp);                    /* 연결 리스트 초기화 */
BOOL addFirst(List *lp, void *data, size_t size, void(*Memcpy)(void*, void*));            /* head node 뒤에 node 추가(역순 저장) */
BOOL addLast(List *lp, void* data, size_t dataSize, void(*Memcpy)(void*, void*));            /* tail node 앞에 node 추가(정순 저장) */
void displayList(List *lp,void(*Print)(void*));                    /* 리스트 내의 모든 데이터 출력 */
BOOL removeNode(List *lp, void* data, int(*comPare)(void*, void*), void(*clear)(void*));        /* data 노드 삭제 */
Node * searchNode(List *lp, void* data, int(*comPare)(void*, void*));        /* data와 일치하는 node 검색 */
void sortList(List *lp, int(*comPare)(void*,void*),void(MemCopy)(void*,void*));                    /* 노드 정렬 - 오름차순 */
void destroyList(List *lp);                    /* 리스트 내의 모든 노드를 삭제 */
