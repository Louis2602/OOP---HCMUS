#include "BusinessGate.h"

void BusinessGate::nhap()
{
    cout << "Nhap thong tin cong Business Gate\n";
    cout << "Nhap don gia: ";
    cin >> dongia;
    cout << "Nhap so luong: ";
    cin >> soluong;
}
bool BusinessGate::quaCong(Prince &ht)
{
    if (soluong * dongia <= ht.getTien())
    {
        ht.setTien(ht.getTien() - soluong * dongia);
        return true;
    }
    return false;
}