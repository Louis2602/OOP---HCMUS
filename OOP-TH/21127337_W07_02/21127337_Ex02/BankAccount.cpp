#include "BankAccount.h"

void BankAccount::Input()
{
    cout << "Enter your account number: ";
    getline(cin, accountNumber);
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your id: ";
    getline(cin, id);
    cout << "Enter your balance: ";
    cin >> balance;
}

void BankAccount::Output()
{
    cout << "========INFORMATION========" << endl;
    cout << "Account number: " << accountNumber << endl;
    cout << "Name of owner: " << name << endl;
    cout << "Social ID of owner: " << id << endl;
    cout << "Balance: " << balance << endl;
}
void BankAccount::Deposite(double d)
{
    balance += d;
}
void BankAccount::Withdraw(double w)
{
    if (balance < 50000)
        cout << "[ERROR]: Cannot withdraw because your balance is below 50000" << endl;
    else
        balance -= w;
}
double BankAccount::currentBalance()
{
    return balance;
}