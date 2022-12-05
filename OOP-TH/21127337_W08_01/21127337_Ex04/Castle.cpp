#include "Castle.h"

void Castle::nhapDS()
{
    int noGates;
    cout << "Nhap so luong cong: ";
    cin >> noGates;
    cout << "Nhap thong tin tung cong\n";
    Gate *g;
    for (int i = 0; i < noGates; i++)
    {
        cout << "Thong tin cong Giao Thuong\n";
        BusinessGate *bg = new BusinessGate[noGates];
        bg[i].nhap();
        g = &bg[i];
        a.push_back(g);
        cout << "Thong tin cong Hoc Thuat\n";
        AcademicGate *ag = new AcademicGate[noGates];
        ag[i].nhap();
        g = &ag[i];
        a.push_back(g);
        cout << "Thong tin cong Suc Manh\n";
        PowerGate *pg = new PowerGate[noGates];
        pg[i].nhap();
        g = &pg[i];
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