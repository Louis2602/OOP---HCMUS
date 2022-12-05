#include "AcademicGate.h"

void AcademicGate::nhap()
{
    cout << "Nhap tri tue: ";
    cin >> tritue;
}

bool AcademicGate::quaCong(Prince &ht)
{
    if (ht.getSucManh() >= tritue)
    {
        return true;
    }
    return false;
}