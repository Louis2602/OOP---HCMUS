#include "header.h"

void Fraction::Input()
{
    do
    {
        cout << "Nhap tu so: ";
        cin >> tuso;
        cout << "Nhap mau so: ";
        cin >> mauso;
    } while (mauso == 0);
}
void Fraction::Output()
{
    cout << "Phan so ban nhap la: " << tuso << " / " << mauso << '\n';
}
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
    if (mauso == ps.mauso)
    {
        ans.tuso = tuso + ps.tuso;
        ans.mauso = mauso;
    }
    else
    {
        ans.tuso = tuso * ps.mauso + ps.tuso * mauso;
        ans.mauso = lcm(mauso, ps.mauso);
    }
    cout << "PS1 + PS2 = " << ans.tuso << " / " << ans.mauso << '\n';
    return ans;
}
Fraction Fraction::Subtract(Fraction ps)
{
    Fraction ans;
    if (mauso == ps.mauso)
    {
        ans.tuso = tuso - ps.tuso;
        ans.mauso = mauso;
    }
    else
    {
        ans.tuso = tuso * ps.mauso - ps.tuso * mauso;
        ans.mauso = lcm(mauso, ps.mauso);
    }
    cout << "PS1 - PS2 = " << ans.tuso << " / " << ans.mauso << '\n';
    return ans;
}
Fraction Fraction::Multiply(Fraction ps)
{
    Fraction ans;
    ans.tuso = tuso * ps.tuso;
    ans.mauso = mauso * ps.mauso;
    cout << "PS1 * PS2 = " << ans.tuso << " / " << ans.mauso << '\n';
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
    cout << "PS1 / PS2 = " << ans.tuso << " / " << ans.mauso << '\n';
    return ans;
}
Fraction Fraction::Reduce()
{
    int UocChung = abs(gcd(tuso, mauso));
    Fraction ans;
    ans.tuso = tuso / UocChung;
    ans.mauso = mauso / UocChung;
    if (ans.mauso < 0)
    {
        ans.mauso = abs(ans.mauso);
        ans.tuso *= -1;
    }
    cout << "Phan so sau khi rut gon = " << ans.tuso << " / " << ans.mauso << '\n';
    return ans;
}
void Fraction::Compare(Fraction ps)
{
    Fraction tmp = Subtract(ps);
    if (tmp.tuso < 0)
        cout << "Phan so 1 > Phan so 2\n";
    else if (tmp.tuso > 0)
        cout << "Phan so 1 < Phan so 2\n";
    else
        cout << "Phan so 1 = Phan so 2\n";
}
bool Fraction::isNegative()
{
    return tuso < 0;
}
bool Fraction::isPositive()
{
    return tuso > 0;
}
bool Fraction::isZero()
{
    return tuso == 0;
}
