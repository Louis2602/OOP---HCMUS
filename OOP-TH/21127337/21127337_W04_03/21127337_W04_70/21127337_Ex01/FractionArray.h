#include "Fraction.h"

class FractionArray : public Fraction
{
    vector<Fraction> vF;
    int num;

public:
    FractionArray();
    FractionArray(int);
    FractionArray(Fraction[], int);
    FractionArray(vector<Fraction>);
    FractionArray(string);
    ~FractionArray(){};
    int getSize();
    vector<Fraction> getVF();
    void setContent(vector<Fraction>, int);
    void Input();
    void Output();
    void LoadArrFractions(string);
    void SaveArrFractions(string);
    Fraction SumAllFractions();
    Fraction maxFraction();
    int countNegative();
    int countPositive();
    int countZero();
};