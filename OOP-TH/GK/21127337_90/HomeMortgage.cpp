#include "HomeMortgage.h"

HomeMortgage::HomeMortgage()
{
    loan = 0;
    rate = 0;
    years = 0;
    customer_name = "";
}
HomeMortgage::HomeMortgage(double _loan, double _rate, int _years, string _name)
{
    setLoan(_loan);
    setRate(_rate);
    setYears(_years);
    setName(_name);
}
string HomeMortgage::getName()
{
    return customer_name;
}
void HomeMortgage::setName(string name)
{
    customer_name = name;
}
double HomeMortgage::getLoan()
{
    return loan;
}
double HomeMortgage::getRate()
{
    return rate;
}
int HomeMortgage::getYears()
{
    return years;
}
void HomeMortgage::setLoan(double _loan)
{
    loan = _loan;
}
void HomeMortgage::setRate(double _rate)
{
    rate = _rate / 100;
}
void HomeMortgage::setYears(int _years)
{
    years = _years;
}
double HomeMortgage::calcMonthlyPayment()
{
    double term = pow((1 + double(rate) / 12), 12 * years);
    double payment;
    payment = double((loan * double(rate) / 12 * term)) / (term - 1);
    return payment;
}
double HomeMortgage::totalAmount()
{
    return calcMonthlyPayment() * (years * 12);
}