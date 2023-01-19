#pragma once

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

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
    Fraction operator+(const Fraction &);
    void Reduce();
    int Compare(Fraction);
    bool isPositive();
    bool isNegative();
    bool isZero();
};