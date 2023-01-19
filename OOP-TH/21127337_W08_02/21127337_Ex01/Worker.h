#pragma once
#include "Employee.h"

class Worker : public Employee
{
private:
    int noItems;
    double payRate = 20000;

public:
    Worker() : Employee(){};
    Worker(int id, int noItems);
    Worker(int id, string name, int noItems);
    Worker(int id, string name, string address, int noItems);
    Worker(int id, string name, string address, string hireDate, int noItems);
    virtual ~Worker(){};
    void Input();
    void Output();
    double Salary() const;
};