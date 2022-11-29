#include "OfficeEmployee.h"

OfficeEmployee::OfficeEmployee(int id, string name, string address, string hireDate, int _noWorkDays, double _payRate) : Employee(id, name, address, hireDate)
{
    noWorkDays = _noWorkDays;
    payRate = _payRate;
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
    cout << "Pay rate per day: " << payRate << endl;
}
double OfficeEmployee::Salary()
{
    return payRate * noWorkDays;
}