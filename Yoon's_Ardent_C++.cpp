// Yoon's_Ardent_C++.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//Project 1 : 계좌 관리 프로그램
//Project 2 : Class 추가
//Project 3 : 복사 생성자 -> 깊은 복사

#include <iostream>
#include <cstring>

using namespace std;
#define NAME_LEN  20

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

//typedef struct
//{
//    int accID;
//    int balance;
//    char cusName[NAME_LEN];
//} Account;

void ShowMenu();        //메뉴입력
void MakeAccount();     //계좌개설
void DepositMoney();    //입금
void WitharawMoney();   //출금
void ShowAllAccInfo();  //잔액조회

class Account
{
private:
    int accID;
    int balance;
    char* cusName;

public:
    Account(int ID, int money, char* name)
        : accID(ID), balance(money) // 멤버 이니셜라이저 // 초기화 대상 명확히 인식 // 성능 이점 -> 선언과 동시에 초기화가 이루어지는 바이너리 코드 생성
    {
        cusName = new char[strlen(name) + 1];
        strcpy_s(cusName, strlen(name), name);
 
    }

    Account(const Account& ref) // 깊은 복사 생성자 : 원본 생성자 포인터 소멸시 복사 생성자는 포인터 주소만 참조해 사용하기 때문에 오류 발생 -> 깊은 복사 생성자를 사용하여 오류 해결
        : accID(ref.accID), balance(ref.balance) 
    {
        cusName = new char[strlen(ref.cusName) + 1];
        strcpy_s(cusName, strlen(ref.cusName), ref.cusName);

    }

    int GetAccID() { return accID; }
    void Deposit(int money)
    {
        balance += money;

    }
    int Withdraw(int money)
    {
        if (balance < money)
            return 0;

        balance -= money;
        return money;
    }

    void ShowAccInfo()
    {
        cout << "계좌ID : " << accID << endl;
        cout << "이  름 : " << cusName << endl;
        cout << "잔  액 : " << balance << endl;
    }

    ~Account()
    {
        delete[]cusName;
    }
};


Account* _accArr[100]; // 계좌 저장 배열
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

    _accArr[_naccNum++] = new Account(nId, nBal, szName);
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
        if (_accArr[i]->GetAccID() == nId)
        {
            _accArr[i]->Deposit(nMoney);
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
        if (_accArr[i]->GetAccID() == id)
        {
            if (_accArr[i]->Withdraw(money) == 0 )
            {
                cout << "잔액 부족" << endl;
                return;
            }
         
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
        _accArr[i]->ShowAccInfo();
    }
    cout << "===================" << endl;
    cout << endl;
}

