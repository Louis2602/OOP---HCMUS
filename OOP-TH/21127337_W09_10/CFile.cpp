#include "CFile.h"

int CFile::getSize() const
{
    return size;
}
void CFile::print(bool isDisplay) const
{
    if (isDisplay)
    {
        cout << name << endl;
        return;
    }
}
CFile::~CFile()
{
}