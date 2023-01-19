#pragma once
#include "BankAccount.h"

class SavingBankAccount : public BankAccount
{
private:
    double annualInterestRates;
    int period;
    int noSavingMonths;

public:
    void Input();
    void Output();
    void Deposite(double d);
    void Withdraw(double w);
    void WithdrawImmediately(double w);
    double currentBalance();
    double currentInterest();
};