#include "Ticket.h"

class ComboTicket : public Ticket
{
    float ticketFactor = 1.5;

public:
    ComboTicket() : Ticket() {}
    void input();
    void output();
};