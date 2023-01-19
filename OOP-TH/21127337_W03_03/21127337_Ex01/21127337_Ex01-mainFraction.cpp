#include "Fraction.h"

int main()
{
	Fraction f1, f2, f3;
	Fraction f;

	f1.Input();
	f2.Input();
	f3.Input();

	cout << "PS1: ";
	cout << f1;
	cout << "PS2: ";
	cout << f2;
	cout << "PS3: ";
	cout << f3;

	Fraction ps;
	cout << "Phep gan: ";
	ps = f2;
	cout << ps;

	f = f1 + f2;
	cout << "+: " << f;
	f = f2 - f3;
	cout << "- :" << f;
	f = f3 * f1;
	cout << "*: " << f;
	f = f1 / f2;
	cout << "/: " << f;

	cout << "==" << endl;
	cout << (f2 == f3) << endl;
	cout << "!=" << endl;
	cout << (f3 != f1) << endl;
	cout << ">=" << endl;
	cout << (f2 >= f3) << endl;
	cout << ">" << endl;
	cout << (f2 > f1) << endl;
	cout << "<=" << endl;
	cout << (f1 <= f3) << endl;
	cout << "<" << endl;
	cout << (f2 < f3) << endl;

	f = f2 + 3;
	cout << f;
	f = -7 + f2;
	cout << f;
	f = 7 * f2;
	cout << f;
	f = f2 - 6;
	cout << f;

	f1 += f2;
	cout << "+=: " << f1;
	f1 -= f2;
	cout << "-=: " << f1;
	f1 *= f2;
	cout << "*=: " << f1;
	f1 /= f2;
	cout << "/=: " << f1;

	cout << "++X: ";
	cout << ++f1;
	cout << "X++: ";
	cout << f1++;

	cout << "--X: ";
	cout << --f2;
	cout << "X--: ";
	cout << f2--;

	float fl = (float)f2;
	cout << "Float:" << fl;

	return 0;
}