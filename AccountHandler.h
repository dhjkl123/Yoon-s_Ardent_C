#pragma once

#include "Account.h"

class AccountHandler
{
private:
	Account* m_accArr[100];
	int m_accNum;
public:
	AccountHandler();
	~AccountHandler();

	void ShowMenu();        //�޴��Է�
	void MakeAccount();     //���°���
	void DepositMoney();    //�Ա�
	void WitharawMoney();   //���
	void ShowAllAccInfo();  //�ܾ���ȸ
};

