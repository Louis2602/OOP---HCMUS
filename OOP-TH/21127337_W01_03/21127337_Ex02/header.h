#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class Point
{
    float x, y;

public:
    void Input();
    void Output();
    float GetX();
    float GetY();
    void SetX(float);
    void SetY(float);
    float DistanceAB(Point);
    float DistanceOx();
    float DistanceOy();
};

class Triangle : public Point
{
    Point A, B, C;

public:
    void Input();
    void Output();
    bool isValidTriangle();
    void TypeOfTriangle();
    float Parameter();
    float Area();
    Point CenterG();
};