#pragma once

#include "Employee.h"

class OfficeEmployee : public Employee
{
private:
    int noWorkDays;
    double payRate;

public:
    OfficeEmployee() : Employee(){};
    OfficeEmployee(int id, string name, string address, string hireDate, int noWorkDays, double payRate);
    void Input();
    void Output();
    double Salary();
};