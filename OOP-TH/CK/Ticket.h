#pragma once
#include <iostream>

using namespace std;

class Ticket
{
protected:
    string filmTitle;
    string startTime;
    string roomName;
    float price;
    float ticketFactor;

public:
    virtual void input() = 0;
    virtual void output() = 0;
    float getTF()
    {
        return ticketFactor;
    }
    float getPrice()
    {
        return price;
    }
    string getTitle()
    {
        return filmTitle;
    }
    string getTime()
    {
        return startTime;
    }
    string getRoom()
    {
        return roomName;
    }
};