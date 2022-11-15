#include "MortgagePayment.h"

int main()
{
    MortgagePayment mp(120000000, 0.12, 4);
    cout << "Monthly Payment: " << mp.calcMonthlyPayment() << endl;
    cout << "Total amount paid to the bank: " << mp.totalAmount() << endl;
    return 0;
}