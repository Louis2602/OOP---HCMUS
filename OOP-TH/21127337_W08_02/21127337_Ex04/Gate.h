#pragma once
#ifndef Gate_h
#define Gate_h

#include "Prince.h"

using namespace std;

class Gate
{
public:
    virtual void nhap() = 0;
    virtual bool quaCong(Prince &ht) = 0;
};

#endif