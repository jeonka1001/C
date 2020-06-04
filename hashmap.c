//
//  9.c
//  Day_0603
//
//  Created by 전경안 on 2020/06/03.
//  Copyright © 2020 전경안. All rights reserved.
//


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void* key;
    void* value;
    int hash;
    struct Node* next;
} Node;

typedef int(*HashFn)(void* key);
typedef int(*EqualsFn)(void* key1, void* key2);
typedef struct Hashmap {
    Node** buckets;
    size_t bucketSize;
    size_t count;
    HashFn hash;
    EqualsFn equlas;
} Hashmap;

#define DEFALUT_BUCKET_SIZE        (1)

Hashmap* hashmapCreate(HashFn hash, EqualsFn equals) {
    if (hash == NULL || equals == NULL) {
        fprintf(stderr, "hashmapCreate: argument is null\n");
        return NULL;
    }
    
    Hashmap* map = calloc(1, sizeof(Hashmap));
    if (map == NULL) {
        perror("hashmapCreate");
        return NULL;
    }
    
    Node** buckets = calloc(DEFALUT_BUCKET_SIZE, sizeof(Node*));
    if (buckets == NULL) {
        perror("hashmapCreate");
        free(map);
        return NULL;
    }
    
    map->buckets = buckets;
    map->bucketSize = DEFALUT_BUCKET_SIZE;
    map->hash = hash;
    map->equlas = equals;
    
    return map;
}

void hashmapDestroy(Hashmap* map) {
    if (map == NULL)
        return;
    free(map->buckets);
    free(map);
}

static int hashKey(Hashmap* map, void* key) {
    int h = map->hash(key);
    h += ~(h << 9);
    h ^= (((unsigned int)h) >> 14);
    h += (h << 4);
    h ^= (((unsigned int)h) >> 10);
    return h;
}

static size_t calculateIndex(size_t bucketSize, int hash) {
    return ((size_t)hash) & (bucketSize - 1);
}

static Node* createNode(void* key, int hash, void* value) {
    Node* node = calloc(1, sizeof(Node));
    if (node == NULL) {
        perror("createNode");
        return NULL;
    }
    node->key = key;
    node->value = value;
    node->hash = hash;
    return node;
}

static int equalsKey(void* key1, int hash1, void* key2, int hash2, EqualsFn equals) {
    if (key1 == NULL || key2 == NULL || equals == NULL)
        return 0;
    
    if (key1 == key2)
        return 1;
    if (hash1 != hash2)
        return 0;
    return equals(key1, key2);
}
static int rehashing(Hashmap *map){
    if(map == NULL){
        fprintf(stderr,"rehashing : argument is null\n");
        return -1;
    }
    size_t newSize = map->bucketSize*2;
    Node** temp = calloc(newSize, sizeof(Node*));
    if(map == NULL){
        perror("rehashing");
        return -1;
    }
    for(size_t i = 0; i <map->bucketSize; i++)
    {
        Node *cur = map->buckets[i];
        while(cur != NULL){
            Node* next = cur->next;
            size_t index = calculateIndex(map->bucketSize*2, cur->hash);
            cur->next = temp[index]; // add Front 방식으로 재 인덱싱 하는것이다.
            temp[index] = cur;
            cur = next;
        }
    }
    free(map->buckets);
    map->buckets = temp;
    map->bucketSize = newSize;
    return 1;
}
void* hashmapPut(Hashmap* map, void* key, void* value) {
    if (map == NULL || key == NULL || value == NULL) {
        fprintf(stderr, "hashmapPut: argument is null\n");
        return NULL;
    }
    if((map->count)>=(map->bucketSize*3/4)){
        rehashing(map);
        if(!map){
            fprintf(stderr,"hashmapPut : rehashing is failed\n");
            return NULL;
        }
    }
    printf("size : %d",map->bucketSize);
    int hash = hashKey(map, key);
    size_t index = calculateIndex(map->bucketSize, hash);
    
    Node** ptr = &(map->buckets[index]);
    while (1) {
        Node* cur = *ptr;
        if (cur == NULL) {
            Node* node = createNode(key, hash, value);
            if (node == NULL) {
                fprintf(stderr, "hashmapPut: createNode error\n");
                return NULL;
            }
            
            *ptr = node;
            map->count++;
            return NULL;
        }
        
        if (equalsKey(cur->key, cur->hash, key, hash, map->equlas) == 1) {
            void* oldValue = cur->value;
            cur->value = value;
            return oldValue;
        }
        ptr = &(cur->next);
    }
}

