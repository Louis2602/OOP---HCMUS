#include "SavingBankAccount.h"

int main()
{
    SavingBankAccount newAccount;
    newAccount.Input();
    newAccount.Deposite(200);
    newAccount.Withdraw(100);
    newAccount.Output();
    cout << "Current Balance: " << newAccount.currentBalance() << endl;
    cout << "Current Interest: " << newAccount.currentInterest() << endl;
    return 0;
}