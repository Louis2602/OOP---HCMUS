#pragma once
#ifndef OOPMath
#define OOPMath

#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265

class Math
{
public:
    static double absOOP(double);
    static long double powOOP(double, double);
    static double sqrtOOP(double);
    static int ceilOOP(double);
    static int floorOOP(double);
    static int roundOOP(double);
    static double logOOP(double);
    static double log2OOP(double);
    static double sinOOP(double);
    static double cosOOP(double);
    static double tanOOP(double);
    static double asinOOP(double);
    static double acosOOP(double);
    static double atanOOP(double);
    static double expOOP(double);
};
#endif