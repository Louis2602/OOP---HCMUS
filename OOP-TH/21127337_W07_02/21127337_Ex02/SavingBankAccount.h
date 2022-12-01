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
    void Deposite();
    void Withdraw();
    double currentBalance();
    double currentInterest();
};