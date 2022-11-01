#include "Monomial.h"

int main()
{
    Monomial A, B, temp;
    int coef, pow, x;
    cout << "Enter coefficient of A: ";
    cin >> coef;
    cout << "Enter power of A: ";
    cin >> pow;
    A = A.Input(coef, pow);
    cout << "Monimial A is: ";
    A.Output();

    cout << "Enter coefficient of B: ";
    cin >> coef;
    cout << "Enter power of B: ";
    cin >> pow;
    B = B.Input(coef, pow);
    cout << "Monomial B is: ";
    B.Output();

    cout << "Enter value of x: ";
    cin >> x;
    cout << "Value of monomial A at x = " << x << " is: " << A.ValueatX(x) << endl;

    cout << "Derivative of A is: ";
    temp = A.Derivative();
    temp.Output();

    cout << "Anti derivative of A is: ";
    temp = A.antiDerivative();
    temp.Output();

    temp = A + B;
    cout << "A + B = ";
    temp.Output();

    temp = A - B;
    cout << "A - B = ";
    temp.Output();

    temp = A * B;
    cout << "A * B = ";
    temp.Output();

    temp = A / B;
    cout << "A / B = ";
    temp.Output();

    return 0;
}