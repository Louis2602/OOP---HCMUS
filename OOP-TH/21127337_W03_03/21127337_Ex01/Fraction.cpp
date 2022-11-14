#include "Fraction.h"

void Fraction::Input()
{
    int num, deno;
    cout << "type numerator : ";
    cin >> num;
    cout << "type denominator : ";
    cin >> deno;
    setDeno(deno);
    setNum(num);
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

Fraction Fraction::operator=(Fraction a)
{
    this->setNum(a.getNum());
    this->setDeno(a.getDeno());
    return *this;
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
bool Fraction::operator==(Fraction a)
{
    a.Reduce();
    this->Reduce();
    return a.getNum() == this->getNum() && a.getDeno() == this->getDeno();
}
bool Fraction::operator!=(Fraction a)
{
    a.Reduce();
    this->Reduce();
    return !(a.getNum() == this->getNum() && a.getDeno() == this->getDeno());
}
bool Fraction::operator>(Fraction a)
{
    Fraction ans;
    ans.setNum(this->getNum() * a.getDeno());
    a.setNum(a.getNum() * this->getDeno());
    if (ans.getNum() > a.getNum())
        return 1;
    return 0;
}
bool Fraction::operator>=(Fraction a)
{
    Fraction ans;
    ans.setNum(this->getNum() * a.getDeno());
    a.setNum(a.getNum() * this->getDeno());
    if (ans.getNum() >= a.getNum())
        return 1;
    return 0;
}
bool Fraction::operator<(Fraction a)
{
    Fraction ans;
    ans.setNum(this->getNum() * a.getDeno());
    a.setNum(a.getNum() * this->getDeno());
    if (ans.getNum() < a.getNum())
        return 1;
    return 0;
}
bool Fraction::operator<=(Fraction a)
{
    Fraction ans;
    ans.setNum(this->getNum() * a.getDeno());
    a.setNum(a.getNum() * this->getDeno());
    if (ans.getNum() <= a.getNum())
        return 1;
    return 0;
}
Fraction Fraction::operator+(int a)
{
    Fraction tmp, ans;
    tmp.setNum(a);
    tmp.setDeno(1);
    ans = *this + tmp;
    return ans;
}
Fraction Fraction::operator-(int a)
{
    Fraction tmp, ans;
    tmp.setNum(a);
    tmp.setDeno(1);
    ans = *this - tmp;
    return ans;
}
Fraction Fraction::operator*(int a)
{
    Fraction tmp, ans;
    tmp.setNum(a);
    tmp.setDeno(1);
    ans = *this * tmp;
    return ans;
}
Fraction Fraction::operator/(int a)
{
    Fraction tmp, ans;
    tmp.setNum(a);
    tmp.setDeno(1);
    ans = *this / tmp;
    return ans;
}
Fraction Fraction::operator+=(Fraction a)
{
    *this = *this + a;
    this->Reduce();
    return *this;
}
Fraction Fraction::operator-=(Fraction a)
{
    *this = *this - a;
    return *this;
}
Fraction Fraction::operator*=(Fraction a)
{
    *this = *this * a;
    return *this;
}
Fraction Fraction::operator/=(Fraction a)
{
    *this = *this / a;
    return *this;
}
Fraction &Fraction::operator++()
{
    Fraction tmp;
    tmp.setNum(1);
    tmp.setDeno(1);
    *this += tmp;
    return *this;
}
Fraction &Fraction::operator++(int)
{
    Fraction tmp = *this;
    ++*this;
    return tmp;
}
Fraction &Fraction::operator--()
{
    Fraction tmp;
    tmp.setNum(1);
    tmp.setDeno(1);
    *this -= tmp;
    return *this;
}
Fraction &Fraction::operator--(int)
{
    Fraction tmp = *this;
    --*this;
    return tmp;
}
Fraction::operator float() const
{
    float ans = (float)Numerator / (float)Denominator;
    return ans;
}

ostream &operator<<(ostream &outDev, Fraction &ps)
{
    outDev << "Fraction: " << ps.getNum() << "/" << ps.getDeno() << '\n';
    return outDev;
}
Fraction operator+(int a, Fraction &ps)
{
    return ps + a;
}
Fraction operator-(int a, Fraction &ps)
{
    return ps - a;
}
Fraction operator*(int a, Fraction &ps)
{
    return ps * a;
}
Fraction operator/(int a, Fraction &ps)
{
    return ps / a;
}