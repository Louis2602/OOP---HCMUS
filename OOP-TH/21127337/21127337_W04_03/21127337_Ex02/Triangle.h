#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

class Point
{
    double x, y;

public:
    Point();
    Point(double);
    Point(double, double);
    Point(string);
    ~Point(){};

    void Input();
    void Output();
    double GetX();
    double GetY();
    void SetX(double);
    void SetY(double);
    double DistanceAB(Point);
    double DistanceOx();
    double DistanceOy();
    void loadPoint(string);
    void savePoint(string);
};

class Triangle : public Point
{
    Point A, B, C;

public:
    Triangle();
    Triangle(double, double, double, double, double, double);
    Triangle(Point, Point, Point);
    Triangle(string);

    void Input();
    void Output();
    void setTriangle(Point, Point, Point);
    bool isValidTriangle();
    void TypeOfTriangle();

    void loadTriangle(string);
    void saveTriangle(string);

    double Parameter();
    double Area();
};