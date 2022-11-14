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
    this->loan = _loan;
}
void MortgagePayment::setRate(double _rate)
{
    this->rate = _rate;
}
void MortgagePayment::setYears(int _years)
{
    this->years = _years;
}
long double MortgagePayment::calcMonthlyPayment()
{
    double term = pow((1 + double(this->rate) / 12), 12 * this->years);
    long double payment;
    payment = double((this->loan * double(this->rate) / 12 * term)) / (term - 1);
    return payment;
}
long double MortgagePayment::totalAmount()
{
    return this->calcMonthlyPayment() * this->years;
}