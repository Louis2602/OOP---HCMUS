#include "OfficeEmployee.h"

OfficeEmployee::OfficeEmployee(int id, int _noWorkDays) : Employee(id)
{
    noWorkDays = _noWorkDays;
}
OfficeEmployee::OfficeEmployee(int id, string name, int _noWorkDays) : Employee(id, name)
{
    noWorkDays = _noWorkDays;
}

OfficeEmployee::OfficeEmployee(int id, string name, string address, int _noWorkDays) : Employee(id, name, address)
{
    noWorkDays = _noWorkDays;
}
OfficeEmployee::OfficeEmployee(int id, string name, string address, string hireDate, int _noWorkDays) : Employee(id, name, address, hireDate)
{
    noWorkDays = _noWorkDays;
}
void OfficeEmployee::Input()
{
    cout << "INPUT OFFICE EMPLOYEE INFORMATION" << endl;
    Employee::Input();
    cout << "Enter your number of working days: ";
    cin >> noWorkDays;
    cout << "Enter your pay rate per day: ";
    cin >> payRate;
}
void OfficeEmployee::Output()
{
    Employee::Output();
    cout << "Number of working days: " << noWorkDays << endl;
}
double OfficeEmployee::Salary()
{
    return payRate * noWorkDays;
}