void hashmapDisplay(const Hashmap* map, const char* (*toString)(void*)) {
    if (map == NULL || toString == NULL)
        return;
    system("clear");    // system("clear");
    
    size_t bucketSize = map->bucketSize;
    for (size_t i = 0; i < bucketSize; i++) {
        printf("bucket[%2d]", i);
        
        for (Node* p = map->buckets[i]; p != NULL; p = p->next)
            printf("->[%s]", toString(p->value));
        printf("\n");
    }
    getchar();
}

void* hashmapGet(const Hashmap* map, void* key) {
    if (map == NULL || key == NULL) {
        fprintf(stderr, "hashmapGet: argument is null\n");
        return NULL;
    }
    
    int hash = hashKey(map, key);
    size_t index = calculateIndex(map->bucketSize, hash);
    Node* cur = map->buckets[index];
    while (cur != NULL) {
        if (equalsKey(cur->key, cur->hash, key, hash, map->equlas) == 1) {
            return cur->value;
        }
        cur = cur->next;
    }
    return NULL;
}

void* hashmapRemove(Hashmap* map,void* key){
    if(map == NULL || key == NULL){
        fprintf(stderr,"hashmapRemove : argument is null \n");
        return NULL;
    }
    int hash = hashKey(map, key);
    size_t index = calculateIndex(map->bucketSize, hash);
    Node **prev = &(map->buckets[index]);
    
    while (*prev != NULL) {
        if (equalsKey((*prev)->key, (*prev)->hash, key, hash, map->equlas) == 1) {
            void* outData = (*prev)->value;
            Node *cur = *prev;
            *prev = cur->next;
            free(cur);
            --map->count;
            return outData;
        }
        *prev = (*prev)->next;
    }
    return NULL;
}
int hashmapForEach(Hashmap* map,void(*userFun)(void*,void*)){
    if(map == NULL || userFun == NULL){
        fprintf(stderr,"hashmapForEach : argument is NULL\n");
        return -1;
    }
    for(int i = 0 ; i < map->bucketSize ; i ++){
        Node* node = map->buckets[i];
        while(node!=NULL){
            userFun(node->key,node->value);
            node=node->next;
        }
    }
    return 1;
}

// 위 코드는 라이브러리 설계자가 제공하는 코드입니다.
// ----------------------------------------------------------------------------------
// 아래의 코드는 사용자가 구현하는 코드입니다.

typedef struct {
    char name[32];
    int age;
} Person;

int myHash(void* key) {
    return strlen((const char*)key);
}

int myEquals(void* key1, void* key2) {
    if (key1 == NULL || key2 == NULL)
        return 0;
    return strcmp((const char*)key1, (const char*)key2) == 0;
}

const char* myToString(void* p) {
    static char buf[1024];
    Person* person = p;
    sprintf(buf, "%s(%d)", person->name, person->age);
    return buf;
}

void increaseAge(void* key, void *value){
    if(key == NULL || value == NULL){
        return ;
    }
    Person*p = value;
    ++p->age;
}

int main() {
    Person people[4] = {
        {"daniel", 20}, {"susan", 30}, {"petty", 40}, {"eddy", 50}
    };
    Hashmap* map = hashmapCreate(myHash, myEquals);
    for (int i = 0; i < 4; i++){
        hashmapPut(map, people[i].name, &people[i]);
        hashmapDisplay(map, myToString);
    }
    
    
    // 해시 맵에 저장된 사람 데이터에 대하여 나이를 1씩 증가!
    hashmapForEach(map,increaseAge);
    hashmapDisplay(map, myToString);
    
    hashmapDestroy(map);
    return 0;
}


