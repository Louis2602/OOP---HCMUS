#include "Ticket.h"

void Ticket::input()
{
    cout << "Enter Film title: ";
    cin >> filmTitle;
    cout << "Enter Start time: ";
    cin >> startTime;
    cout << "Enter Room name: ";
    cin >> roomName;
    cout << "Enter Price of food and drink: ";
    cin >> price;
}
void Ticket::output()
{
    cout << "======INFOMARTION=======" << endl;
    cout << "Film title: " << filmTitle << endl;
    cout << "Start time: " << startTime << endl;
    cout << "Room name: " << roomName << endl;
    cout << "Price of food and drink: " << price << endl;
    cout << "Ticket factor: " << ticketFactor << endl;
}