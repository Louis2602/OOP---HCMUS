#include "header.h"

int main()
{
    Fraction a, b;
    Fraction ans;
    a.Input();
    a.Output();
    b.Input();
    b.Output();
    ans = a.Add(b);
    cout << "+: ";
    ans.Output();
    ans = a.Subtract(b);
    cout << "-: ";
    ans.Output();
    ans = a.Multiply(b);
    cout << "*: ";
    ans.Output();
    ans = a.Divide(b);
    cout << "/: ";
    ans.Output();
    cout << "Rut gon: \n";
    a = a.Reduce();
    a.Output();
    b = b.Reduce();
    b.Output();
    cout << a.Compare(b) << endl;
    cout << a.isNegative() << endl;
    cout << a.isPositive() << endl;
    cout << a.isZero() << endl;
    return 0;
}