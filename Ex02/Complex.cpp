#include "Complex.h"

void Complex::Input()
{
    float _real, _im;
    cout << "Real: ";
    cin >> _real;
    cout << "Im: ";
    cin >> _im;
    this->setReal(_real);
    this->setIm(_im);
}
void Complex::Output()
{
    cout << "Complex Number: " << this->getReal() << " + (" << this->getIm() << ")i\n";
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
    return (float)sqrt(this->getReal() * this->getReal() + this->getIm() * this->getIm());
}
Complex Complex::operator+(Complex z)
{
    Complex ans;
    ans.setReal(this->getReal() + z.getReal());
    ans.setIm(this->getIm() + z.getIm());
    return ans;
}

Complex Complex::operator-(Complex z)
{
    Complex ans;
    ans.setReal(this->getReal() - z.getReal());
    ans.setIm(this->getIm() - z.getIm());
    return ans;
}
Complex Complex::operator*(Complex z)
{
    Complex ans;
    ans.setReal(this->getReal() * z.getReal() + this->getIm() * z.getIm() * -1);
    ans.setIm(this->getReal() * z.getIm() + this->getIm() * z.getReal());
    return ans;
}
Complex Complex::operator/(Complex z)
{
    Complex ans;
    float msc = z.module() * z.module();
    ans.setReal((float)(this->getReal() * z.getReal() + this->getIm() * z.getIm()) / msc);
    ans.setIm((float)(this->getIm() * z.getReal() - this->getReal() * z.getIm()) / msc);
    return ans;
}