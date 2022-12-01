#pragma once
#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
protected:
    string accountNumber;
    string name;
    string id;
    double balance;

public:
    virtual void Input();
    virtual void Output();
    virtual void Deposite();
    virtual void Withdraw();
    virtual double currentBalance() = 0;
};