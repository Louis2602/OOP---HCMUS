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

    void loadTriangleArray();
    void saveTriangleArray();

    TriangleArray validTriangles();
    Triangle maxArea();
    void countTypeTriangles();
};