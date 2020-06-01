//
//  linkedlist.h
//  Day_0601
//
//  Created by 전경안 on 2020/06/01.
//  Copyright © 2020 전경안. All rights reserved.
//

#ifndef linkedlist_h
#define linkedlist_h

typedef char * (* PRINT_FUNC )(void*);
typedef int(*FreeFunc)(void *);
typedef struct Node Node;
typedef struct List List;

List* listInitialize(FreeFunc ffp);
int listAdd(void* data,List *list);
void listDisplay(const List *list,PRINT_FUNC printFunc);
void listDisplayBack(const List *list,PRINT_FUNC printFunc);
int listAddHead(void* data,List *list);
Node* listGet(const int index,const List *list);
int listInsert(const int index,void* data,List *list);
int listCount(const List *list);
int listRemove(const int index, void **oldData,List *list);
int listRemoveTail(void **oldData,List *list);
int listRemoveHead(void **oldData,List *list);
void* getData(Node*);
void* listRemoveData(List* , Node* );
//void listFinalize(List *list){
//    if(list == NULL){
//        fprintf(stderr,"listFinalize : argument is null\n");
//        return ;
//    }
//
//}

#endif /* linkedlist_h */
