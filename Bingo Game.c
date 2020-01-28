//
//  main.c
//  HW 68_20200128
//
//  Created by 전경안 on 2020/01/28.
//  Copyright © 2020 전경안. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void showmenu(void);//메뉴 출력함수
int menuselect(void);//메뉴 선택함수
void output(int);//게임 결과 출력
int bingocheck(int **,int);//빙고 체크 함수

void myflush(void);
int randnum(int);

int selectbingosize(void);//빙고 크기 정하는 함수
void inputnum(int **,int);//빙고 숫자 채우는 함수
void playgame(int**,int);//연습게임 진행 함수
int playdualgame(int**,int**,int);//대전게임 진행 함수

void display(int**,const int);//연습용 디스플레이 출력 함수
void dualdisplay(int**,int**,const int);//대전용 빙고 디스플레이 출력 함수

void trainingmode(int);// 연습용 빙고 생성
void computermode(int);//대전용 빙고 생성
int main(){
    int menu,size;
    srand((unsigned int)time(NULL));
    while(1){
        menu=menuselect();
        switch(menu){
            case 1:
                printf("연습용 빙고 게임을 시작합니다.\n");
                size = selectbingosize();//빙고 사이즈 선택
                trainingmode(size);
                break;
            case 2:
                printf("컴퓨터 대전 빙고 게임을 시작합니다.\n");
                size = selectbingosize();//빙고 사이즈 선택
                computermode(size);
                break;
            default:
                printf("게임을 종료합니다.\n");
                return 0;
        }
    }
}

void showmenu(){
    printf("1.연습게임\n");
    printf("2.대전게임\n");
    printf("3.종료\n");
    printf("\n");
    printf("# 메뉴선택:");
}

int menuselect(){
    int num,res;
    while(1){
        showmenu();
        res=scanf("%d",&num);
        if(res==1){
            if(1<=num&&num<=3){
                return num;
            }
        }
        myflush();
        printf("다시 입력해주세요.\n");
    }
}

int selectbingosize(){
    int size,res;
    while(1){
        printf("# 빙고판의 가로,세로 크기를 입력해주세요(2<=Size<=10): ");
        res=scanf("%d",&size);
        if(res==1){
            if(2<=size&&size<=10){
                return size;
            }
        }
        myflush();
        printf("다시 입력해주세요.\n");
    }
}

void trainingmode(int s){
    int **bingo = (int **)malloc(sizeof(int*)*s);//사용자 빙고
    for(int i=0;i<s;i++){
        bingo[i]=(int *)malloc(sizeof(int)*s);
    }
    inputnum(bingo,s);//숫자 채우기
    playgame(bingo,s);//게임 진행
    for(int i=0;i<s;i++){
        free(bingo[i]);
    }
    free(bingo);
}

void computermode(int s){
    int gameres;//게임결과
    int **bingo = (int **)malloc(sizeof(int*)*s);//사용자 빙고
    int **combingo = (int **)malloc(sizeof(int*)*s);//컴퓨터 빙고
    for(int i=0;i<s;i++){
        bingo[i]=(int *)malloc(sizeof(int)*s);
        combingo[i]=(int *)malloc(sizeof(int)*s);
    }
    inputnum(bingo,s);//숫자 채우기
    inputnum(combingo,s);//컴퓨터 숫자 채우기
    gameres=playdualgame(bingo,combingo,s);//게임 진행
    output(gameres);//결과출력
    for(int i=0;i<s;i++){
        free(bingo[i]);
        free(combingo[i]);
    }
    free(bingo);
    free(combingo);
}


void inputnum(int **bingo,int s){
    int innum=1,inum,jnum;//innum은 1에서 빙고크기만큼 증가하는숫자/ inum,jnum은 난수를 저장하기 위한변수
    for(int j=0;j<s;j++){
        for(int k=0;k<s;k++){
            bingo[j][k]=0;// 빙고 숫자를 채우기 위해 0으로 초기화
        }
    }
    while(innum!=(s*s)+1){
        if(bingo[inum=randnum(s)][jnum=randnum(s)]==0)
        {
            bingo[inum][jnum]=innum;
            innum++;
        }
    }
}
int randnum(int s){
    return rand()%s;
}

