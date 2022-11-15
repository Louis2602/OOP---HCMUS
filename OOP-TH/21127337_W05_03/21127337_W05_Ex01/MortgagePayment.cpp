#include "MortgagePayment.h"

MortgagePayment::MortgagePayment(long double _loan, double _rate, int _years)
{
    setLoan(_loan);
    setRate(_rate);
    setYears(_years);
}
long double MortgagePayment::getLoan()
{
    return loan;
}
double MortgagePayment::getRate()
{
    return rate;
}
int MortgagePayment::getYears()
{
    return years;
}
void MortgagePayment::setLoan(long double _loan)
{
    loan = _loan;
}
void MortgagePayment::setRate(double _rate)
{
    rate = _rate;
}
void MortgagePayment::setYears(int _years)
{
    years = _years;
}
long double MortgagePayment::calcMonthlyPayment()
{
    double term = pow((1 + double(rate) / 12), 12 * years);
    long double payment;
    payment = double((loan * double(rate) / 12 * term)) / (term - 1);
    return payment;
}
long double MortgagePayment::totalAmount()
{
    return calcMonthlyPayment() * years;
}