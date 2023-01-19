#pragma once
#include <iostream>

using namespace std;

class IntArray
{
    int *arr;
    int size;

public:
    void Input();
    int *getArr();
    void setArr(int *);
    int getSize();
    void setSize(int);

    IntArray &operator=(const IntArray&);

    friend ostream &operator<<(ostream &, const IntArray &);
    friend istream &operator>>(istream &, IntArray &);

    int &operator[](int);

    operator int() const;
};
