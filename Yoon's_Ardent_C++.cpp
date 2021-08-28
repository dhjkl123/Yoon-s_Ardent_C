// Yoon's_Ardent_C++.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstring>

using namespace std;
#define NAME_LEN  20

void ShowMenu();        //메뉴입력
void MakeAccount();     //계좌개설
void DepositMoney();    //입금
void WitharawMoney();   //출금
void ShowAllAccInfo();  //잔액조회

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct
{
    int accID;
    int balance;
    char cusName[NAME_LEN];
} Account;

Account _accArr[100]; // 계좌 저장 배열
int _naccNum = 0;   // 계좌 저장 개수

int main()
{
    int nChoice;
    while (1)
    {
        ShowMenu();
        cout << "선택 : ";
        cin >> nChoice;
        cout << endl;

        switch (nChoice)
        {
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WitharawMoney();
            break;
        case INQUIRE:
            ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
            break;
        default :
            cout << "Choice Failed.. Check your Choice"<<endl;
            break;
        }
    }
    return 0;
}

void ShowMenu()
{
    cout << "----- MENU -----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입   금" << endl;
    cout << "3. 출   금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;

}

void MakeAccount()
{
    int nId;
    char szName[NAME_LEN];
    int nBal;

    cout << "[계좌개설]" << endl;
    cout << "계좌ID : "; cin >> nId;
    cout << "이  름 :"; cin >> szName;
    cout << "입금액 :"; cin >> nBal;
    cout << endl; cout << endl;

    _accArr[_naccNum].accID = nId;
    _accArr[_naccNum].balance = nBal;
    strcpy_s(_accArr[_naccNum].cusName , szName);
    _naccNum++;
}

void DepositMoney()
{
    int nMoney;
    int nId;
    cout << "[입   금]" << endl;
    cout << "계좌ID : "; cin >> nId;
    cout << "입금액 : "; cin >> nMoney;

    for (int i = 0; i < _naccNum; i++)
    {
        if (_accArr[i].accID == nId)
        {
            _accArr[i].balance += nMoney;
            cout << "입금완료" << endl;
            return;

        }
    }
    cout << "유효하지 않은 ID 입니다." << endl;
    cout << endl;
}

void WitharawMoney()
{
    int money;
    int id;
    cout << "[출   금]" << endl;
    cout << "출금 ID: "; cin >> id;
    cout << "출금액: "; cin >> money;

    for (int i = 0; i < _naccNum; i++)
    {
        if (_accArr[i].accID == id)
        {
            if (_accArr[i].balance < money)
            {
                cout << "잔액 부족" << endl;
                return;
            }
            _accArr[i].balance -= money;
            cout << "출금완료" << endl;
            return;

        }
    }
    cout << "유효하지 않은 ID 입니다." << endl;
    cout << endl;
}

void ShowAllAccInfo()
{
    for (int i = 0; i < _naccNum; i++)
    {
        cout << "===================" << endl;
        cout << "계좌ID : " << _accArr[i].accID << endl;
        cout << "이  름 : " << _accArr[i].cusName << endl;
        cout << "잔  액 : " << _accArr[i].balance << endl;
    }
    cout << "===================" << endl;
    cout << endl;
}
