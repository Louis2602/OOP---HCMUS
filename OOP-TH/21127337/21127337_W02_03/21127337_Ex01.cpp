#include "Fraction.h"

using namespace std;

int main()
{
    Fraction a(3, 5), b("12/5"), c;
    cout << "PS a: ";
    a.Output();
    cout << "PS b: ";
    b.Output();
    // c.Input();
    // cout << "PS c: ";
    // c.Output();

    Fraction fractionFromFile;
    fractionFromFile.LoadFraction("load.txt");
    fractionFromFile.Output();

    a.SaveFraction("save.txt");
    return 0;
}