#include "Complex.h"

void Complex::Input()
{
    float _real, _im;
    cout << "Real: ";
    cin >> _real;
    cout << "Im: ";
    cin >> _im;
    setReal(_real);
    setIm(_im);
}
void Complex::Output()
{
    cout << "Complex Number: " << getReal() << " + (" << getIm() << ")i\n";
}
float Complex::getReal()
{
    return real;
}
float Complex::getIm()
{
    return im;
}
void Complex::setReal(float _real)
{
    real = _real;
}
void Complex::setIm(float _im)
{
    im = _im;
}

float Complex::module()
{
    return (float)sqrt(getReal() * getReal() + getIm() * getIm());
}
Complex Complex::operator+(Complex z)
{
    Complex ans;
    ans.setReal(getReal() + z.getReal());
    ans.setIm(getIm() + z.getIm());
    return ans;
}

Complex Complex::operator-(Complex z)
{
    Complex ans;
    ans.setReal(getReal() - z.getReal());
    ans.setIm(getIm() - z.getIm());
    return ans;
}
Complex Complex::operator*(Complex z)
{
    Complex ans;
    ans.setReal(getReal() * z.getReal() + getIm() * z.getIm() * -1);
    ans.setIm(getReal() * z.getIm() + getIm() * z.getReal());
    return ans;
}
Complex Complex::operator/(Complex z)
{
    Complex ans;
    float msc = z.module() * z.module();
    ans.setReal((float)(getReal() * z.getReal() + getIm() * z.getIm()) / msc);
    ans.setIm((float)(getIm() * z.getReal() - getReal() * z.getIm()) / msc);
    return ans;
}