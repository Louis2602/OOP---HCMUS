#pragma once
#ifndef AcademicGate_h
#define AcademicGate_h
#include "Gate.h"

class AcademicGate : public Gate
{
    int tritue;

public:
    void nhap();
    bool quaCong(Prince &ht);
};
#endif