#include "Employee.h"
#include "OfficeEmployee.h"
#include "Worker.h"
#include <iostream>
#include <vector>

class Company
{
    vector<Employee *> employees;

public:
    void Input();
    void employeeInfo();
    double totalSalary();
    vector<Employee *> highestSalary();
};