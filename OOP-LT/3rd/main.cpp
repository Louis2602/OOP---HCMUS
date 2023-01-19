#include "mystring.h"

int main()
{
	MyString s1, s2;
	cout << "Enter a string 1:\n";
	cin >> s1;
	cout << "Enter a string 2:\n";
	cin >> s2;
	cout << "S1: " << s1 << "S2: " << s2 << '\n';
	cout << "Substring:\n";
	int start, len;
	cout << "Enter start: ";
	cin >> start;
	cout << "Enter len: ";
	cin >> len;
	char *sub = s1.subString(start, len);
	cout << "S1: " << s1 << "S2: " << s2;
	cout << "Substr from " << start << " to " << len << " is: " << sub << endl;

	cout << "Add 2 string:\n";
	cout << "S1: " << s1 << "S2: " << s2;
	cout << "S1 + S2 = " << s1 + s2 << '\n';

	cout << "Find:\n";
	cout << "S1: " << s1 << "S2: " << s2;
	cout << s1.find(s2) << endl;

	char *newStr;
	cout << "Insert:\n";
	// int pos;
	// cout << "Enter pos: ";
	// cin >> pos;
	// cout << "Enter str to insert: ";
	newStr = s1.insert(1, s2.getStr());
	cout << "S1: " << s1 << "S2: " << s2;
	cout << "After insert: " << newStr << endl;

	cout << "Erase:\n";
	cout << "S1: " << s1;
	newStr = s1.erase(2, 5);
	cout << "After erase: " << newStr << endl;

	cout << "Replace:\n";
	cout << "S1: " << s1 << "S2: " << s2;
	newStr = s1.replace(1, 5, s2.getStr());
	cout << "After replace: " << newStr << endl;

	return 0;
}