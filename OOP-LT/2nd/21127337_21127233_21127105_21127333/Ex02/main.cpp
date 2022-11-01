#include "Complex.h"

int main()
{
    Complex z1, z2;
    z1.Input();
    z1.Output();

    z2.Input();
    z2.Output();

    Complex ans;
    cout << "+: ";
    ans = z1 + z2;
    ans.Output();
    cout << "-: ";
    ans = z1 - z2;
    ans.Output();
    cout << "*: ";
    ans = z1 * z2;
    ans.Output();
    cout << "/: ";
    ans = z1 / z2;
    ans.Output();
    cout << "Module z1: " << z1.module() << endl;
    cout << "Module z2: " << z2.module() << endl;
    return 0;
}