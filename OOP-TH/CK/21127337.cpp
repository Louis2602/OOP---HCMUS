#include "Company.h"

int main()
{

    Company comp;
    comp.input();
    comp.ticketInfo();
    comp.save("ticket.txt");
    comp.sortInfo();
    comp.summarize();
    return 0;
}