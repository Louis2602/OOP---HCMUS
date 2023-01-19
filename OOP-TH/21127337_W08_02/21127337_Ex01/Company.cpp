#include "Company.h"

void Company::Input()
{
    int noOE, noW, num;
    cout << "Enter number of Employees: ";
    cin >> num;
    Employee *e = nullptr;
    int type;
    for (int i = 0; i < num; i++)
    {
        while (true)
        {
            cout << "Enter type of employee (1: Office, 2: Worker): ";
            cin >> type;
            if (type == 1)
            {
                e = new OfficeEmployee;
                break;
            }
            else if (type == 2)
            {
                e = new Worker;
                break;
            }
        }
        e->Input();
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
bool compare(Employee *a, Employee *b)
{
    return a->Salary() < b->Salary();
}

void Company::highestSalary()
{
    // int maxSalary = employees[0]->Salary();
    // for (int i = 1; i < employees.size(); i++)
    //     if (maxSalary < employees[i]->Salary())
    //         maxSalary = employees[i]->Salary();
    Employee *e = *max_element(employees.begin(), employees.end(), compare);
    cout << "Employees with highest salary: \n";
    for (int i = 0; i < employees.size(); i++)
        if (employees[i]->Salary() == e->Salary())
            employees[i]->Output();
}