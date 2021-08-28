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
    cout << "1. ���°���" << endl;
    cout << "2. ��   ��" << endl;
    cout << "3. ��   ��" << endl;
    cout << "4. �������� ��ü ���" << endl;
    cout << "5. ���α׷� ����" << endl;

}

void AccountHandler::MakeAccount()
{
    int nId;
    char szName[NAME_LEN];
    int nBal;

    cout << "[���°���]" << endl;
    cout << "����ID : "; cin >> nId;
    cout << "��  �� :"; cin >> szName;
    cout << "�Աݾ� :"; cin >> nBal;
    cout << endl; cout << endl;

    m_accArr[m_accNum++] = new Account(nId, nBal, szName);
}

void AccountHandler::DepositMoney()
{
    int nMoney;
    int nId;
    cout << "[��   ��]" << endl;
    cout << "����ID : "; cin >> nId;
    cout << "�Աݾ� : "; cin >> nMoney;

    for (int i = 0; i < m_accNum; i++)
    {
        if (m_accArr[i]->GetAccID() == nId)
        {
            m_accArr[i]->Deposit(nMoney);
            cout << "�ԱݿϷ�" << endl;
            return;

        }
    }
    cout << "��ȿ���� ���� ID �Դϴ�." << endl;
    cout << endl;
}

void AccountHandler::WitharawMoney()
{
    int money;
    int id;
    cout << "[��   ��]" << endl;
    cout << "��� ID: "; cin >> id;
    cout << "��ݾ�: "; cin >> money;

    for (int i = 0; i < m_accNum; i++)
    {
        if (m_accArr[i]->GetAccID() == id)
        {
            if (m_accArr[i]->Withdraw(money) == 0)
            {
                cout << "�ܾ� ����" << endl;
                return;
            }

            cout << "��ݿϷ�" << endl;
            return;

        }
    }
    cout << "��ȿ���� ���� ID �Դϴ�." << endl;
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
