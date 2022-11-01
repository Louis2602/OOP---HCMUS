#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class Date
{
    int day, month, year, hour, minute, second;
    string DayInWeek[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

public:
    void Input();
    Date Tomorrow();
    Date Yesterday();

    Date operator+(int);
    Date operator-(int);
    Date operator*(int);
    Date operator/(int);
    Date operator=(Date);

    bool operator==(Date);
    bool operator!=(Date);
    bool operator>(Date);
    bool operator>=(Date);
    bool operator<(Date);
    bool operator<=(Date);

    Date operator+=(Date);
    Date operator-=(Date);
    Date operator*=(Date);
    Date operator/=(Date);

    Date &operator++();
    Date &operator++(int);
    Date &operator--();
    Date &operator--(int);

    operator int() const;
    operator long() const;
    friend ostream &operator<<(ostream &, Date &);
    friend istream &operator>>(istream &, Date &);
};