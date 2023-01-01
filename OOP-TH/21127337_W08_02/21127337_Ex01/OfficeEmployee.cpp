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
    int n;
    cout << "Enter number of workers below you: ";
    cin >> n;
    downEmp.resize(n);
    int type;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter type of worker: ";
        cin >> type;
        if (type == 0)
        {
            downEmp[i] = new Worker;
        }
        downEmp[i]->Input();
    }
}
void OfficeEmployee::Output()
{
    Employee::Output();
    cout << "Number of working days: " << noWorkDays << endl;
    cout << "Workers below: " << endl;
    for (int i = 0; i < downEmp.size(); i++)
        downEmp[i]->Output();
}
double OfficeEmployee::Salary() const
{
    return payRate * noWorkDays;
}