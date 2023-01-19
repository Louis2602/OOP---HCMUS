#include "FractionArray.h"

FractionArray::FractionArray()
{
    vF.clear();
}
FractionArray::FractionArray(int n)
{
    Fraction f;
    for (int i = 0; i < n; i++)
        vF.push_back(f);
    setContent(vF, n);
}
FractionArray::FractionArray(Fraction a[], int n)
{
    vector<Fraction> _vF;
    for (int i = 0; i < n; i++)
        _vF.push_back(a[i]);
    setContent(_vF, n);
}
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

Fraction FractionArray::maxFraction()
{
    Fraction maxF = vF[0];
    for (int i = 0; i < num - 1; i++)
    {
        if (vF[i + 1].Compare(vF[i]) == 1)
            maxF = vF[i + 1];
    }
    return maxF;
}
int FractionArray::countNegative()
{
    int cnt = 0;
    for (int i = 0; i < num; i++)
        if (vF[i].isNegative())
            cnt++;
    return cnt;
}
int FractionArray::countPositive()
{
    int cnt = 0;
    for (int i = 0; i < num; i++)
        if (vF[i].isPositive())
            cnt++;
    return cnt;
}
int FractionArray::countZero()
{
    int cnt = 0;
    for (int i = 0; i < num; i++)
        if (vF[i].isZero())
            cnt++;
    return cnt;
}