#include "Ticket.h"

class RegularTicket : public Ticket
{
private:
    float ticketFactor = 1.5;

public:
    RegularTicket() : Ticket() {}
    void input();
    void output();
};