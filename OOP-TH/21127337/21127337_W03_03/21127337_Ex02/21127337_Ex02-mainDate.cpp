#include "Date.h"

int main()
{
	Date d1;
	Date d2;
	// Date d3;
	// Date d4;
	// Date d5;
	// Date d6;

	d1.Input();
	d2.Input();
	// d3.Input();
	// d4.Input();
	// d5.Input();
	// d6.Input();
	cout << "Date 1: " << d1;
	cout << "Date 2: " << d2;

	// d6=d3;

	// Date t;
	// cout << "Tomorrow: ";
	// t = d1.Tomorrow();
	// cout << t;
	// cout << "Yesterday: ";
	// t = d2.Yesterday();
	// cout << t;

	// cout << (d1 == d2) << endl;
	// cout << (d1 != d2) << endl;
	// cout << (d1 >= d2) << endl;
	// cout << (d1 <= d2) << endl;
	// cout << (d1 > d2) << endl;
	// cout << (d1 < d2) << endl;

	Date t;
	// t = d2 + 1;
	// cout << t;
	// t = d1 + 10;
	// cout << t;
	// t = d2 - 2;
	// cout << t;
	// d4++;
	// ++d2;
	// d5--;
	// --d6;

	// cout<<d3;
	// cin>>d4;

	cout << (int)d1 << endl; // from the first day of current year

	cout << (long)d2 << endl; // from 1/1/1

	// Date d7;
	// d7+=7;
	// d2-=6;

	return 0;
}