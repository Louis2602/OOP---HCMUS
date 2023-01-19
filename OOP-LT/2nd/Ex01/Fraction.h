#pragma once
#include <iostream>

using namespace std;

class Fraction
{
    int Numerator, Denominator;

public:
    Fraction Input();
    void Output();
    int getNum();
    int getDeno();
    void setNum(int);
    void setDeno(int);
    void Inverse();
    void Reduce();
    Fraction operator+(Fraction);
    Fraction operator-(Fraction);
    Fraction operator*(Fraction);
    Fraction operator/(Fraction);
};
