#include <iostream>
#include <vector>
using namespace std;

class NhanVien
{
public:
    virtual string className() = 0;
    virtual int size()
    {
        return 0;
    }
};

class LTV : public NhanVien
{
public:
    string className()
    {
        return "LTV";
    }
};

class Tester : public NhanVien
{
public:
    string className()
    {
        return "Tester";
    }
};

class Manager : public NhanVien
{
    vector<NhanVien *> subList;

public:
    Manager(vector<NhanVien *> _list)
    {
        subList = _list;
    }
    string className()
    {
        return "Manager";
    }
    int size()
    {
        int cnt = 0;
        for (int i = 0; i < subList.size(); i++)
        {
            cnt++;
            if (subList[i]->className() == "Manager")
                cnt += subList[i]->size();
        }
        return cnt;
    }
};

class CongTy
{
    vector<NhanVien *> list;

public:
    CongTy(vector<NhanVien *> _list)
    {
        list = _list;
    };
    int size()
    {
        return list.size();
    }
    void count()
    {
        int cnt = 0;
        for (NhanVien *&x : list)
        {
            cnt = 0;
            if (x->className() == "Manager")
            {
                cnt += x->size();
                cout << x->className() << ": " << cnt << endl;
            }
        }
    }
};

int main()
{
    vector<NhanVien *> list;
    LTV *a = new LTV;
    LTV *a1 = new LTV;
    LTV *a2 = new LTV;
    Tester *b = new Tester;
    Tester *b1 = new Tester;
    vector<NhanVien *> list1;
    list1.push_back(a);
    list1.push_back(a1);
    list1.push_back(b);
    Manager *c = new Manager(list1);
    vector<NhanVien *> list2;
    list2.push_back(a);
    list2.push_back(a2);
    list2.push_back(b1);
    list2.push_back(c);
    Manager *c1 = new Manager(list2);

    list.push_back(a);
    list.push_back(a1);
    list.push_back(b);
    list.push_back(a2);
    list.push_back(b1);
    list.push_back(c);
    list.push_back(c1);

    CongTy comp(list);
    cout << "Company list: " << comp.size() << endl;
    comp.count();
    return 0;
}