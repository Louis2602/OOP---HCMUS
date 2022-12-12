#ifndef CItem_h
#define CItem_h

#include <string>
#include <iostream>

using namespace std;

class CItem
{
protected:
    string name;
    bool isHidden;
    bool isAlsoApplyToChildren;

public:
    CItem(string name);

    string getName();

    virtual int getSize() const = 0;
    virtual void print(bool) const = 0;
    virtual CItem *findByName(string);
    virtual CItem *removeByName(string);
    virtual void setHidden(bool, bool);
    virtual ~CItem();
};
#endif