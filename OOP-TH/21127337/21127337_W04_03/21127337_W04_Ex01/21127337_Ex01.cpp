#include "Fraction.h"

using namespace std;

int main()
{
    Fraction a(-3, 5), b("12/5"), c;
    cout << "PS a: ";
    a.Output();
    cout << "PS b: ";
    b.Output();
    c.Input();
    cout << "PS c: ";
    c.Output();

    Fraction fractionFromFile;
    fractionFromFile.LoadFraction("load.txt");
    fractionFromFile.Output();

    a.SaveFraction("save.txt");
    cout << "Compare a & b: " << a.Compare(b) << endl;
    cout << "Negative ? " << a.isNegative() << endl;
    cout << "Positive ? " << a.isPositive() << endl;
    cout << "Zero ? " << a.isZero() << endl;

    Fraction d;
    FractionArray vF1(d);
    vF1.Output();

    FractionArray vF2("1/2 3/4 3/11");
    vF2.Output();

    vector<Fraction> arrF = {a, b, c};
    FractionArray vF3(arrF);
    vF3.Output();

    FractionArray vF4;
    vF4.Input();
    vF4.Output();

    FractionArray vF5;
    vF5.LoadArrFractions("load.txt");
    vF5.Output();
    vF5.SaveArrFractions("save.txt");

    Fraction sum;
    sum = vF5.SumAllFractions();
    cout << "Sum of all fractions: ";
    sum.Output();
    return 0;
}