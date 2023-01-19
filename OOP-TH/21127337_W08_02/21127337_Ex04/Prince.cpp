#include "Prince.h"

void Prince::nhap()
{
    cout << "Thong tin cua hoang tu\n";
    cout << "Nhap so tien: ";
    cin >> tien;
    cout << "Nhap tri tue: ";
    cin >> tritue;
    cout << "Nhap suc manh: ";
    cin >> sucmanh;
}
void Prince::xuat()
{
    cout << "Thong tin cua hoang tu\n";
    cout << "So tien: " << tien << endl;
    cout << "Tri tue: " << tritue << endl;
    cout << "Suc manh: " << sucmanh << endl;
}
int Prince::getTien()
{
    return tien;
}
int Prince::getTriTue()
{
    return tritue;
}
int Prince::getSucManh()
{
    return sucmanh;
}
void Prince::setTien(int tien)
{
    this->tien = tien;
}
void Prince::setSucManh(int sucmanh)
{
    this->sucmanh = sucmanh;
}