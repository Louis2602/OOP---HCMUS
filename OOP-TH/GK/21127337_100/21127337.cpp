#include "Bank.h"

int main()
{
    // HomeMortgage mp(150000, 2.87, 15);
    // cout << "Monthly Payment: " << mp.calcMonthlyPayment() << endl;
    // cout << "Total amount paid to the bank: " << mp.totalAmount() << endl;
    Bank bk;
    bk.inputBankInfo();
    // bk.outputList();
    cout << "Total Money: " << bk.totalMoney() << endl;
    bk.countSameInterestRateVal();
    bk.sortInfo();
    bk.outputList();
    bk.saveInfo("bank.txt");

    return 0;
}