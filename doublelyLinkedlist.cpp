//
//  doublelyLinkedlist.cpp
//  HW2_20200203
//
//  Created by 전경안 on 2020/02/03.
//  Copyright © 2020 전경안. All rights reserved.
//

#include "doublelyLinkedlist.h"
#include "wordData.h"
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()
#include <memory.h>
/*----------------------------------------------------------------------------------
 Function name    : createList - 연결 리스트 생성 및 초기화
 Parameters        : lp - 리스트 관리 구조체의 주소
 Returns            : 성공 - TRUE / 실패 - FALSE
 ----------------------------------------------------------------------------------*/
BOOL createList(List *lp)
{
    if (lp == NULL) {  /* lp포인터 NULL check */
        return FALSE;
    }
    lp->head = (Node *)malloc(sizeof(Node));    /* head node 생성 */
    if (lp->head == NULL) {
        return FALSE;
    }
    lp->tail = (Node *)malloc(sizeof(Node));    /* tail node 생성 */
    if (lp->tail == NULL) {
        free(lp->head);
        return FALSE;
    }
    
    lp->head->next = lp->tail; /* head node와 tail node 연결 */
    lp->tail->next = lp->tail; /* tail node의 next는 자기 자신을 가리키도록 설정 */
    lp->head->prev = lp->head; // head node의 prev는 자기 자신을 가리키도록 설정 (tail의 next와 같다.)
    lp->tail->prev = lp->head; // tail node와 head node를 연결해주는 코드
    lp->size = 0;    /* 연결 리스트 크기 0으로 초기화 */
    
    return TRUE;
}

/*----------------------------------------------------------------------------------
 Function name    : addFirst - head node 뒤에 node 추가(역순 저장)
 Parameters        : lp - 리스트 관리 구조체의 주소
 data - 추가할 데이터
 Returns            : 성공 - TRUE / 실패 - FALSE
 ----------------------------------------------------------------------------------*/
BOOL addFirst(List *lp, void *data , size_t dataSize , void(*Memcpy)(void*,void*))
{
    Node *newp;
    
    if (lp == NULL) { /* lp포인터 NULL check */
        return FALSE;
    }
    
    newp = (Node *)malloc(sizeof(Node)+dataSize); /* 새 노드 생성 */
    if (newp != NULL) {                /* 새 노드 생성 성공 시 처리 */
        Memcpy(newp + 1, data);        /* 새 노드에 data 저장 */
        newp->next = lp->head->next; /* 새 노드의 next 설정 */
        lp->head->next = newp;    /* head ndoe 뒤에 새 노드 연결 */
        newp->next->prev = newp; //newp->next (= 기존 데이터) 의 prev =>> 새로 추가될 노드를 가리켜야 함.
        newp->prev = lp->head; // 앞쪽에 추가할 것 이기 때문에 새 데이터의 prev 는 head를 가리켜야 함.
        
        ++lp->size;                    /* 리스트 size 증가 */
        return TRUE;
    }
    else {                            /* 새 노드 생성 실패 시 처리 */
        return FALSE;
    }
}
/*----------------------------------------------------------------------------------
 Function name    : addLast - tail node 앞에 새 node 추가(정순 저장)
 Parameters        : lp - 리스트 관리 구조체의 주소
 data - 추가할 데이터의 주소
 dataSize - 데이터 하나의 크기
 Memcpy - 멤버 복사를 위한 함수의 주소 포인터
 Returns            : 성공 - TRUE / 실패 - FALSE
 ----------------------------------------------------------------------------------*/
BOOL addLast(List *lp, void* data,size_t dataSize, void(*Memcpy)(void*,void*))
{
    Node *newp;    /* 새 노드 주소저장용 포인터 */
    if (lp == NULL) { /* lp포인터 NULL check */
        return FALSE;
    }
    
    newp = (Node *)calloc(1,sizeof(Node)+dataSize);    /* 새 노드 생성 */
    if (newp != NULL) {    /*  새 노드 생성 성공 시 처리 */
        Memcpy(newp + 1, data);//새 노드의 데이터 영역에 주소를 계산해서 data를 복사
        
        newp->next = lp->tail;    /* 새 노드의 next 설정 */
        newp->prev = lp->tail->prev;// 새 노드의 prev 설정
        
        lp->tail->prev->next = newp;
        lp->tail->prev = newp;
        // 85랑 83이랑 바뀐다면?
        ++lp->size;    /* 리스트 size 증가 */
        return TRUE;
    }
    else {    /* 새 노드 생성 실패 시 처리 */
        return FALSE;
    }
}

/*----------------------------------------------------------------------------------
 Function name    : displayList - 리스트 내의 모든 데이터 출력
 Parameters        : lp - 리스트 관리 구조체의 주소
 Returns            : 없음
 ----------------------------------------------------------------------------------*/
