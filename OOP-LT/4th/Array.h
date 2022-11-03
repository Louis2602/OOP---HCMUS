#pragma once
#include <iostream>

using namespace std;

class Array
{
    int size;
    int *arr;

public:
    Array();
    Array(int);
    Array(int[], int);
    // Array() : Array(){};
    ~Array();

    int *getArr();
    void setArr(int *);
    int getSize();
    void setSize(int);

    Array &operator=(Array);

    friend ostream &operator<<(ostream &, Array &);
    friend istream &operator>>(istream &, Array &);

    int &operator[](int);

    operator int *() const;
};