#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
private:
    float real, im;

public:
    void Input();
    void Output();
    float getReal();
    float getIm();
    void setReal(float);
    void setIm(float);
    float module();
    Complex operator+(Complex);
    Complex operator-(Complex);
    Complex operator*(Complex);
    Complex operator/(Complex);
};