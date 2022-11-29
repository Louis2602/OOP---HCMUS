#include "NgayThang.h"

NgayThang::NgayThang()
{
    ngay = thang = nam = 1;
}

void NgayThang::splitDate(int totalDays)
{
    NgayThang t;
    int totalMonths = totalDays / dayInMonth;
    int day = t.ngay + totalDays % dayInMonth;
    int year = totalMonths / monthInYear;
    if (nam > 1)
        // year = t.nam + nam + totalMonths / monthInYear;
        year = year + t.nam + nam;
    else
        // year = t.nam + totalMonths / monthInYear;
        year += t.nam;
    int month = t.thang + totalMonths % monthInYear;
    setDate(day, month, year);
}
NgayThang::NgayThang(int totalDays)
{
    NgayThang tmp;
    tmp.splitDate(totalDays);
    *this = tmp;
}
NgayThang::NgayThang(int year, int month, int day)
{
    year = abs(year) - 1;
    month = abs(month) - 1;
    day = abs(day) - 1;
    setDate(day, month, year);
    int totalDays = month * dayInMonth + day;
    splitDate(totalDays);
}
ostream &operator<<(ostream &out, NgayThang &date)
{
    out << date.ngay << "/" << date.thang << "/" << date.nam;
    return out;
}
void NgayThang::output()
{
    stringstream stream;
    if (ngay < 10)
        stream << "0";
    stream << ngay << "/";
    if (thang < 10)
        stream << "0";
    stream << thang << "/" << nam;
    cout << stream.str() << endl;
}
void NgayThang::setDate(int day, int month, int year)
{
    ngay = day;
    thang = month;
    nam = year;
}
NgayThang NgayThang::operator+(const NgayThang &t)
{
    NgayThang tmp = *this;
    NgayThang ans;
    int day = tmp.ngay + t.ngay - 1;
    int month = tmp.thang + t.thang - 1;
    int year = tmp.nam + t.nam - 1;
    int totalDays = month * dayInMonth + day;
    ans.setDate(day, month, year);
    ans.splitDate(totalDays);
    return ans;
}
NgayThang NgayThang::operator+(int days)
{
    NgayThang tmp = *this;
    int day = tmp.ngay + days - 1;
    int month = tmp.thang - 1;
    int year = tmp.nam - 1;
    tmp.setDate(day, month, year);
    int totalDays = month * dayInMonth + day;
    tmp.splitDate(totalDays);
    return tmp;
}

NgayThang operator+(int days, const NgayThang &t)
{
    NgayThang tmp = t;
    NgayThang ans = tmp + days;
    return ans;
}
NgayThang &NgayThang::operator++()
{
    ngay++;
    int day = ngay - 1;
    int month = thang - 1;
    int year = nam - 1;
    setDate(day, month, year);
    int totalDays = month * dayInMonth + day;
    splitDate(totalDays);
    return *this;
}
NgayThang NgayThang::operator++(int)
{
    NgayThang tmp = *this;
    ++*this;
    return tmp;
}
vector<NgayThang *> NgayThang::list;
NgayThang *NgayThang::add(NgayThang *t)
{
    if (t == nullptr)
        return nullptr;
    list.push_back(t);
    return t;
}
NgayThang *NgayThang::NgayThangLonNhat()
{
    int totalDays = 0;
    int comp;
    int max = list[0]->ngay + list[0]->thang * 30 + list[0]->nam;
    int index;
    for (int i = 1; i < list.size(); i++)
    {
        // cout << "nt" << i + 1 << ": " << *list[i] << endl;
        totalDays = list[i]->ngay + list[i]->thang * 30;
        comp = totalDays + list[i]->nam;
        if (max < comp)
        {
            max = comp;
            index = i;
        }
    }
    return list[index];
}

int NgayThang::maxAppropriateDays()
{
    int daymax;
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        daymax = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        daymax = 30;
        break;
    case 2:
        daymax = 28 + ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0));
        break;
    }
    return daymax;
}