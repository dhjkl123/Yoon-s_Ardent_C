#include "Account.h"

#include <iostream>
#include <cstring>

using namespace std;
#define NAME_LEN  20

Account::Account(int ID, int money, char* name)
    : accID(ID), balance(money) // ��� �̴ϼȶ����� // �ʱ�ȭ ��� ��Ȯ�� �ν� // ���� ���� -> ����� ���ÿ� �ʱ�ȭ�� �̷������ ���̳ʸ� �ڵ� ����
{
    cusName = new char[strlen(name) + 1];
    strcpy_s(cusName, strlen(name), name);

}

Account::Account(const Account& ref) // ���� ���� ������ : ���� ������ ������ �Ҹ�� ���� �����ڴ� ������ �ּҸ� ������ ����ϱ� ������ ���� �߻� -> ���� ���� �����ڸ� ����Ͽ� ���� �ذ�
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

void Account::ShowAccInfo() const // const ��ü�� ���� ȣ��� const ��� �Լ��� ȣ��
{
    cout << "����ID : " << accID << endl;
    cout << "��  �� : " << cusName << endl;
    cout << "��  �� : " << balance << endl;
}


