#include "Employee.h"
#include "OfficeEmployee.h"
#include "Worker.h"
#include <iostream>
#include <vector>
#include <algorithm>

class Company
{
    vector<Employee *> employees;

public:
    void Input();
    void employeeInfo();
    void totalSalary();
    void highestSalary();
};