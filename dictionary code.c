//
//  main.c
//  HW70_20200131
//
//  Created by 전경안 on 2020/01/31.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)
typedef struct _dictionary{
    char word[20];
    char mean[80];
    int len;
}Dic;
Dic dary[10];
void showmenu(void);// 단순 메뉴를 출력하는 함수
int selectmenu(void);//메뉴 선택 함수
void inputDic(int *wp);// 단어를 입력받는 함수 (wp = 현재 입력한 단어의 수를 나타낸다)
void printWord(int *wp);//단어를 출력하는 함수
void searchWord(int *wp);//단어를 검색하는 함수
void deleteWord(int *wp);//삭제할 단어를 검색하는 함수
void deleteFunc(int i,int wp);//삭제할 단어가 있을경우 지워주는 함수(i = 삭제할 단어의 배열 방 위치)
void myflush(void);

int main() {
    int wordcnt=0;
    int selectnum;
    while(1){
        showmenu();
        selectnum = selectmenu();
        switch(selectnum){
            case 1:
                inputDic(&wordcnt);
                break;
            case 2:
                printWord(&wordcnt);
                break;
            case 3:
                searchWord(&wordcnt);
                break;
            case 4:
                deleteWord(&wordcnt);
                break;
            default:
                printf("사전 프로그램 종료\n");
                return 0;
        }
    }
    return 0;
}
void showmenu(void){
    printf("=====[사전 프로그램 메뉴]=====\n");
    printf("1. 입력하기\n");
    printf("2. 출력하기\n");
    printf("3. 검색하기\n");
    printf("4. 삭제하기\n");
    printf("5. 종료\n");
    printf("\n");
}
int selectmenu(){
    int select,res;
    while(1){
        printf("선택 :");
        res = scanf("%d",&select);
        if(res==1){
            if(1<=select&&select<=5){
                return select;
            }
            else{
                ;
            }
        }
        else{
            myflush();
        }
    }
}
void inputDic(int *wp){
    while(*wp!=10){
        printf("# 단어를 입력하시오 :");
        scanf("%s",dary[*wp].word);
        if(strcmp(dary[*wp].word,"end")==0){return;}
        getchar();
        printf("# 의미를 입력하시오 :");
        fgets(dary[*wp].mean,79,stdin);
        if(strcmp(dary[*wp].word,"end")==0){return;}
        dary[*wp].len=(int)strlen(dary[*wp].word);
        *wp+=1;
        printf("\n");
    }
    printf("메모리 부족\n");
    return;
}

void printWord(int *wp){
    for(int i=0;i<*wp;i++){
        if(strlen(dary[i].mean)>51){
            printf("%d. %*.*s(%d) : %-*.*s~\n",i+1,20,dary[i].len,dary[i].word,(int)dary[i].len,50,50,dary[i].mean);
        }
        else{
            printf("%d. %*.*s(%d) : %-*.*s\n",i+1,20,dary[i].len,dary[i].word,(int)dary[i].len,50,(int)strlen(dary[i].mean)-1,dary[i].mean);
        }
    }
}

void searchWord(int *wp){
    char tmp[20];
    while(1){
        printf("# 찾을 단어를 입력하시오: ");
        scanf("%s",tmp);
        if(strcmp(tmp,"end")==0){return;}
        for(int i=0;i<*wp;i++){
            if(strcmp(dary[i].word,tmp)==0){
                printf("단어의 뜻: %s\n",dary[i].mean);
                break;
            }
            if(i==*wp-1){printf("Not Found!!\n\n");}
        }
    }
    return;
}

void deleteWord(int *wp){
    char tmp[20],ny;
    while(1){
        printf("# 삭제할 단어를 입력하시오: ");
        scanf("%s",tmp);
        if(strcmp(tmp,"end")==0){return;}
        for(int i=0;i<*wp;i++){
            if(strcmp(dary[i].word,tmp)==0){
                myflush();
                printf("# 정말로 삭제하시겠습니까?(y/n) :");
                scanf("%c",&ny);
                if(ny=='y'){
                    deleteFunc(i,*wp);
                    printf("삭제되었습니다.\n");
                    *wp-=1;
                }
                else{
                    printf("삭제가 취소되었습니다.\n");
                }
                break;
            }
            if(i==*wp-1){printf("없는 단어입니다.\n\n");}
        }
        if(*wp==0){
            printf("사전에 단어가 없습니다.\n");
            return;
        }
    }
}
void deleteFunc(int i,int wp){
    for(int j=i;j<wp;j++){
        strcpy(dary[j].word,dary[j+1].word);
        strcpy(dary[j].mean,dary[j+1].mean);
        dary[j].len=(int)strlen(dary[j].word);
    }
}
void myflush(){
    while(getchar()!='\n'){
        ;
    }
}
