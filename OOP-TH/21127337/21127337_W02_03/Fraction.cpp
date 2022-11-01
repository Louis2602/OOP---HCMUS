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
    cout << "Fraction: " << getNum() << " / " << getDeno() << '\n';
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