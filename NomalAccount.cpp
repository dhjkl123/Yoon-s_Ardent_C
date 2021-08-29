#include "NomalAccount.h"

NomalAccount::NomalAccount(int ID, int money, char* name, int rate)
	:m_inerRate(rate), Account(ID, money, name)
{
}

void NomalAccount::Deposit(int money)
{
	Account::Deposit(money);
	Account::Deposit(money * m_inerRate / 100);
}
