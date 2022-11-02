#include "Date.h"

istream &operator>>(istream &in, Date &date)
{
    int d, m, y;
    cout << "Input day: ";
    cin >> d;
    cout << "Input month: ";
    cin >> m;
    cout << "Input year: ";
    cin >> y;
    date.setDate(d, m, y);
    return in;
}
ostream &operator<<(ostream &out, Date &date)
{
    out << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << '\n';
    return out;
}

int Date::getDay()
{
    return day;
}
int Date::getMonth()
{
    return month;
}
int Date::getYear()
{
    return year;
}
bool isLeapYear(int _year)
{
    return (_year % 400 == 0) || ((_year % 4 == 0) && (_year % 100 != 0));
}
bool valid_date(int _day, int _month, int _year)
{
    if (_month < 1 || _month > 12)
        return false;
    if (_month == 2 && _day == 29 && isLeapYear(_year))
        return true;
    if (_day < 1 || _day > days[_month - 1])
        return false;
    return true;
}
void Date::setDate(int _day, int _month, int _year)
{
    if (valid_date(_day, _month, _year))
    {
        day = _day;
        month = _month;
        year = _year;
    }
    else
        return;
}

void Date::Input()
{
    int d, m, y;
    cout << "Input day: ";
    cin >> d;
    cout << "Input month: ";
    cin >> m;
    cout << "Input year: ";
    cin >> y;
    this->setDate(d, m, y);
}

Date Date::Tomorrow()
{
    int dayT, monthT, yearT;
    days[1] = 28 + isLeapYear(this->year);

    this->day = (this->day % days[this->month - 1]) + 1;
    if (this->day == 1)
        this->month = (this->month) % 12 + 1;
    this->year = this->year + (this->month == 1 && this->day == 1);
    return *this;
}
Date Date::Yesterday()
{
    int dayP, monthP, yearP;
    days[1] = 28 + isLeapYear(this->year);

    if (this->day == 1)
    {
        if (this->month == 1)
        {
            this->month = 12;
            this->day = (days[this->month - 1]);
            this->year--;
        }
        else
        {
            this->day = (days[this->month - 2]);
            this->month--;
        }
    }
    else
        this->day--;
    return *this;
}
bool Date::operator==(Date x)
{
    return ((this->day == x.getDay()) && (this->month == x.getMonth()) && (this->year == x.getYear()));
}
bool Date::operator!=(Date x)
{
    return !(*this == x);
}
int countLeapYears(Date d)
{
    int years = d.getYear();
    if (d.getMonth() <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}
int getDifference(Date d1, Date d2)
{
    long int n1 = d1.getYear() * 365 + d1.getDay();

    for (int i = 0; i < d1.getMonth() - 1; i++)
        n1 += days[i];
    n1 += countLeapYears(d1);

    long int n2 = d2.getYear() * 365 + d2.getDay();
    for (int i = 0; i < d2.getMonth() - 1; i++)
        n2 += days[i];
    n2 += countLeapYears(d2);
    return (n2 - n1);
}
bool Date::operator>(Date x)
{
    int diff;
    if (this->year > x.getYear())
        return true;
    else
    {
        diff = getDifference(*this, x);
        if (diff > 0)
            return false;
    }
    return true;
}
bool Date::operator>=(Date x)
{
    if (*this > x || *this == x)
        return true;
    return false;
}
bool Date::operator<(Date x)
{
    return !(*this >= x);
}
bool Date::operator<=(Date x)
{
    return !(*this > x);
}
Date Date::operator=(Date x)
{
    this->setDate(x.getDay(), x.getMonth(), x.getYear());
    return *this;
}
Date Date::operator+(int a)
{
    if (this->day + a > days[this->month - 1])
    {
        this->month = this->month + 1;
        if (this->month > 12)
        {
            this->month = 1;
            this->year = this->year + 1;
        }
        this->day = this->day + a - days[this->month - 1];
    }
    else
        this->day = this->day + a;

    return *this;
}
Date Date::operator-(int a)
{
    if (this->day - a < 0)
    {
        this->month = this->month - 1;
        if (this->month < 1)
        {
            this->month = 12;
            this->year = this->year - 1;
        }
        this->day = this->day - a + days[this->month - 1];
    }
    else
        this->day = this->day - a;

    return *this;
}
Date &Date::operator++()
{
    *this = *this + 1;
    return *this;
}
Date &Date::operator++(int)
{
    ++*this;
    return *this;
}
Date &Date::operator--()
{
    *this = *this - 1;
    return *this;
}
Date &Date::operator--(int)
{
    --*this;
    return *this;
}
Date Date::operator+=(int a)
{
    *this = *this + a;
    return *this;
}
Date Date::operator-=(int a)
{
    *this = *this - a;
    return *this;
}
Date::operator int() const
{
    Date firstDate;
    firstDate.setDate(1, 1, this->year);
    return getDifference(firstDate, *this) + 1;
}
Date::operator long() const
{
    Date firstDate;
    firstDate.setDate(1, 1, 1);
    return getDifference(firstDate, *this) + 1;
}