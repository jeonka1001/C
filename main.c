
#include<stdio.h>
int command(void);
void push(int *,int*);//추가한다
void pop(int*,int);//지운다
void top(int);//가장 위에 수를 보여줌
void empty(int);//비어있으면 1
void size(int);
void printstack(int*,int);
int main(){
    int sizee,cc,stack[10000],t,i;
    sizee=0;
    printf("명령어수:");
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        printf("명령어랑 숫자:");
        cc = command();
        switch(cc){
            case 0:
                push(stack,&sizee);
                break;
            case 1:
                pop(stack,sizee);
                sizee--;
                break;
            case 2:
                empty(sizee);
                break;
            case 3:
                top(stack[sizee-1]);
                break;
            case 4:
                size(sizee);
                break;
            case 5:
                printstack(stack,sizee);
                break;
            default:
                cc = command();
                i--;
                break;
        }
        
    }
    return 0;
}

int command(){
    char com[5];
    scanf("%s",com);
    if(com[1]=='u'){
        return 0;
    }
    else if(com[0]=='p'&&com[2]=='p'){
        return 1;
    }
    else if(com[0]=='e'){
        return 2;
    }
    else if(com[0]=='t'){
        return 3;
    }
    else if(com[0]=='s'){
        return 4;
    }
    else if(com[1]=='r'){
        return 5;
    }
    else{
        return -1;
    }
}

void push(int *stack,int *sizee){
    int num;
    scanf("%d",&num);
    stack[*sizee]=num;
    *sizee+=1;
}

void pop(int *stack,int sizee){
    stack[sizee-1] = 'NULL';
}

void top(int topp){
    printf("top:%d\n",topp);
}
void empty(int sizee){
    if(sizee==0){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
}
void size(int sizee){
    printf("%d\n",sizee);
}
void printstack(int *stack,int sizee){
    int i;
    for(i=0;i<sizee;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
