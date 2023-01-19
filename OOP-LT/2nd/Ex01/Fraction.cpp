#include "Fraction.h"

Fraction Fraction::Input()
{
    int num, deno;
    cout << "type numerator : ";
    cin >> num;
    cout << "type denominator : ";
    cin >> deno;
    Fraction ps;
    ps.setDeno(deno);
    ps.setNum(num);
    return ps;
}

void Fraction::Output()
{
    cout << this->getNum() << "/" << this->getDeno() << endl;
}

int Fraction::getNum()
{
    return Numerator;
}

int Fraction::getDeno()
{
    return Denominator;
}

void Fraction::setDeno(int deno)
{
    if (deno == 0)
        return;
    Denominator = deno;
}

void Fraction::setNum(int num)
{
    Numerator = num;
}

Fraction Fraction::operator+(Fraction a)
{
    Fraction ans;
    if (this->getDeno() == a.Denominator)
    {
        ans.Numerator = this->getNum() + a.Numerator;
        ans.Denominator = this->getDeno();
    }
    else
    {
        ans.Numerator = this->getNum() * a.Denominator + a.Numerator * this->getDeno();
        ans.Denominator = this->getDeno() * a.Denominator;
    }
    ans.Reduce();
    return ans;
}
Fraction Fraction::operator-(Fraction a)
{
    Fraction ans;
    if (this->getDeno() == a.Denominator)
    {
        ans.Numerator = this->getNum() - a.Numerator;
        ans.Denominator = this->getDeno();
    }
    else
    {
        ans.Numerator = this->getNum() * a.Denominator - a.Numerator * this->getDeno();
        ans.Denominator = this->getDeno() * a.Denominator;
    }
    ans.Reduce();
    return ans;
}

Fraction Fraction::operator*(Fraction a)
{
    Fraction ans;
    ans.Numerator = this->getNum() * a.Numerator;
    ans.Denominator = this->getDeno() * a.Denominator;
    ans.Reduce();
    return ans;
}

Fraction Fraction::operator/(Fraction a)
{
    Fraction ans;
    if (a.Numerator == 0)
    {
        cout << "Can not divide by 0" << endl;
        return ans;
    }
    ans.Numerator = this->getNum() * a.Denominator;
    ans.Denominator = this->getDeno() * a.Numerator;
    ans.Reduce();
    return ans;
}
int GCD(int a, int b)
{
    return b == 0 ? a : GCD(b, a % b);
}
void Fraction::Reduce()
{
    int gcd = abs(GCD(this->getNum(), this->getDeno()));
    if (this->getDeno() < 0)
    {
        Numerator = this->getNum() * -1;
        Denominator = this->getDeno() * -1;
    }
    Numerator = this->getNum() / gcd;
    Denominator = this->getDeno() / gcd;
}
void Fraction::Inverse()
{
    swap(Numerator, Denominator);
    Reduce();
}
