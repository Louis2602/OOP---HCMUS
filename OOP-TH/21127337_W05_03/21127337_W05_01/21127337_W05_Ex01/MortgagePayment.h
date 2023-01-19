#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class MortgagePayment
{
private:
    long double loan;
    double rate;
    int years;

public:
    MortgagePayment(long double, double, int);
    long double getLoan();
    double getRate();
    int getYears();
    void setLoan(long double);
    void setRate(double);
    void setYears(int);
    long double calcMonthlyPayment();
    long double totalAmount();
};