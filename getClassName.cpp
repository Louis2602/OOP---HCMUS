#include <iostream>
#include <typeinfo>
using namespace std;

class A
{
public:
  string className()
  {
    string s = typeid(*this).name();
    int i;
    for (i = 0; i < s.length(); ++i)
    {
      if (s[i] < '0' || s[i] > '9')
        break;
    }
    return s.substr(i);
  }
};
int main(int argc, char *argv[])
{
  A a;
  cout << a.className();
  return 0;
}