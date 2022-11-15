#include "OOPMath.h"

double Math::absOOP(double x)
{
    return abs(x);
}
long double Math::powOOP(double base, double exponent)
{
    return pow(base, exponent);
}
double Math::sqrtOOP(double x)
{
    return sqrt(x);
}
int Math::ceilOOP(double x)
{
    return ceil(x);
}
int Math::floorOOP(double x)
{
    return floor(x);
}
int Math::roundOOP(double x)
{
    return round(x);
}
double Math::logOOP(double x)
{
    return log(x);
}
double Math::log2OOP(double x)
{
    return log2(x);
}
double Math::sinOOP(double x)
{
    return sin(x * PI / 180);
}
double Math::cosOOP(double x)
{
    return cos(x * PI / 180);
}
double Math::tanOOP(double x)
{
    return tan(x * PI / 180);
}
double Math::asinOOP(double x)
{
    return asin(x) * 180 / PI;
}
double Math::acosOOP(double x)
{
    return acos(x) * 180 / PI;
}
double Math::atanOOP(double x)
{
    return atan(x) * 180 / PI;
}
double Math::expOOP(double x)
{
    return exp(x);
}