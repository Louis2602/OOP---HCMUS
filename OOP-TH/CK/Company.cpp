#include "Company.h"

void Company::input()
{
    int n;
    cout << "Enter number of tickets: ";
    cin >> n;
    Ticket *t;
    int type;
    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            cout << "Enter type of ticket (1: regular, 2: combo): ";
            cin >> type;
            if (type == 1)
            {
                t = new RegularTicket;
                break;
            }
            else if (type == 2)
            {
                t = new ComboTicket;
                break;
            }
        }
        t->input();
        list.push_back(t);
    }
}
bool compare(Ticket *i1, Ticket *i2)
{
    return (i1->getTF() < i2->getTF());
}
void Company::sortInfo()
{
    sort(list.begin(), list.end(), compare);
    int start;
    int end = 0;
    for (int i = 0; i < list.size(); i++)
        for (int j = i; j < list.size(); j++)
            if ((list[i]->getPrice() > list[j]->getPrice()) && (list[i]->getTF() == list[j]->getTF()))
                swap(list[i], list[j]);
}
void Company::save(string filename)
{
    fstream fs(filename, ios::out);
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i]->getTF() == 1.0)
        {
            fs << "Regular ticket: " << endl;
            fs << list[i]->getTitle() << ", " << list[i]->getPrice() << ", " << list[i]->getRoom() << ", " << list[i]->getTime() << endl;
        }
    }
    fs.close();
}
void Company::ticketInfo()
{
    for (int i = 0; i < list.size(); i++)
        list[i]->output();
}
bool compareTime(Ticket *a, Ticket *b)
{
    return a->getTime() < b->getTime();
}
void Company::summarize()
{
    int cnt = 0;
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i]->getTF() == 1.5)
            cnt++;
    }
    sort(list.begin(), list.end(), compareTime);
    for (int i = 0; i < list.size(); i++)
    {
        cout << "Range: " << i << ": " << cnt << endl;
    }
}