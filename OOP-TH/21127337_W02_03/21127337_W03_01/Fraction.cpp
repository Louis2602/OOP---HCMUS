#include "Fraction.h"



int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
Fraction Fraction::Add(Fraction ps)
{
    Fraction ans;
    ans.mauso = lcm(mauso, ps.mauso);
    if (mauso == ps.mauso)
    {
        ans.tuso = tuso + ps.tuso;
        ans.mauso = mauso;
    }
    else
    {
        ans.tuso = tuso * (ans.mauso / mauso) + ps.tuso * (ans.mauso / ps.mauso);
    }
    ans.Reduce();
    return ans;
}
Fraction Fraction::Subtract(Fraction ps)
{
    Fraction ans;
    ans.mauso = lcm(mauso, ps.mauso);
    if (mauso == ps.mauso)
    {
        ans.tuso = tuso - ps.tuso;
        ans.mauso = mauso;
    }
    else
    {
        ans.tuso = tuso * (ans.mauso / mauso) - ps.tuso * (ans.mauso / ps.mauso);
    }
    ans.Reduce();
    return ans;
}
Fraction Fraction::Multiply(Fraction ps)
{
    Fraction ans;
    ans.tuso = tuso * ps.tuso;
    ans.mauso = mauso * ps.mauso;
    ans.Reduce();
    return ans;
}
Fraction Fraction::Divide(Fraction ps)
{
    Fraction ans;
    if (ps.tuso == 0)
    {
        cerr << "Phan so chia la so 0 nen khong the thuc hien phep chia duoc!!!\n";
        return ans;
    }
    ans.tuso = tuso * ps.mauso;
    ans.mauso = mauso * ps.tuso;
    ans.Reduce();
    return ans;
}
void Fraction::Reduce()
{
    int UocChung = abs(gcd(tuso, mauso));
    tuso = tuso / UocChung;
    mauso = mauso / UocChung;
    if (mauso < 0)
    {
        mauso = abs(mauso);
        tuso *= -1;
    }
}
int Fraction::Compare(Fraction ps)
{
    Fraction tmp = Subtract(ps);
    float comp = (float)tmp.tuso / tmp.mauso;
    if (comp > 0)
        return 1;
    else if (comp < 0)
        return -1;
    else
        return 0;
}
bool Fraction::isNegative()
{
    return tuso * mauso < 0;
}
bool Fraction::isPositive()
{
    return tuso * mauso > 0;
}
bool Fraction::isZero()
{
    return tuso == 0;
}
