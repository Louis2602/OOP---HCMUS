#pragma once
#include <iostream>
#include <cmath>
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
    virtual void Deposite(double d);
    virtual void Withdraw(double w);
    virtual double currentBalance() = 0;
};