#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class HomeMortgage
{
private:
    double loan;
    double rate;
    int years;
    string customer_name;

public:
    HomeMortgage();
    HomeMortgage(double, double, int, string);
    double getLoan();
    double getRate();
    int getYears();
    string getName();
    void setLoan(double);
    void setRate(double);
    void setYears(int);
    void setName(string);
    double calcMonthlyPayment();
    double totalAmount();
};