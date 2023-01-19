#include "PowerGate.h"

void PowerGate::nhap()
{
    cout << "Nhap thong tin cong Power Gate\n";
    cout << "Nhap suc manh: ";
    cin >> sucmanh;
}

bool PowerGate::quaCong(Prince &ht)
{
    if (ht.getSucManh() >= sucmanh)
    {
        ht.setSucManh(ht.getSucManh() - sucmanh);
        return true;
    }
    return false;
}