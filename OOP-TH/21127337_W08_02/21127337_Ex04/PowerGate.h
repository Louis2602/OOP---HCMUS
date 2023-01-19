#pragma once
#ifndef PowerGate_h
#define PowerGate_h
#include "Gate.h"

class PowerGate : public Gate
{
    int sucmanh;

public:
    void nhap();
    bool quaCong(Prince &ht);
};
#endif