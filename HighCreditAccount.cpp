#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(int ID, int money, char* name, int rate, int special)
	: NomalAccount(ID, money, name, rate), m_SpecialRate(special)
{

}

void HighCreditAccount::Deposit(int money)
{
	NomalAccount::Deposit(money);
	Account::Deposit(money * (m_SpecialRate / 100));
}