void playgame(int **bingo,const int s){
    int ynum,res;
    int checkres=0;
    int check[s*s+1];
    while(1){
        display(bingo,s);
        printf("# 지울 숫자 입력(1-%d): ",s*s);
        res=scanf("%d",&ynum);
        if(res==1){
            if(1<=ynum&&ynum<=s*s){
                if(check[ynum]==-1){
                    printf("* 이미 지워진 숫자 입니다.\n");
                }
                else{
                    check[ynum]=-1;
                    for(int i=0;i<s;i++){
                        for(int j=0;j<s;j++){
                            if(bingo[i][j]==ynum){
                                bingo[i][j]=-1;
                            }
                        }
                    }
                }
                checkres=bingocheck(bingo,s);
                if(checkres==1){
                    display(bingo,s);
                    printf("%d 빙고 완료\n",s);
                    return ;
                }
            }
            else{
                printf("@범위 내에서 입력하세요\n");
            }
        }
        else{
            printf("@숫자만 입력하세요.\n");
            myflush();
        }
    }
}

int playdualgame(int **bingo,int **combingo,const int s){
    int ynum,res,turn=1;
    int checkres=0,comcheckres=0;
    int check[s*s+1];
    while(1){
        dualdisplay(bingo,combingo,s);
        if(turn==1){
            turn*=-1;
            printf("# 지울 숫자 입력(1-%d): ",s*s);
            res=scanf("%d",&ynum);
        }
        else{
            turn*=-1;
            res=1;
            ynum=randnum(s*s);
            printf("# 컴퓨터가 선택한 숫자는 (%d)입니다.\n",ynum);
        }
        if(res==1){
            if(1<=ynum&&ynum<=s*s){
                if(check[ynum]==-1){
                    printf("* 이미 지워진 숫자 입니다.\n");
                    turn*=-1;
                }
                else{
                    check[ynum]=-1;
                    for(int i=0;i<s;i++){
                        for(int j=0;j<s;j++){
                            if(bingo[i][j]==ynum){
                                bingo[i][j]=-1;
                            }
                            if(combingo[i][j]==ynum){
                                combingo[i][j]=-1;
                            }
                        }
                    }
                }
                checkres=bingocheck(bingo,s);
                comcheckres=bingocheck(combingo,s);
                if(checkres==1&&comcheckres==1){
                    dualdisplay(bingo,combingo,s);
                    return 0;
                }
                else if(checkres==1){
                    dualdisplay(bingo,combingo,s);
                    return 1;
                }
                else if(comcheckres==1){
                    dualdisplay(bingo,combingo,s);
                    return 2;
                }
                else{;}
            }
            else{
                printf("@범위 내에서 입력하세요\n");
                turn*=-1;
            }
        }
        else{
            printf("@숫자만 입력하세요.\n");
            myflush();
            turn*=-1;
        }
    }
}

void display(int **bingo,const int s){
    for(int i=0;i<s;i++){
        printf("ㅣ\t");
        for(int j=0;j<s;j++){
            if(bingo[i][j]==-1){
                printf("X\t");
            }
            else{
                printf("%d\t",bingo[i][j]);
            }
        }
        printf("ㅣ\n");
    }
}
void dualdisplay(int **bingo,int **combingo,const int s){
    for(int i=0;i<s;i++){
        printf("ㅣ\t");
        for(int j=0;j<s;j++){
            if(bingo[i][j]==-1){
                printf("X\t");
            }
            else{
                printf("%d\t",bingo[i][j]);
            }
        }
        printf("ㅣ\t\tㅣ\t");
        for(int k=0;k<s;k++){
            if(combingo[i][k]==-1){
                printf("X\t");
            }
            else{
                printf("?\t");
            }
        }
        printf("ㅣ\n");
    }
}

int bingocheck(int **bingo,int s){
    int count=0;
    int sumbingo=0;
    for(int i=0;i<s;i++){//가로줄 빙고 체크
        for(int j=0;j<s;j++){
            if(bingo[i][j]==-1){
                sumbingo--;
                if(sumbingo==-1*s){
                    count++;
                }
            }
        }
        sumbingo=0;
    }
    for(int j=0;j<s;j++){//세로줄 체크
        for(int i=0;i<s;i++){
            if(bingo[i][j]==-1){
                sumbingo-=1;
                if(sumbingo==-1*s){
                    count++;
                }
            }
        }
        sumbingo=0;
    }
    for(int i=0;i<s;i++){//대각선 1 체크
        if(bingo[i][i]==-1){
            sumbingo--;
            if(sumbingo==-1*s){
                count++;
            }
        }
    }
    sumbingo=0;
    for(int i=0;i<s;i++){//대각선 2 체크
        if(bingo[i][s-i-1]==-1){
            sumbingo--;
            if(sumbingo==-1*s){
                count++;
            }
        }
    }
    if(count>=s){
        return 1;
    }
    else{
        return 0;
    }
}

void output(int a){
    if(a==1){
        printf("사용자의 승리");
    }
    else if(a==2){
        printf("사용자의 패배");
    }
    else{
        printf("드로우");
    }
    printf("\n");
}
void myflush(){
    while(getchar()!='\n'){
        ;
    }
}
