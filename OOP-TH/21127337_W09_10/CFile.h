#include <iostream>
#include "CItem.h"

using namespace std;

class CFile : public CItem
{
private:
    int size;
    bool readOnly;
    bool hidden;

public:
    CFile(string name, int size) : CItem(name)
    {
        this->size = size;
    }
    int getSize() const;
    void print(bool) const;
    virtual ~CFile();
};