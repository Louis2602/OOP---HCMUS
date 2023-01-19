#include "CFolder.h"

void CFolder::add(CItem *d)
{
    data.push_back(d);
}
int CFolder::getSize() const
{
    int sum = 0;
    for (int i = 0; i < data.size(); i++)
        sum += data[i]->getSize();
    return sum;
}
void CFolder::print(bool isDisplay) const
{
    if (!this->isHidden && isDisplay)
        cout << name << endl;
    for (int i = 0; i < data.size(); i++)
    {
        if (!this->isAlsoApplyToChildren)
            data[i]->print(isDisplay);
    }
}
CItem *CFolder::removeByName(string item)
{
    CItem *it = nullptr;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i]->getName() == item)
        {
            it = data[i];
            data.erase(data.begin() + i);
            break;
        }
        else
            it = data[i]->removeByName(item);
    }
    return it;
}
CItem *CFolder::findByName(string item)
{
    CItem *it;
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i]->getName() == item)
            it = data[i];
        else
            it = data[i]->findByName(item);
    }
    return it;
}
CFolder::~CFolder()
{
}