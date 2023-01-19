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
    a.Reduce();
    a.Output();
    b.Reduce();
    b.Output();
    cout << "Compare: " << a.Compare(b) << endl;
    cout << "A is negative? : " << a.isNegative() << endl;
    cout << "A is positive? : " << a.isPositive() << endl;
    cout << "A is zero? : " << a.isZero() << endl;
    return 0;
}
