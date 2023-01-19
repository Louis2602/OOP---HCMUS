#include "TriangleArray.h"
TriangleArray::TriangleArray()
{
    array = nullptr;
    num = 0;
}

TriangleArray::TriangleArray(int n)
{
    Triangle t;
    Triangle *tmp = new Triangle[n];
    for (int i = 0; i < n; i++)
        tmp[i] = t;
    setContent(tmp, n);
}
TriangleArray::TriangleArray(Triangle a[], int n)
{
    Triangle *tmp = new Triangle[n];
    for (int i = 0; i < n; i++)
        tmp[i] = a[i];
    setContent(tmp, n);
}
TriangleArray::TriangleArray(vector<Triangle> a)
{
    int n = a.size();
    Triangle *tmp = new Triangle[n];
    for (int i = 0; i < n; i++)
        tmp[i] = a[i];
    setContent(tmp, n);
}
TriangleArray::TriangleArray(string s)
{
    stringstream ss(s);
    int cnt = 0;
    string tmp;
    while (!ss.eof())
    {
        ss.ignore();
        getline(ss, tmp, ']');
        ss.ignore();
        cnt++;
    }
    Triangle *a = new Triangle[cnt];
    int i = 0;
    ss.clear();
    ss.seekg(0, ios::beg);
    while (i < cnt)
    {
        ss.ignore();
        getline(ss, tmp, ']');
        ss.ignore();
        Triangle t(tmp);
        a[i] = t;
        i++;
    }
    setContent(a, cnt);
}

int TriangleArray::getNum()
{
    return num;
}
Triangle *TriangleArray::getArr()
{
    Triangle *tmp = array;
    return tmp;
}
void TriangleArray::setContent(Triangle *t, int n)
{
    array = new Triangle[n];
    num = n;
    for (int i = 0; i < n; i++)
        array[i] = t[i];
}
void TriangleArray::Output()
{
    for (int i = 0; i < this->getNum(); i++)
        array[i].Output();
}
void TriangleArray::Input()
{
    int n;
    cout << "Input number of triangles: ";
    cin >> n;
    Triangle *tmp = new Triangle[n];
    Triangle t;
    for (int i = 0; i < n; i++)
    {
        cout << "Input triangle " << i + 1 << ":\n";
        t.Input();
        tmp[i] = t;
    }
    setContent(tmp, n);
}
void TriangleArray::loadTriangleArray(string filename)
{
    fstream fs(filename, ios::in);
    string s;
    getline(fs, s);
    TriangleArray tmp(s);
    *this = tmp;
    fs.close();
}
void TriangleArray::saveTriangleArray(string filename)
{
    fstream fs(filename, ios::out);
    string s;
    for (int i = 0; i < num; i++)
    {
        fs << "[(" << array[i].getA().GetX() << "," << array[i].getA().GetY() << ")(" << array[i].getB().GetX() << "," << array[i].getB().GetY() << ")(" << array[i].getC().GetX() << "," << array[i].getC().GetY() << ")]";
        if (i != num - 1)
            fs << ";";
    }
    fs.close();
}
void TriangleArray::invalidTriangles()
{
    Triangle *t = new Triangle[num];
    int n = 0;
    for (int i = 0; i < num; i++)
    {
        if (!array[i].isValidTriangle())
        {
            t[n] = array[i];
            n++;
        }
    }
    setContent(t, n);
}
Triangle TriangleArray::maxArea()
{
    int maxA = array[0].Area();
    Triangle tg;
    for (int i = 0; i < num - 1; i++)
    {
        if (array[i + 1].Area() > maxA)
        {
            maxA = array[i + 1].Area();
            tg = array[i + 1];
        }
    }
    return tg;
}
void TriangleArray::countTypeTriangles()
{
    int TGVC, TGV, TGD, TGC, TGT;
    TGVC = TGV = TGD = TGC = TGT = 0;
    for (int i = 0; i < num; i++)
    {
        if (array[i].TypeOfTriangle() == 1)
            TGVC++;
        else if (array[i].TypeOfTriangle() == 2)
            TGV++;
        else if (array[i].TypeOfTriangle() == 3)
            TGD++;
        else if (array[i].TypeOfTriangle() == 4)
            TGC++;
        else if (array[i].TypeOfTriangle() == 5)
            TGT++;
    }
    cout << "Number of Right-angled Isosceles triangle: " << TGVC << endl;
    cout << "Number of Right-angled triangle: " << TGV << endl;
    cout << "Number of Equilateral triangle: " << TGD << endl;
    cout << "Number of Isosceles triangle: " << TGC << endl;
    cout << "Number of scalene triangle: " << TGT << endl;
}