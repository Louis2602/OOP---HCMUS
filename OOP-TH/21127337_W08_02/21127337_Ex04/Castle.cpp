#include "Castle.h"

void Castle::nhapDS()
{
    int noGates;
    cout << "Nhap so luong cong: ";
    cin >> noGates;
    Gate *g;
    int type;
    for (int i = 0; i < noGates; i++)
    {
        while (true)
        {
            cout << "Nhap loai cong (1: BG, 2: PG, 3: AG): ";
            cin >> type;
            if (type == 1)
            {
                g = new BusinessGate;
                break;
            }
            else if (type == 2)
            {
                g = new PowerGate;
                break;
            }
            else if (type == 3)
            {
                g = new AcademicGate;
                break;
            }
        }
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