#pragma once

#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class NgayThang
{
private:
    int ngay, thang, nam;
    int dayInMonth = 30;
    int monthInYear = 12;
    static vector<NgayThang *> list;

public:
    NgayThang();
    NgayThang(int, int, int);
    NgayThang(int);
    static NgayThang *add(NgayThang *);

    void setDate(int, int, int);
    void splitDate(int);

    void output();

    NgayThang operator+(const NgayThang &);
    // NgayThang operator-(const NgayThang &);

    NgayThang operator+(int);
    // NgayThang operator-(int);

    friend NgayThang operator+(int, const NgayThang &);
    // NgayThang friend operator-(int, const NgayThang &);

    NgayThang &operator++();
    NgayThang operator++(int);

    // NgayThang &operator--();
    // NgayThang operator--(int);
    static NgayThang *NgayThangLonNhat();

    int maxAppropriateDays();

    friend ostream &operator<<(ostream &, NgayThang &);
};