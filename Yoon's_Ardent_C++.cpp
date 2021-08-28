// Yoon's_Ardent_C++.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//Project 1 : 계좌 관리 프로그램
//Project 2 : Class 추가
//Project 3 : 복사 생성자 -> 깊은 복사
//Project 4 : 멤버 함수 const
//Project 5 : Control Class, Entity Class

#include <iostream>
#include <cstring>

#include "Account.h"
#include "AccountHandler.h"

using namespace std;
#define NAME_LEN  20

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

Account* _accArr[100]; // 계좌 저장 배열
int _naccNum = 0;   // 계좌 저장 개수

int main()
{
    AccountHandler manager;
    int nChoice;
    while (1)
    {
        manager.ShowMenu();
        cout << "선택 : ";
        cin >> nChoice;
        cout << endl;

        switch (nChoice)
        {
        case MAKE:
            manager.MakeAccount();
            break;
        case DEPOSIT:
            manager.DepositMoney();
            break;
        case WITHDRAW:
            manager.WitharawMoney();
            break;
        case INQUIRE:
            manager.ShowAllAccInfo();
            break;
        case EXIT:
            for (int i = 0; i < _naccNum; i++)
                delete _accArr[i];
            return 0;
            break;
        default :
            cout << "Choice Failed.. Check your Choice"<<endl;
            break;
        }
    }
    return 0;
}




