#include <iostream>
#include <math.h>

using namespace std;

class Monomial
{
    float Coef, Pow;

public:
    Monomial(){};
    ~Monomial(){};
    Monomial Input(float, float);
    void Output();
    float getCoef();
    float getPow();
    void assignCoef(float);
    void assignPow(float);
    int ValueatX(float);
    Monomial Derivative();
    Monomial antiDerivative();
    Monomial operator+(Monomial);
    Monomial operator-(Monomial);
    Monomial operator*(Monomial);
    Monomial operator/(Monomial);
};