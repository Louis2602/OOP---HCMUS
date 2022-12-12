#include "CFile.h"

int CFile::getSize() const
{
    return size;
}
void CFile::print(bool isDisplay) const
{
    // if (this->hidden_attr)
    // {
    if (isDisplay)
    {
        cout << name << endl;
        return;
    }
    // }
    // cout << this->getName() << endl;
}
CFile::~CFile()
{
}