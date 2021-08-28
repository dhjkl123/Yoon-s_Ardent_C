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

	void ShowMenu();        //메뉴입력
	void MakeAccount();     //계좌개설
	void DepositMoney();    //입금
	void WitharawMoney();   //출금
	void ShowAllAccInfo();  //잔액조회
};

