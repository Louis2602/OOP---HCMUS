#include "header.h"

void Point::Input()
{
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
}

void Point::Output()
{
    cout << "(" << x << "," << y << ")\n";
}
float Point::DistanceAB(Point b)
{
    return sqrt((b.x - x) * (b.x - x) + (b.y - y) * (b.y - y));
}
float Point::DistanceOx()
{
    return y;
}
float Point::DistanceOy()
{
    return x;
}
float Point::GetX()
{
    return x;
}
float Point::GetY()
{
    return y;
}
void Point::SetX(float _x)
{
    x = _x;
}
void Point::SetY(float _y)
{
    y = _y;
}
void Triangle::Input()
{
    cout << "Nhap toa do dinh A\n";
    A.Input();
    cout << "Nhap toa do dinh B\n";
    B.Input();
    cout << "Nhap toa do dinh C\n";
    C.Input();
}
void Triangle::Output()
{
    A.Output();
    B.Output();
    C.Output();
}
float AB, AC, BC;
bool Triangle::isValidTriangle()
{
    AB = A.DistanceAB(B);
    AC = A.DistanceAB(C);
    BC = B.DistanceAB(C);
    if (AB + BC > AC && AB + AC > BC && AC + BC > AB)
        return true;
    return false;
}
void Triangle::TypeOfTriangle()
{
    cout << AB << " " << BC << " " << AC << endl;
    if ((float)sqrt(AB * AB + BC * BC) == (float)AC || (float)sqrt(AB * AB + AC * AC) == (float)BC || (float)sqrt(BC * BC + AC * AC) == (float)AB)
    {
        if (AB == AC || AC == BC || AB == BC)
            cout << "Right-angled Isosceles triangle" << endl;
        else
            cout << "Right-angled triangle" << endl;
    }
    else
    {
        if (AB == AC && AC == BC)
            cout << "Equilateral triangle" << endl;
        else if (AB == AC || AC == BC || AB == BC)
            cout << "Isosceles triangle" << endl;
        else
            cout << "Scalene triangle" << endl;
    }
}
float Triangle::Parameter()
{
    return AB + AC + BC;
}
float Triangle::Area()
{
    float p = (AB + BC + AC) / 2;
    return sqrt(p * (p - AB) * (p - AC) * (p - BC));
}
Point Triangle::CenterG()
{
    Point G;
    float x = (A.GetX() + B.GetX() + C.GetX()) / 3;
    float y = (A.GetY() + B.GetY() + C.GetY()) / 3;
    G.SetX(x);
    G.SetY(y);
    return G;
}
