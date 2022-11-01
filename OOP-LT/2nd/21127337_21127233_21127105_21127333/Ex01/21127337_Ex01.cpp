#include "Fraction.h"

ostream &operator<<(ostream &outDev, Fraction &ps)
{
	outDev << "Fraction: " << ps.getNum() << "/" << ps.getDeno() << '\n';
	return outDev;
}

Fraction operator+(int a, Fraction &ps)
{
	return ps + a;
}
Fraction operator-(int a, Fraction &ps)
{
	return ps - a;
}
Fraction operator*(int a, Fraction &ps)
{
	return ps * a;
}
Fraction operator/(int a, Fraction &ps)
{
	return ps / a;
}

int main()
{
	Fraction f1, f2;
	Fraction f3;
	Fraction f4;
	Fraction f5;
	Fraction f6, f7, f8;

	f1.Input();
	f2.Input();
	// f3.Input();
	// f4.Input();
	// f5.Input();
	// f6.Input();
	// f7.Input();
	// f8.Input();

	// f6 = f3;

	// f7 = f1 + f5;
	// f8 = f2 - f4;
	// f2 = f3 * f4;
	// f5 = f6 / f3;

	cout << "PS1: ";
	cout << f1;
	cout << "PS2: ";
	cout << f2;
	// cout << "PS3: ";
	// cout << f3;
	// cout << "PS4: ";
	// cout << f4;
	// cout << "PS5: ";
	// cout << f5;

	// cout << (f2 == f3);
	// cout << (f3 != f1);
	// cout << (f2 >= f5);
	// cout << (f2 > f5);
	// cout << (f5 <= f3);
	// cout << (f5 < f3);

	// f1 = f2 + 3;
	// cout << f1;
	// f1 = -7 + f2;
	// cout << f1;
	// f1 = 7 * f2;
	// cout << f1;
	// f1 = f2 - 6;
	// cout << f2;

	// f1 += f2;
	// f1 -= f2;
	// f1 *= f2;
	// f1 /= f2;

	cout << ++f1;
	cout << f1++;

	cout << f2--;
	cout << --f2;

	float f = (float)f2; // 3/2 => 1.5
	cout << f;

	return 0;
}