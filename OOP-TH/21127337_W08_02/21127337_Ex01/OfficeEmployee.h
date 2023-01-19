#pragma once

#include "Employee.h"
#include "Worker.h"

class OfficeEmployee : public Employee
{
private:
    int noWorkDays;
    double payRate = 300000;
    vector<Employee *> downEmp;

public:
    OfficeEmployee() : Employee(){};
    OfficeEmployee(int id, int noWorkDays);
    OfficeEmployee(int id, string name, int noWorkDays);
    OfficeEmployee(int id, string name, string address, int noWorkDays);
    OfficeEmployee(int id, string name, string address, string hireDate, int noWorkDays);
    virtual ~OfficeEmployee(){};
    void Input();
    void Output();
    double Salary() const;
};