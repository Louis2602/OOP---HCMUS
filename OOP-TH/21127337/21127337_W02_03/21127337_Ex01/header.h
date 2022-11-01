#pragma once

#include <iostream>

using namespace std;

class Fraction
{
    int tuso, mauso;

public:
    void Input();
    void Output();
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
