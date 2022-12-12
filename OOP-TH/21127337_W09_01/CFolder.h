#include <vector>
#include "CItem.h"

using namespace std;

class CFolder : public CItem
{
private:
    vector<CItem *> data;

public:
    CFolder(string name) : CItem(name){};
    void add(CItem *);
    int getSize() const;
    void print(bool) const;
    CItem *removeByName(string);
    CItem *findByName(string);
    virtual ~CFolder();
};