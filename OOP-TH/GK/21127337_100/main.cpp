#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class People
{
private:
    string name;
    int score;

public:
    People(string name, int score)
    {
        this->name = name;
        this->score = score;
    }
    string getName()
    {
        return name;
    }
    int getScore()
    {
        return score;
    }
    ~People();
};
bool decrease(People *x, People *y)
{
    return (x->getScore() > y->getScore());
}
void Swap(People *x, People *y)
{
    People *tmp = x;
    x = y;
    y = tmp;
}
int main()
{
    vector<People *> p;
    p.push_back(new People("A", 40));
    p.push_back(new People("C", 30));
    p.push_back(new People("B", 30));
    p.push_back(new People("D", 20));
    p.push_back(new People("G", 50));
    p.push_back(new People("F", 60));
    p.push_back(new People("A", 60));
    p.push_back(new People("E", 50));
    p.push_back(new People("C", 50));
    sort(p.begin(), p.end(), decrease);
    // Xep giam dan theo score, neu score bang nhau thi xep tang dan theo name
    for (int i = 0; i < p.size() - 1; i++)
        for (int j = i; j < p.size(); j++)
            if ((p[i]->getScore() == p[j]->getScore()) && (p[i]->getName() > p[j]->getName()))
                Swap(p[i], p[j]);
    for (int i = 0; i < p.size(); i++)
        cout << p[i]->getName() << ": " << p[i]->getScore() << endl;
    return 0;
}