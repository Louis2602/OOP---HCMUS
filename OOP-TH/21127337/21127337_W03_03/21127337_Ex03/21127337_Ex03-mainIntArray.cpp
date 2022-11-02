#include "IntArray.h"

int main()
{
	// // Using dynamic allocated array
	IntArray m1;
	IntArray m2;

	IntArray m3;
	// IntArray m4;
	// IntArray m5;

	m1.Input();
	// m2.Input();
	// m3.Input();
	// m4.Input();
	// m5.Input();

	cout << "Arr 1: ";
	cout << m1;

	cin >> m2;
	cout << "Arr 2: ";
	cout << m2;

	m3 = m2;
	cout << "Arr 3: ";
	cout << m3;

	cout << m2[3] << endl;
	m2[4] = 1;
	cout << m2;

	cout << "Size of arr: " << (int)m2 << endl; // return the size of array

	return 0;
}