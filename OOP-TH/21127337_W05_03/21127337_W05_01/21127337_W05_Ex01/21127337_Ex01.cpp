#include "MortgagePayment.h"

int main()
{
    MortgagePayment mp(150000, 2.87, 15);
    cout << "Monthly Payment: " << mp.calcMonthlyPayment() << endl;
    cout << "Total amount paid to the bank: " << mp.totalAmount() << endl;
    return 0;
}