#include "Castle.h"
using namespace std;

int main()
{
    Prince ht;
    Castle c;
    c.nhapDS();
    ht.nhap();
    if (c.cuuCongChua(ht))
        ht.xuat();
    else
        cout << "He died. Haha" << endl;
    return 0;
}