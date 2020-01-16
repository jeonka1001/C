
//
//  main.cpp
//  4-5 oop프로젝트1 은행
//
//  Created by 전경안 on 2020/01/05.
//  Copyright © 2020 전경안. All rights reserved.
// 멤버변수는 동적할당
// 구조체 포인터 배열로 선언

#include <iostream>
#include <cstring>

using namespace std;

namespace BankNum{
    enum{
        NAME_LEN=20,
        MAKEACC=1,//계좌개설
        DEPOSIT,//입금
        WITHDRAW,//출금
        SHOWINFO,//정보출력
    };
};

using namespace BankNum;

class Banksys{
private:
    char *myname; //아이디 배열
    int accid; // 계좌번호
    int mymoney;
public:
    Banksys(char *name,int id)
    :mymoney(0)
    {
        unsigned long len=strlen(name);
        myname = new char[len+1];////////동적 메모리 할당 여기도 지우기
        strcpy(myname,name);
        accid=id;
    }
    
    void input(int money){
        if(money>0){
            mymoney+=money;
        }
        else{
            cout<<"올바르지 않은 값 입니다."<<endl;
        }
    }
    
    void output(int money){
        if(mymoney>=money){
            mymoney-=money;
        }else{
            cout<<"올바르지 않은 값 입니다."<<endl;
        }
    }
    void showinfo(){
        cout<<"===================="<<endl;
        cout<<"이름 "<<myname<<endl;
        
        cout<<"계좌번호 "<<accid<<endl;
        
        cout<<"잔액 "<<mymoney<<endl;
    }
    char* namereturn(){
        return myname;
    }
    int idreturn(){
        return accid;
    }
    ~Banksys(){
        delete []myname;/////마이네임을 지웁니다.
    }
};
void showmenu();
int banknum=0;//생성한 계좌의 개수
Banksys *bs[10];//10개의 계좌 생성 가능\

int cmpid(char*,int,int);

//////////////////////////////////////////////////////
int main(){
    int select,money,inum;
    char name[NAME_LEN];
    int id;
    
    while(1){
        showmenu();
        cout<<"선택 :";
        cin>>select;
        switch(select){
            case MAKEACC:
                cout<<"이름과 아이디(숫자 5자리)를 입력해주세요 ";
                cin>>name>>id;
                bs[banknum]=new Banksys(name,id);///////////동적 메모리 할당 나중에 지우기
                banknum++;
                break;
                
            case DEPOSIT:
                cout<<"회원님의 성명과 아이디를 입력해주세요";
                cin>>name>>id;
                inum=cmpid(name,id,banknum);
                if(inum==961001){
                    cout<<"잘 못 입력하셨습니다."<<endl;
                }
                else{
                    cout<<"입금하실 금액을 입력해 주세요: ";
                    cin>>money;
                    bs[inum]->input(money);
                }
                break;
                
            case WITHDRAW:
                cout<<"회원님의 성명과 아이디를 입력해주세요";
                cin>>name>>id;
                inum=cmpid(name,id,banknum);
                if(inum==961001){
                    cout<<"잘 못 입력하셨습니다."<<endl;
                }
                else{
                    cout<<"출금하실 금액을 입력해 주세요: ";
                    cin>>money;
                    bs[inum]->output(money);
                }
                break;
                
            case SHOWINFO:
                for(int i=0;i<banknum;i++){
                    bs[i]->showinfo();
                }
                break;
                
            case 5:
                cout<< "프로그램을 종료합니다."<<endl;
                for(int i=0;i<banknum;i++){
                    delete bs[i];//배열을 지웁니다.
                }
                return 0;
                
            default:
                
                cout<<"잘못 입력하셨습니다."<<endl;
                break;
                
        }
    }
}

void showmenu(){
    cout<<"===================="<<endl;
    cout<<"1.계좌개설\n"<<"2.입금\n"<<"3.출금\n"<<"4.회원내용 출력"<<endl;
    cout<<"5.종료"<<endl;
}
int cmpid(char* name,int id,int banknum){
    for(int i=0;i<banknum;i++){
        if(strcmp(bs[i]->namereturn(),name)==0)//저장된 이름과 입력한 이름 비교
        {
            if(id==bs[i]->idreturn()){
                return i;
            }
        }
        else{
            ;
        }
    }
    return 961001;
}


