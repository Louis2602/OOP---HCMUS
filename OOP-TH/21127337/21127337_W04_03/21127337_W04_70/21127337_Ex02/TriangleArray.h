#pragma once
#include "Triangle.h"
#include <vector>

class TriangleArray
{
    Triangle *array;
    int num;

public:
    TriangleArray();
    TriangleArray(int);
    TriangleArray(Triangle[], int);
    TriangleArray(vector<Triangle>);
    TriangleArray(string);

    void Input();
    void Output();

    int getNum();
    Triangle *getArr();
    void setContent(Triangle *, int);

    void loadTriangleArray(string);
    void saveTriangleArray(string);

    void invalidTriangles();
    Triangle maxArea();
    void countTypeTriangles();
};