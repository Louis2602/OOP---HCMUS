#include "Triangle.h"

int main()
{
    // Point a;
    // a.Output();
    Point b(3);
    b.Output();
    Point c(3, 5);
    c.Output();
    Point d("(3,11)");
    d.Output();
    // Point e;
    // e.loadPoint("load.txt");
    // e.Output();
    // e.savePoint("save.txt");
    // cout << "Distance: " << c.DistanceAB(d);

    Triangle a1;
    cout << "Default Constructor:\n";
    a1.Output();
    Triangle b1(1, 1, 2, 3, 3, 5);
    cout << "6-double Constructor:\n";
    b1.Output();
    Triangle c1(b, c, d);
    cout << "3-Points Constructor:\n";
    c1.Output();
    Triangle d1("(0,0)(0,1)(1,0)");
    cout << "String Constructor:\n";
    d1.Output();
    Triangle e1;
    e1.Input();
    e1.Output();
    b1.isValidTriangle() == true ? cout << "Valid Triangle\n" : cout << "Invalid Triangle\n";
    cout << "Type of triangle: ";
    b1.TypeOfTriangle();
    cout << "Chu vi = " << b1.Parameter() << endl;
    cout << "Dien tich = " << b1.Area() << endl;

    Triangle f;
    f.loadTriangle("load.txt");
    f.Output();
    f.saveTriangle("save.txt");
    return 0;
}