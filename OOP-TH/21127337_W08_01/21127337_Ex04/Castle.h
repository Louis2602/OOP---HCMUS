#pragma once

#ifndef Castle_h
#define Castle_h

#include "Gate.h"
#include "BusinessGate.h"
#include "AcademicGate.h"
#include "PowerGate.h"

#include <vector>
#include <iostream>

using namespace std;

class Castle
{
    vector<Gate *> a;

public:
    void nhapDS();
    bool cuuCongChua(Prince &ht);
};
#endif