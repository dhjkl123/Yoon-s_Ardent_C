#include "AccountHandler.h"

#include <iostream>
#include <cstring>

#include "HighCreditAccount.h"
#include "NomalAccount.h"

using namespace std;
#define NAME_LEN  20

//계좌의 종류
enum { NOMAL = 1, CREDIT = 2 };

//신용등급
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

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

    int nInterRate;
    int sel;
    int nLevel;

    cout << "[계좌개설]" << endl;
    cout << "1. 보통예금계좌" << endl;
    cout << "2. 신용신뢰계좌" << endl;
    cout << "선택  : "; cin >> sel;

    if (sel == NOMAL)
    {
        cout << "[보통예금계좌개설]" << endl;
        cout << "계좌ID : "; cin >> nId;
        cout << "이  름 :"; cin >> szName;
        cout << "입금액 :"; cin >> nBal;
        cout << "이자율 :"; cin >> nInterRate;
        
        m_accArr[m_accNum++] = new NomalAccount(nId, nBal, szName, nInterRate);
    }
    else
    {
        cout << "[신용신뢰계좌개설]" << endl;
        cout << "계좌ID : "; cin >> nId;
        cout << "이  름 :"; cin >> szName;
        cout << "입금액 :"; cin >> nBal;
        cout << "이자율 :"; cin >> nInterRate;
        cout << "신용등급(1:A, 2:B, 3:C) :"; cin >> nLevel;

        switch (nLevel)
        {
        case 1:
            m_accArr[m_accNum++] = new HighCreditAccount(nId, nBal, szName, nInterRate, LEVEL_A);
            break;
        case 2:
            m_accArr[m_accNum++] = new HighCreditAccount(nId, nBal, szName, nInterRate, LEVEL_B);
            break;
        case 3:
            m_accArr[m_accNum++] = new HighCreditAccount(nId, nBal, szName, nInterRate, LEVEL_C);
            break;
        }
        
        
    }

    cout << endl; cout << endl;

    
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
