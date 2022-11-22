#pragma once
#include <iostream>

using namespace std;

class MyIntArray
{
    int size;
    int *arr;

public:
    MyIntArray();
    MyIntArray(int);
    MyIntArray(int[], int);
    MyIntArray(const MyIntArray &);
    ~MyIntArray();

    int *getArr();
    // void setArr(int *);
    int getSize();
    // void setSize(int);
    void setContent(int *, int);
    MyIntArray &operator=(const MyIntArray &);

    friend ostream &operator<<(ostream &, const MyIntArray &);
    friend istream &operator>>(istream &, MyIntArray &);

    int &operator[](int);

    operator int *() const;
};