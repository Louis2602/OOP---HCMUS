#include "mystring.h"

istream &operator>>(istream &in, MyString &s)
{
	char *temp = new char[256];
	int count = 0;
	in.getline(temp, 256);
	while (temp[count] != '\0')
		count++;
	temp[count] = '\0';
	s.setLength(count);
	s.setStr(temp);
	delete[] temp;
	return in;
}

ostream &operator<<(ostream &out, MyString &s)
{
	char *tmp = s.getStr();
	for (int i = 0; i < s.getLength(); i++)
	{
		out << tmp[i];
	}
	cout << endl;
	return out;
}

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
	cout << "Enter start, length to get substr: ";
	cin >> start >> len;
	char *ans = s1.subString(start, len);
	cout << ans << '\n';

	cout << "Add 2 string:\n";
	cout << "S1 + S2 = " << s1 + s2 << '\n';
	return 0;
}