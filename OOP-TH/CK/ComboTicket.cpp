#include "ComboTicket.h"

void ComboTicket::input()
{
    cout << "Combo Ticket Input:\n";
    Ticket::input();
}
void ComboTicket::output()
{
    Ticket::output();
    cout << "Ticket factor: " << ticketFactor << endl;
}