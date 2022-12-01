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
void BankAccount::Deposite()
{
    double amount;
    cout << "Enter the amount of money you want to deposite: ";
    cin >> amount;
}