#pragma once
#include <iostream>

using namespace std;

class Fraction
{
    int Numerator, Denominator;

public:
    void Input();
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
    Fraction operator=(Fraction);

    Fraction operator+(int);
    Fraction operator-(int);
    Fraction operator*(int);
    Fraction operator/(int);

    bool operator==(Fraction);
    bool operator!=(Fraction);
    bool operator>(Fraction);
    bool operator>=(Fraction);
    bool operator<(Fraction);
    bool operator<=(Fraction);

    Fraction operator+=(Fraction);
    Fraction operator-=(Fraction);
    Fraction operator*=(Fraction);
    Fraction operator/=(Fraction);

    Fraction &operator++();
    Fraction &operator++(int);
    Fraction &operator--();
    Fraction &operator--(int);

    operator float() const;
    friend ostream &operator<<(ostream &, Fraction &);
    Fraction friend operator+(int, Fraction &);
    Fraction friend operator-(int, Fraction &);
    Fraction friend operator*(int, Fraction &);
    Fraction friend operator/(int, Fraction &);
};