#include <iostream>
#include <string.h>

using namespace std;
class A
{
private:
    char *m_s;

public:
    A()
    {
        cout << "A constructor 0 params" << endl;
        m_s = strdup("default");
    }
    A(char *s)
    {
        cout << "A constructor 1 params" << endl;
        m_s = s;
    }
    virtual void prepare() { cout << "A "; }
    void display()
    {
        prepare();
        cout << m_s << endl;
    }
    friend istream &operator>>(istream &in, A &a)
    {
        a.m_s = new char[1024];
        in.get(a.m_s, 1024);
        return in;
    }
    friend ostream &operator<<(ostream &out, const A &a)
    {
        out << a.m_s << endl;
        return out;
    }
};
class B : public A
{
public:
    B(char *s) : A(s)
    {
        cout << "B constructor 1 params" << endl;
    }
    B(const B &b)
    {
        cout << "B copy constructor" << endl;
    }
    void prepare() { cout << "B "; }
};
void foo(A *obj1, A obj2)
{
    obj1->display();
    obj2.display();
}
int main()
{
    // B obj1("text");
    // A *obj2 = new B(obj1);
    // foo(&obj1, *obj2);
    A obj;
    cin >> obj;
    cout << obj;
    return 0;
}