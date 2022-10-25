#include "header.h"

int main()
{
    Triangle t;
    t.Input();
    t.Output();
    t.isValidTriangle() == true ? cout << "Valid Triangle\n" : cout << "Invalid Triangle\n";
    cout << "Type of triangle: ";
    t.TypeOfTriangle();
    cout << "Chu vi = " << t.Parameter() << endl;
    cout << "Dien tich = " << t.Area() << endl;
    Point G = t.CenterG();
    cout << "Trong tam G la: ";
    G.Output();
    return 0;
}