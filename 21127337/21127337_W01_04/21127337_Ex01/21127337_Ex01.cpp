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
    ans.Reduce();
    ans = a.Subtract(b);
    ans.Reduce();
    ans = a.Multiply(b);
    ans.Reduce();
    ans = a.Divide(b);
    ans.Reduce();
    a.Reduce();
    b.Reduce();
    cout << a.isNegative() << endl;
    cout << a.isPositive() << endl;
    cout << a.isZero() << endl;
    return 0;
}