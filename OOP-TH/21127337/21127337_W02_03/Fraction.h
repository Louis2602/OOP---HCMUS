#pragma once

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Fraction
{
    int numerator, denominator;

public:
    Fraction();
    Fraction(int);
    Fraction(int, int);
    Fraction(string);
    ~Fraction(){};
    int getNum();
    int getDeno();
    void setNum(int);
    void setDeno(int);
    void LoadFraction(string);
    void SaveFraction(string);
    void Input();
    void Output();
    Fraction Add(Fraction);
    int Compare(Fraction);
    bool isPositive();
    bool isNegative();
    bool isZero();
};