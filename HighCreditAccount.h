#pragma once
#include "NomalAccount.h"
class HighCreditAccount : public NomalAccount
{
private:
	int m_SpecialRate;
public:
	HighCreditAccount(int ID, int money, char* name, int rate, int special);

	virtual void Deposit(int money);
};

