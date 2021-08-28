#pragma once
class Account
{
private:
    int accID;
    int balance;
    char* cusName;

public:
    Account(int ID, int money, char* name);
    Account(const Account& ref);
    ~Account();

    int GetAccID() const;
    void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const; // const 객체를 통해 호출시 const 멤버 함수를 호출

};


