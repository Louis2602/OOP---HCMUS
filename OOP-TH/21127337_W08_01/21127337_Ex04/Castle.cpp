#include "Castle.h"

void Castle::nhapDS()
{
    int noGates;
    cout << "Nhap so luong cong: ";
    cin >> noGates;
    cout << "Nhap thong tin tung cong\n";
    Gate *g;
    int type;
    for (int i = 0; i < noGates; i++)
    {
        cout << "Nhap loai cong (1: BG, 2: PG, 3: AG): ";
        cin >> type;
        if (type == 1)
            g = new BusinessGate;
        else if (type == 2)
            g = new PowerGate;
        else if (type == 3)
            g = new AcademicGate;
        g->nhap();
        a.push_back(g);
    }
}
bool Castle::cuuCongChua(Prince &ht)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (!a[i]->quaCong(ht))
            return false;
    }
    return true;
}