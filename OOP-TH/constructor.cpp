#include <iostream>

using namespace std;
class Base {
public:
    Base() = default;
    ~Base() = default;
    virtual void print() {
        cout << "Base" << endl;
    }
};

class Derived : public Base {
public:
    Derived(const string &name) : name(name) {}
    ~Derived() = default;
    void print() override {
        cout << name << endl;
    }
private:
    string name;
};
int main()
{
    Base *base = new Derived("Lam");
    base->print(); // Lam
    return 0;
}
