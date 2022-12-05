#pragma once
#ifndef BusinessGate_h
#define BusinessGate_h
#include "Gate.h"
using namespace std;

class BusinessGate : public Gate
{
    int dongia;
    int soluong;

public:
    void nhap();
    bool quaCong(Prince &ht);
};
#endif