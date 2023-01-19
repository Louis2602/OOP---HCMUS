#pragma once
#include <iostream>
#include <ctime>

using namespace std;

static int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Date
{
    int day, month, year;

public:
    int getDay();
    int getMonth();
    int getYear();

    void setDate(int, int, int);

    void Input();
    Date Tomorrow();
    Date Yesterday();

    Date operator+(int);
    Date operator-(int);
    Date operator=(Date);

    bool operator==(Date);
    bool operator!=(Date);
    bool operator>(Date);
    bool operator>=(Date);
    bool operator<(Date);
    bool operator<=(Date);

    Date operator+=(int);
    Date operator-=(int);

    Date &operator++();
    Date &operator++(int);
    Date &operator--();
    Date &operator--(int);

    operator int() const;
    operator long() const;
    friend ostream &operator<<(ostream &, Date &);
    friend istream &operator>>(istream &, Date &);
};