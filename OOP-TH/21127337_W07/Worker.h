#pragma once
#include "Employee.h"

class Worker : public Employee
{
private:
    int noItems;
    double payRate;

public:
    Worker() : Employee(){};
    Worker(int id, string name, string address, string hireDate, int _noItems, double _payRate);
    void Input();
    void Output();
    double Salary();
};