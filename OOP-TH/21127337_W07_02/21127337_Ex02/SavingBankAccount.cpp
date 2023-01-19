#include "SavingBankAccount.h"

void SavingBankAccount::Input()
{
    BankAccount::Input();
    cout << "Enter annualInterestRates: ";
    cin >> annualInterestRates;
    cout << "Enter period: ";
    cin >> period;
    cout << "Enter number of saving months: ";
    cin >> noSavingMonths;
}
void SavingBankAccount::Output()
{
    BankAccount::Output();
    cout << "AnnualInterestRates: " << annualInterestRates << endl;
    cout << "Period: " << period << endl;
    cout << "Number of saving months: " << noSavingMonths << endl;
}
void SavingBankAccount::Deposite(double d)
{
    char opt;
    if (noSavingMonths < period)
    {
        cout << "[ERROR]: Cannot deposite because number of saving months is less than your period.!!!" << endl;
        cout << "Create new saving account to store new amount of money (y/n): ";
        cin >> opt;
        cin.ignore();
        if (opt == 'y')
        {
            cout << "====New account has been created====" << endl;
            SavingBankAccount *newAccount = new SavingBankAccount();
            *this = *newAccount;
            this->Input();
            this->Deposite(d);
            delete newAccount;
        }
        else
            cout << "See you next time!!" << endl;
    }
    else
        balance += d;
}
void SavingBankAccount::Withdraw(double w)
{
    if (noSavingMonths < period)
        cout << "[ERROR]: Cannot withdraw!!!" << endl;
    else
        balance -= w;
}
void SavingBankAccount::WithdrawImmediately(double w)
{
    annualInterestRates = 2.0 / 100;
    balance *= pow((1 + annualInterestRates), noSavingMonths / 12);
}
double SavingBankAccount::currentBalance()
{
    return balance * pow((1 + double(annualInterestRates / 100 * period / 12.0)), noSavingMonths / period);
}
double SavingBankAccount::currentInterest()
{
    return currentBalance() - balance;
}