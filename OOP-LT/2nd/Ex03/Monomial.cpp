#include "Monomial.h"

Monomial Monomial::Input(float coef, float pow)
{
    Monomial newm;
    newm.assignCoef(coef);
    newm.assignPow(pow);
    return newm;
}

void Monomial::Output()
{
    cout << getCoef() << "x^" << getPow() << endl;
}

float Monomial::getCoef()
{
    return Coef;
}

float Monomial::getPow()
{
    return Pow;
}
void Monomial::assignCoef(float coef)
{
    this->Coef = (float)coef;
}
void Monomial::assignPow(float pow)
{
    this->Pow = (float)pow;
}

int Monomial::ValueatX(float x)
{
    return this->Coef * pow(x, this->Pow);
}

Monomial Monomial::Derivative()
{
    Monomial temp;
    temp.assignCoef(this->Pow * this->Coef);
    temp.assignPow(this->Pow - 1);
    return temp;
}

Monomial Monomial::antiDerivative()
{
    Monomial temp;
    temp.assignPow(this->Pow + 1);
    temp.assignCoef((float)this->Coef / (this->Pow + 1));
    return temp;
}

Monomial Monomial::operator+(Monomial B)
{
    Monomial temp;
    temp.assignCoef(0);
    temp.assignPow(0);
    if (this->Pow == B.getPow())
    {
        temp.assignCoef(B.getCoef() + this->Coef);
        temp.assignPow(B.getPow());
    }
    else
    {
        cout << "2 monomials with different powers cannot be added" << endl;
        return temp;
    }
    return temp;
}

Monomial Monomial::operator-(Monomial B)
{
    Monomial temp;
    temp.assignCoef(0);
    temp.assignPow(0);
    if (this->Pow == B.getPow())
    {
        temp.assignCoef(this->Coef - B.getCoef());
        temp.assignPow(B.getPow());
    }
    else
    {
        cout << "2 monomials with different powers cannot be subtracted" << endl;
        return temp;
    }
    return temp;
}

Monomial Monomial::operator*(Monomial B)
{
    Monomial temp;
    temp.assignCoef(this->Coef * B.getCoef());
    temp.assignPow(this->Pow + B.getPow());
    return temp;
}

Monomial Monomial::operator/(Monomial B)
{
    Monomial temp;
    temp.assignCoef(this->Coef / B.getCoef());
    temp.assignPow(this->Pow - B.getPow());
    return temp;
}