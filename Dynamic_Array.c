//
//  F.c
//  Day_0527
//
//  Created by 전경안 on 2020/05/27.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Array {
    int* contents;
    int size;
    int count;
} Array;

#define INITIAL_SIZE (4)
Array* arrayCreate() {
    Array* array = calloc(1, sizeof(Array));
    if (array == NULL) {
        perror("arrayCreate");
        return NULL;
    }
    int* contents = malloc(sizeof(int) * INITIAL_SIZE);
    if (contents == NULL) {
        perror("arrayCreate");
        free(array);
        return NULL;
    }
    array->contents = contents;
    array->size = INITIAL_SIZE;
    return array;
}

void arrayDestroy(Array* array) {
    if (array == NULL)
        return;
    free(array->contents);
    free(array);
}

#define MAX_SIZE (4096)

int newContents(Array *array){
    if((array->size)+INITIAL_SIZE > MAX_SIZE || array->size+INITIAL_SIZE < array->size){
        array->size -= INITIAL_SIZE;
    }
    int *newContents = realloc(array->contents,sizeof(int)*((array->size)+INITIAL_SIZE));
    if(newContents == NULL){
        perror("arrorAdd");
        return -1;
    }
    array->contents = newContents;
    array->size += INITIAL_SIZE;
    
    
    return 0;
}

int arrayAdd(Array* array, int data) {
    if (array == NULL) {
        fprintf(stderr, "arrayAdd: argument is null\n");
        return -1;
    }
    if (array->count >= array->size){
        newContents(array);
    }
    
    array->contents[array->count] = data;
    ++(array->count);
    return 0;
}

void arrayDisplay(const Array* array) {
    system("clear");
    for (int i = 0; i < array->size; i++) {
        if (i < array->count)
            printf("[%2d]", array->contents[i]);
        else
            printf("[%2c]", ' ');
    }
    getchar();
}

int arraySet(Array* array, int index, int newData, int* oldData) {
    if (array == NULL || oldData == NULL) {
        fprintf(stderr, "arraySet: argument is null\n");
        return -1;
    }
    
    if (index < 0 || index >= array->count) {
        fprintf(stderr, "arraySet: out of index\n");
        return -1;
    }
    
    *oldData = array->contents[index];
    array->contents[index] = newData;
    return 0;
}

int arrayInsert(Array* array, int index, int newData) {
    if (array == NULL) {
        fprintf(stderr, "arrayInsert: argument is null\n");
        return -1;
    }
    
    if (array->count == array->size) {
        newContents(array);
    }
    
    if (index < 0 || index >= array->count) {
        fprintf(stderr, "arrayInsert: out of index\n");
        return -1;
    }
    
    memmove(array->contents + index + 1, array->contents + index,
            sizeof(int) * (array->count - index));
    
    array->contents[index] = newData;
    ++(array->count);
    return 0;
}


int arrayCount(const Array* array) {
    if (array == NULL) {
        fprintf(stderr, "arrayCount: argument is null\n");
        return -1;
    }
    return array->count;
}

int arrayGet(const Array *array,int index, int *outData){
    if(array == NULL || outData == NULL){
        fprintf(stderr, "arrayGet: argument is null\n");
        return -1;
    }
    *outData = array-> contents[index];
    return 0;
}

int arrayRemove(Array *array, int index,int *delData){
    if(array == NULL){
        fprintf(stderr, "arrayRemove: argument is null\n");
        return -1;
    }
    if( array->count == 0 ){
        fprintf(stderr, "arrayRemove: Array is Empty\n");
        return -1;
    }
    if(index < 0 || index >= array->count){
        fprintf(stderr, "arrayRemove: out of index\n");
        return -1;
    }
    *delData = array->contents[index];
    if(index != array->count-1){
        memmove(array->contents+index, array->contents+(index+1),sizeof(int)*(array->count-(index+1)));
    }
    array->count--;
    return 0;
}
int main() {
    Array* arr = arrayCreate();
    //--------------------------
    arrayDisplay(arr);
    for (int i = 0; i < 20; i++){
        arrayAdd(arr, i + 1);
        arrayDisplay(arr);
    }
    arrayInsert(arr, 3, 9999);
    arrayDisplay(arr);
    arrayInsert(arr, 0, 0);
    arrayDisplay(arr);
    arrayDestroy(arr);
}





