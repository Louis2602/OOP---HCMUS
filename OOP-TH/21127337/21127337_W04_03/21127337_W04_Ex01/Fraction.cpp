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
int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}
int Fraction::Compare(Fraction ps)
{
    int msc = LCM(this->getDeno(), ps.getDeno());
    int ts1, ts2;
    ts1 = this->getNum() * msc;
    ts2 = ps.getNum() * msc;
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

// =========================================== //
FractionArray::FractionArray()
{
    vF.clear();
}
FractionArray::FractionArray(Fraction f)
{
    int n;
    cout << "Input number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        vF.push_back(f);
    setContent(vF, n);
}
// FractionArray::FractionArray(Fraction[], int) {

// }
FractionArray::FractionArray(vector<Fraction> _vF)
{
    setContent(_vF, _vF.size());
}
FractionArray::FractionArray(string s)
{
    stringstream ss(s);
    string ts, ms;
    string ps;
    int cnt = 0;
    vector<Fraction> _vF;
    while (ss >> ps)
    {
        cnt++;
        stringstream _ps(ps);
        getline(_ps, ts, '/');
        getline(_ps, ms);
        setNum(stoi(ts));
        setDeno(stoi(ms));
        _vF.push_back(*this);
    }
    setContent(_vF, cnt);
}
int FractionArray::getSize()
{
    return num;
}
vector<Fraction> FractionArray::getVF()
{
    return vF;
}
void FractionArray::setContent(vector<Fraction> f, int n)
{
    num = n;
    vF = f;
}
void FractionArray::Input()
{
    Fraction tmp;
    int n;
    cout << "Input number of fractions: ";
    cin >> n;
    int num, deno;
    vector<Fraction> _vF;
    for (int i = 0; i < n; i++)
    {
        cout << "Input Fraction " << i + 1 << ":\n";
        cout << "Input Numerator: ";
        cin >> num;
        cout << "Input Denominator: ";
        cin >> deno;
        setNum(num);
        setDeno(deno);
        _vF.push_back(*this);
    }
    setContent(_vF, n);
}
void FractionArray::Output()
{
    cout << "Fraction: ";
    for (int i = 0; i < num; i++)
        cout << vF[i].getNum() << "/" << vF[i].getDeno() << ", ";
    cout << endl;
}

void FractionArray::LoadArrFractions(string filename)
{
    fstream fs(filename, ios::in);
    string s;
    getline(fs, s);
    stringstream ss(s);
    string ts, ms;
    string ps;
    int cnt = 0;
    vector<Fraction> _vF;
    while (ss >> ps)
    {
        cnt++;
        stringstream _ps(ps);
        getline(_ps, ts, '/');
        getline(_ps, ms);
        setNum(stoi(ts));
        setDeno(stoi(ms));
        _vF.push_back(*this);
    }
    setContent(_vF, cnt);
    fs.close();
}
void FractionArray::SaveArrFractions(string filename)
{
    fstream fs(filename, ios::out);
    for (int i = 0; i < num; i++)
        fs << vF[i].getNum() << "/" << vF[i].getDeno() << " ";
    fs.close();
}
Fraction FractionArray::SumAllFractions()
{
    Fraction sum;
    for (int i = 0; i < num; i++)
    {
        sum = sum + vF[i];
    }
    return sum;
}