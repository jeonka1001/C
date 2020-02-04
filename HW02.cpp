#include <stdio.h>
#include <string.h>
#include "doublelyLinkedlist.h"
#include "wordData.h"


void readFile(List *lp);
void myflush(void);                /* 입력 버퍼 flush 함수 */
/*----------------------------------------------------------------------------------
 Function name : main
 ----------------------------------------------------------------------------------*/
int main()
{
    List pointList;//포인트 단어 저장
    List myWord;//사용자 입력 단어 저장
    BOOL bres;
    char comWord[W_LEN]=START_WORD;
    char inWord[W_LEN];
    char temp[W_LEN]="";
    int count =1,score=0;
    
    createList(&pointList); //포인트 단어 리스트 생성
    createList(&myWord); // 사용자 입력 단어 리스트 생성
    readFile(&pointList); // 텍스트 파일 읽어오기
    addLast(&myWord, comWord ,sizeof(inWord),strCopy);//pointer 단어 리스트에 추가
    while (1) {
        printf("\n포인트 단어 : ");
        displayList(&pointList, strPrint);
        printf("# 사용자 입력 단어 :");
        displayList(&myWord,strPrint);
        
        printf("끝말잇기 단어 입력 (%d 회차) :",count);
        scanf("%s", inWord);
        if(comWord[strlen(comWord)-1]==inWord[0])//기존 단어의 마지막과 입력한 단어의 첫번재 비교
        {
            count++;
            bres = removeNode(&pointList,inWord,strCompare,strClear);
            if(bres == 1){
                addLast(&myWord, inWord ,sizeof(inWord),strCopy);
                score++;
                //sortList(&pointList,strCompare,strCopy);
            }
            else{
                addLast(&myWord, inWord ,sizeof(inWord),strCopy);
            }
            strcpy(temp,inWord);
            strcpy(inWord,comWord);
            strcpy(comWord,temp);
        }
        else{
            printf("다시 입력하세요.\n");
            myflush();
        }
        if(score == 5){
            break;
        }
    }
    printf("** 당신의 점수는 %d점 입니다\n",score*20);
    
    destroyList(&pointList);
    destroyList(&myWord);
    return 0;
}

/*----------------------------------------------------------------------------------
 Function name    : myflush - 입력 버퍼 내의 모든 데이터 지우는 함수
 Parameters        : 없음
 Returns            : 없음
 ----------------------------------------------------------------------------------*/
void myflush()
{
    while (getchar() != '\n') {
        ;
    }
}


void readFile(List *lp) {
    FILE *ffp;
    char temp[W_LEN];
    int i;
    ffp=fopen("/Users/jeongyeong-an/data//pointWord.txt","rt");//데이터 경로를 지정 하지 않을 시 프로젝트 파일에서 경로를 찾는다.
    
    assert(ffp!=NULL);//fopen이 실패시 프로그램 종료
    for(i=0;i<5;i++){
        if( fscanf(ffp,"%s",temp)!=1)//파일 내에서 개행문자를 제외한 문자를 읽어온다.
        {
            
            break;
        }
        addFirst(lp,temp,sizeof(temp),strCopy);
        
    }
    sortList(lp,strCompare,strCopy);
    fclose(ffp);
}

