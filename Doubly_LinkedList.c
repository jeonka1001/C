//
//  9.c
//  Day_0529
//
//  Created by 전경안 on 2020/05/29.
//  Copyright © 2020 전경안. All rights reserved.
//

//이중 연결 리스트
//
//  A.c
//  Day_0602
//
//  Created by 전경안 on 2020/06/02.
//  Copyright © 2020 전경안. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define list_entry(ptr,type,member) (type*)((char*)ptr - (long)&((type*)0)->member);

#define list_foreach(node,head) for (node = (head)->prev; node != (head); node = node->prev)

#define list_foreach_reverse(node,head) for (node = (head)->prev; node != (head); node = node->prev)

#define LIST_HEAD(name) Node name = { &(name),&(name) }

typedef struct Node {
    struct Node* next;
    struct Node* prev;
} Node;

static inline void insertNode(Node* new, Node* prev, Node* next) {
    new->next = next;
    new->prev = prev;
    prev->next = new;
    next->prev = new;
}

static inline void listAdd(Node* head, Node* node) {
    insertNode(node, head->prev, head);
    return ;
}

static inline void listAddHead(Node* head, Node* node) {
    insertNode(node, head, head->next);
    return ;
}
static inline void listRemove(Node *node){
    Node *prev = node->prev;
    Node *next = node->next;
    next->prev = prev;
    prev->next = next;
    return ;
}


// 위의 코드는 라이브러리가 제공하는 코드입니다.
// ----------------------------------------------------------------------------------
// 아래의 코드는 사용자가 구현하는 코드입니다.


typedef struct Person {
    char name[32];
    int age;
    Node list;
} Person;

void display(const Node* head) {
    if (head == NULL) {
        fprintf(stderr, "display(): argument is null\n");
        return;
    }
    
    system("clear");
    printf("[head]");
    Node *node;
    list_foreach(node,head) {
        Person* p = list_entry(node,Person,list);
        printf("<->[%s(%d)]", p->name, p->age);
    }
    printf("<->[head]");
    getchar();
}

//이 전 코드는 자료구조 탐색이 너무 어렵다.
// 이를 해결하기위해 탐색 함수를 제공합니다.
void displayBackwardly(const Node* head) {
    if (head == NULL) {
        fprintf(stderr, "displayBackwardly(): argument is null\n");
        return;
    }
    
    system("clear");
    printf("[head]");
    Node* node;
    list_foreach_reverse(node,head) {
        Person* p = list_entry(node, Person, list);
        printf("<->[%s(%d)]", p->name, p->age);
    }
    printf("<->[head]");
    getchar();
}

int main(void) {
    Person people[4] = {
        {"eddy", 20}, {"pororo", 30}, {"petty", 40}, {"poby", 50}
    };
    
    LIST_HEAD(head);
    display(&head);
    for (int i = 0; i < 4; i++) {
        listAdd(&head, &(people[i].list));
        // listAddHead(&head, nodes + i);
        display(&head);
    }
    Node *node;
    list_foreach(node,&head){
        Person* p = list_entry(node,Person,list);
        if(strcmp(p->name,"pororo")==0){
            listRemove(node);
        }
    }
    display(&head);
    return 0;
}


