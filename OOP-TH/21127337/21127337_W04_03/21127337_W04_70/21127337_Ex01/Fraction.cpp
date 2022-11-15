#include "Fraction.h"

Fraction::Fraction()
{
    this->numerator = 0;
    this->denominator = 1;
}
Fraction::Fraction(int x)
{
    this->numerator = x;
    this->denominator = 1;
}
Fraction::Fraction(int x, int y)
{
    this->numerator = x;
    this->denominator = y;
}
Fraction::Fraction(string s)
{
    stringstream ss(s);
    string ts, ms;
    getline(ss, ts, '/');
    getline(ss, ms);
    setNum(stoi(ts));
    setDeno(stoi(ms));
}
void Fraction::Input()
{
    int _num, _deno;
    cout << "Input Numerator: ";
    cin >> _num;
    cout << "Input Denominator: ";
    cin >> _deno;
    setNum(_num);
    setDeno(_deno);
}
void Fraction::setNum(int _numerator)
{
    this->numerator = _numerator;
}
void Fraction::setDeno(int _denominator)
{
    if (_denominator == 0)
    {
        cout << "Denominator cannot be zero!!";
        return;
    }
    this->denominator = _denominator;
}
int Fraction::getNum()
{
    return numerator;
}

int Fraction::getDeno()
{
    return denominator;
}
void Fraction::Output()
{
    cout << "Fraction: " << getNum() << "/" << getDeno() << '\n';
}
void Fraction::LoadFraction(string filename)
{
    fstream fs(filename, ios::in);
    string ts, ms;
    while (!fs.eof())
    {
        getline(fs, ts, '/');
        getline(fs, ms);
    }
    setNum(stoi(ts));
    setDeno(stoi(ms));
    fs.close();
}
void Fraction::SaveFraction(string filename)
{
    fstream fs(filename, ios::out);
    fs << this->numerator << "/" << this->denominator;
    fs.close();
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
        numerator = this->getNum() * -1;
        denominator = this->getDeno() * -1;
    }
    numerator = this->getNum() / gcd;
    denominator = this->getDeno() / gcd;
}
Fraction Fraction::operator+(const Fraction &a)
{
    Fraction ans;
    if (denominator == a.denominator)
    {
        ans.numerator = numerator + a.numerator;
        ans.denominator = this->getDeno();
    }
    else
    {
        ans.numerator = numerator * a.denominator + a.numerator * denominator;
        ans.denominator = denominator * a.denominator;
    }
    ans.Reduce();
    return ans;
}
int Fraction::Compare(Fraction ps)
{
    int ts1, ts2;
    ts1 = this->getNum() * ps.getDeno();
    ts2 = ps.getNum() * this->getDeno();
    int comp = ts1 - ts2;
    if (comp > 0)
        return 1;
    else if (comp < 0)
        return -1;
    else
        return 0;
}
bool Fraction::isNegative()
{
    return numerator * denominator < 0;
}
bool Fraction::isPositive()
{
    return numerator * denominator > 0;
}
bool Fraction::isZero()
{
    return numerator == 0;
}
