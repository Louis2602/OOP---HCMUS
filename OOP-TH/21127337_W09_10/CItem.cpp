#include "CItem.h"

CItem::CItem(string name)
{
    this->name = name;
}
string CItem::getName()
{
    return name;
}
CItem *CItem::findByName(string item)
{
    return nullptr;
}
CItem *CItem::removeByName(string item)
{
    return nullptr;
}
void CItem::setHidden(bool isHidden, bool isAlsoApplyToChildren)
{
    this->isHidden = isHidden;
    this->isAlsoApplyToChildren = isAlsoApplyToChildren;
}
CItem::~CItem()
{
}