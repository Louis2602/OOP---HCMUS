#include "Fraction.h"

istream &operator>>(istream &inDev, Fraction &ps)
{
    int num, deno;
    inDev >> num >> deno;
    ps.setDeno(deno);
    ps.setNum(num);
    return inDev;
}

int main()
{
    Fraction ps1, ps2;
    // ps1 = ps1.Input();
    // ps2 = ps2.Input();
    cout << "Input Fraction:\n";
    cin >> ps1 >> ps2;
    cout << "Fraction 1: ";
    ps1.Output();
    cout << "Fraction 2: ";
    ps2.Output();

    Fraction ans;
    cout << "+: ";
    ans = ps1 + ps2;
    ans.Output();

    cout << "-: ";
    ans = ps1 - ps2;
    ans.Output();

    cout << "*: ";
    ans = ps1 * ps2;
    ans.Output();

    cout << "/: ";
    ans = ps1 / ps2;
    ans.Output();

    cout << "Reduce: ";
    ps1.Reduce();
    ps1.Output();
    ps2.Reduce();
    ps2.Output();

    cout << "Inverse: ";
    ps1.Inverse();
    ps1.Output();
    ps2.Inverse();
    ps2.Output();

    return 0;
}