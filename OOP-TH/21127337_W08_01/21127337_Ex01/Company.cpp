#include "Company.h"

void Company::Input()
{
    int noOE, noW;
    cout << "Enter number of office employees: ";
    cin >> noOE;
    OfficeEmployee *oe = new OfficeEmployee[noOE];
    Employee *e;
    for (int i = 0; i < noOE; i++)
    {
        oe[i].Input();
        e = &oe[i];
        employees.push_back(e);
    }
    cout << "Enter number of workers: ";
    cin >> noW;
    Worker *w = new Worker[noW];
    for (int i = 0; i < noW; i++)
    {
        w[i].Input();
        e = &w[i];
        employees.push_back(e);
    }
}
void Company::employeeInfo()
{
    for (int i = 0; i < employees.size(); i++)
        employees[i]->Output();
}
void Company::totalSalary()
{
    double sum;
    for (int i = 0; i < employees.size(); i++)
        sum += employees[i]->Salary();
    cout << "Total salary: " << sum << endl;
}
void Company::highestSalary()
{
    vector<Employee *> eList;
    int maxSalary = employees[0]->Salary();
    for (int i = 1; i < employees.size(); i++)
        if (maxSalary < employees[i]->Salary())
            maxSalary = employees[i]->Salary();
    cout << "Employees with highest salary: \n";
    for (int i = 0; i < employees.size(); i++)
        if (employees[i]->Salary() == maxSalary)
            employees[i]->Output();
}