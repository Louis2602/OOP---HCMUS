#pragma once

#include <iostream>

using namespace std;

class Fraction
{
    int numerator, denominator;

public:
    Fraction(int, int);
    int getNum();
    int getDeno();
    void setNum(int);
    void setDeno(int);
    Fraction Add(Fraction);
    Fraction Subtract(Fraction);
    Fraction Multiply(Fraction);
    Fraction Divide(Fraction);
    void Reduce();
    int Compare(Fraction);
    bool isPositive();
    bool isNegative();
    bool isZero();
};
