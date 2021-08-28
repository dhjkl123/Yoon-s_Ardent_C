#include "Account.h"

#include <iostream>
#include <cstring>

using namespace std;
#define NAME_LEN  20

Account::Account(int ID, int money, char* name)
    : accID(ID), balance(money) // 멤버 이니셜라이저 // 초기화 대상 명확히 인식 // 성능 이점 -> 선언과 동시에 초기화가 이루어지는 바이너리 코드 생성
{
    cusName = new char[strlen(name) + 1];
    strcpy_s(cusName, strlen(name), name);

}

Account::Account(const Account& ref) // 깊은 복사 생성자 : 원본 생성자 포인터 소멸시 복사 생성자는 포인터 주소만 참조해 사용하기 때문에 오류 발생 -> 깊은 복사 생성자를 사용하여 오류 해결
    : accID(ref.accID), balance(ref.balance)
{
    cusName = new char[strlen(ref.cusName) + 1];
    strcpy_s(cusName, strlen(ref.cusName), ref.cusName);

}

Account::~Account()
{
    delete[]cusName;
}

int Account::GetAccID() const 
{ 
    return accID; 
}

void Account::Deposit(int money)
{
    balance += money;

}

int Account::Withdraw(int money)
{
    if (balance < money)
        return 0;

    balance -= money;
    return money;
}

void Account::ShowAccInfo() const // const 객체를 통해 호출시 const 멤버 함수를 호출
{
    cout << "계좌ID : " << accID << endl;
    cout << "이  름 : " << cusName << endl;
    cout << "잔  액 : " << balance << endl;
}


