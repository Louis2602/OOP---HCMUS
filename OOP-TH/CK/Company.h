#include "ComboTicket.h"
#include "RegularTicket.h"
#include <fstream>
#include <vector>
#include <algorithm>

class Company
{
    vector<Ticket *> list;

public:
    void input();
    void ticketInfo();
    void sortInfo();
    void save(string);
    void summarize();
};