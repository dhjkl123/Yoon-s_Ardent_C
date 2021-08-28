#include "AccountHandler.h"

#include <iostream>
#include <cstring>

using namespace std;
#define NAME_LEN  20

AccountHandler::AccountHandler() :m_accNum(0) {}

AccountHandler::~AccountHandler()
{
    for (int i = 0; i < m_accNum; i++)
    {
        delete m_accArr[i];
    }
}

void AccountHandler::ShowMenu()
{
    cout << "----- MENU -----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입   금" << endl;
    cout << "3. 출   금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;

}

void AccountHandler::MakeAccount()
{
    int nId;
    char szName[NAME_LEN];
    int nBal;

    cout << "[계좌개설]" << endl;
    cout << "계좌ID : "; cin >> nId;
    cout << "이  름 :"; cin >> szName;
    cout << "입금액 :"; cin >> nBal;
    cout << endl; cout << endl;

    m_accArr[m_accNum++] = new Account(nId, nBal, szName);
}

void AccountHandler::DepositMoney()
{
    int nMoney;
    int nId;
    cout << "[입   금]" << endl;
    cout << "계좌ID : "; cin >> nId;
    cout << "입금액 : "; cin >> nMoney;

    for (int i = 0; i < m_accNum; i++)
    {
        if (m_accArr[i]->GetAccID() == nId)
        {
            m_accArr[i]->Deposit(nMoney);
            cout << "입금완료" << endl;
            return;

        }
    }
    cout << "유효하지 않은 ID 입니다." << endl;
    cout << endl;
}

void AccountHandler::WitharawMoney()
{
    int money;
    int id;
    cout << "[출   금]" << endl;
    cout << "출금 ID: "; cin >> id;
    cout << "출금액: "; cin >> money;

    for (int i = 0; i < m_accNum; i++)
    {
        if (m_accArr[i]->GetAccID() == id)
        {
            if (m_accArr[i]->Withdraw(money) == 0)
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

void AccountHandler::ShowAllAccInfo()
{
    for (int i = 0; i < m_accNum; i++)
    {
        cout << "===================" << endl;
        m_accArr[i]->ShowAccInfo();
    }
    cout << "===================" << endl;
    cout << endl;
}
