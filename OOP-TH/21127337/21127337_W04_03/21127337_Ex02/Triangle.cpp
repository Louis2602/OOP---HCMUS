#include "Triangle.h"

Point::Point()
{
    x = y = 0;
}

Point::Point(double param)
{
    x = y = param;
}
Point::Point(double p1, double p2)
{
    x = p1;
    y = p2;
}
Point::Point(string s)
{
    stringstream ss(s);
    string tmp;
    ss.ignore();
    getline(ss, tmp, ',');
    SetX(stof(tmp));
    getline(ss, tmp, ')');
    SetY(stof(tmp));
}
void Point::Input()
{
    double _x, _y;
    cout << "Nhap x: ";
    cin >> _x;
    cout << "Nhap y: ";
    cin >> _y;
    SetX(_x);
    SetY(_y);
}

void Point::Output()
{
    cout << "(" << GetX() << "," << GetY() << ")\n";
}
double Point::DistanceAB(Point b)
{
    return sqrt((b.x - x) * (b.x - x) + (b.y - y) * (b.y - y));
}
double Point::DistanceOx()
{
    return y;
}
double Point::DistanceOy()
{
    return x;
}
double Point::GetX()
{
    return x;
}
double Point::GetY()
{
    return y;
}
void Point::SetX(double _x)
{
    x = _x;
}
void Point::SetY(double _y)
{
    y = _y;
}
void Point::loadPoint(string filename)
{
    fstream fs(filename, ios::in);
    string tmp;
    fs.ignore();
    getline(fs, tmp, ',');
    SetX(stof(tmp));
    getline(fs, tmp, ')');
    SetY(stof(tmp));
    fs.close();
}
void Point::savePoint(string filename)
{
    fstream fs(filename, ios::out);
    fs << "(" << GetX() << "," << GetY() << ")";
    fs.close();
}
// =================================================//
Triangle::Triangle()
{
    A.SetX(0);
    A.SetY(0);
    B.SetX(0);
    B.SetY(1);
    C.SetX(1);
    C.SetY(0);
}
Triangle::Triangle(double xA, double yA, double xB, double yB, double xC, double yC)
{
    A.SetX(xA);
    A.SetY(yA);
    B.SetX(xB);
    B.SetY(yB);
    C.SetX(xC);
    C.SetY(yC);
}
Triangle::Triangle(Point a, Point b, Point c)
{
    setTriangle(a, b, c);
}
Triangle::Triangle(string s)
{
    Point p[3];
    stringstream ss(s);
    string tmp;
    int i = 0;
    while (i < 3)
    {
        ss.ignore();
        getline(ss, tmp, ',');
        p[i].SetX(stof(tmp));
        getline(ss, tmp, ')');
        p[i].SetY(stof(tmp));
        i++;
    }
    setTriangle(p[0], p[1], p[2]);
}
void Triangle::setTriangle(Point a, Point b, Point c)
{
    A.SetX(a.GetX());
    A.SetY(a.GetY());
    B.SetX(b.GetX());
    B.SetY(b.GetY());
    C.SetX(c.GetX());
    C.SetY(c.GetY());
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
double AB, AC, BC;
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
    if ((double)sqrt(AB * AB + BC * BC) == (double)AC || (double)sqrt(AB * AB + AC * AC) == (double)BC || (double)sqrt(BC * BC + AC * AC) == (double)AB)
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
double Triangle::Parameter()
{
    return AB + AC + BC;
}
double Triangle::Area()
{
    double p = (AB + BC + AC) / 2;
    return sqrt(p * (p - AB) * (p - AC) * (p - BC));
}

void Triangle::loadTriangle(string filename)
{
    fstream fs(filename, ios::in);
    string tmp;
    getline(fs, tmp);
    stringstream ss(tmp);
    int i = 0;
    Point p[3];
    while (i < 3)
    {
        ss.ignore();
        getline(ss, tmp, ',');
        p[i].SetX(stof(tmp));
        getline(ss, tmp, ')');
        p[i].SetY(stof(tmp));
        i++;
    }
    setTriangle(p[0], p[1], p[2]);
    fs.close();
}
void Triangle::saveTriangle(string filename)
{
    fstream fs(filename, ios::out);
    fs << "(" << A.GetX() << "," << A.GetY() << ")(" << B.GetX() << "," << B.GetY() << ")(" << C.GetX() << "," << C.GetY() << ")";
    fs.close();
}
