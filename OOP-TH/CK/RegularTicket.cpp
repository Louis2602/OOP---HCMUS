#include "RegularTicket.h"

void RegularTicket::input()
{
    cout << "Regular Ticket Input:\n";
    Ticket::input();
}
void RegularTicket::output()
{
    Ticket::output();
    cout << "Ticket factor: " << ticketFactor << endl;
}