void displayList(List *lp,void(*Print)(void*))
{
    Node *curp;
    
    if (lp == NULL) { /* lp포인터 NULL check */
        return;
    }
    
    curp = lp->head->next;  /* data 있는 첫노드를 curp로 가리키게 함 */
    
    /* 리스트의 마지막 노드까지 curp를 옮기면서 data영역 출력하기 */
    while (curp != lp->tail) {
        Print(curp + 1);
        curp = curp->next;
    }
    printf("\n");
    
    return;
}

/*----------------------------------------------------------------------------------
 Function name    : searchNode - data와 일치하는 첫 번째 node 검색
 Parameters        : lp - 리스트 관리 구조체의 주소
 data - 검색할 데이터의 시작주소
 comPare - 데이터의 값을 비교하는 함수
 Returns            : 성공 - 검색된 노드의 주소 / 실패 - NULL pointer
 ----------------------------------------------------------------------------------*/
Node * searchNode(List *lp, void* data,int (*comPare)(void*,void*))
{
    Node *curp;
    if (lp == NULL) { /* lp포인터 NULL check */
        return NULL;
    }
    
    curp = lp->head->next;/* data첫노드를 curp로 가리키게 함 */
    /* 리스트의 마지막 데이터 노드까지 curp를 옮기면서 검색하기 */
    while (curp != lp->tail) {
        if (comPare(curp+1,data)==0)//curp는 노드 자체 따라서 +1을 해서 동적할당 받은 메모리를 보내야 함
        {
            return curp;    /* 찾은 노드의 주소 리턴 */
        }
        else {
            curp = curp->next;//다음 노드로 이동(curp+1 = 데이터 / curp + next = 다음노드)
        }
    }
    
    return NULL;    /* 못찾으면 NULL pointer 리턴 */
}
/*----------------------------------------------------------------------------------
 Function name    : removeNode - data와 일치하는 첫 번째 노드 삭제
 Parameters        : lp - 리스트 관리 구조체의 주소
 data - 삭제할 데이터
 Returns            : 성공 - TRUE / 실패 - FALSE
 ----------------------------------------------------------------------------------*/
BOOL removeNode(List *lp, void* data,int(*comPare)(void*,void*),void(*clear)(void*))
{
    Node *delp;
    if (lp == NULL) { /* lp포인터 NULL check */
        return FALSE;
    }
    delp = searchNode(lp, data,comPare);  /* 삭제할 node를 검색 함 */
    if (delp != NULL) { /* 삭제할 노드를 찾았으면 삭제하기 */
        delp->prev->next = delp->next;
        delp->next->prev = delp->prev;
        
        clear(delp + 1);//+1이 없을시 prev와 next 삭제됨.
        
        free(delp);    /* 노드 삭제 */
        --lp->size;    /* 리스트 size 감소 */
        return TRUE;
    }
    else {    /* 삭제할 노드의 못찾았으면 삭제 실패 */
        return FALSE;
    }
}
/*----------------------------------------------------------------------------------
 Function name    : sortList - 노드 정렬(오름차순)
 Parameters        : lp - 리스트 관리 구조체의 주소
 Returns            : 없음
 ----------------------------------------------------------------------------------*/
void sortList(List *lp, int(*comPare)(void*,void*),void(MemCopy)(void*,void*))
{
    char temp[W_LEN];
    Node *sortNode,*startNode;
    sortNode = lp->head->next;
    startNode = lp->head->next;
    if (lp == NULL) { /* lp포인터 NULL check */
        return;
    }
    while(1){
        if(comPare(sortNode+1,(sortNode->next)+1)<0){
            sortNode=sortNode->next;
        }
        else if(comPare(sortNode+1,(sortNode->next)+1)>0){
            MemCopy(&temp,sortNode+1);
            MemCopy(sortNode+1,(sortNode->next)+1);
            MemCopy((sortNode->next)+1,&temp);
            sortNode=sortNode->next;
        }
        else{
            sortNode=sortNode->next;
        }
        if(sortNode->next == lp->tail){
            startNode = startNode->next;
            sortNode = startNode;
            if(startNode==lp->tail->prev){
                return;
            }
        }
    }
}
/*----------------------------------------------------------------------------------
 Function name    : destroyList - 리스트 내의 모든 노드(head, tail 노드 포함)를 삭제
 Parameters        : lp - 리스트 관리 구조체의 주소
 Returns            : 없음
 ----------------------------------------------------------------------------------*/
void destroyList(List *lp)
{
    Node *curp;
    Node *nextp;
    if (lp == NULL) { /* lp포인터 NULL check */
        return;
    }
    curp = lp->head->next;
    while (curp != lp->tail) {
        nextp = curp->next;
        free(curp);
        curp = nextp;
    }
    free(lp->head);
    free(lp->tail);
    
    lp->head = lp->tail = NULL;
    lp->size = 0;
    return;
}

