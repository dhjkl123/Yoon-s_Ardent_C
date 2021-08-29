#pragma once
#include "Account.h"
class NomalAccount : public Account
{
private:
	int m_inerRate;

public:
	NomalAccount(int ID, int money, char* name, int rate);

	virtual void Deposit(int money);



};

